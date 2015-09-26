/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

#include "motore_ricerca.h"
#include "utils.h"

MotoreDiRicerca::MotoreDiRicerca()
{
	current_dir = NULL;
}
		
MotoreDiRicerca::MotoreDiRicerca(Directory* dir) 
{ 
	current_dir = NULL;
	SetDir(dir);
}


void MotoreDiRicerca::DumpTxt(std::string nome_dump)
{
	std::ofstream ofs;
	ofs.open ("dump/"+nome_dump+".txt", std::ofstream::out);
	
	if(current_dir==NULL)
	{
		ofs<<"Dir Not Set"<<std::endl;
	}
	else if(current_dir->HasError())
	{
		ofs<<current_dir->GetError()<<std::endl;
	}
	else
	{
		std::map<std::string,std::list<std::string> >::const_iterator map_iter = docs_word.begin();
		std::list<std::string>::const_iterator list_iter;
		for (; map_iter != docs_word.end(); map_iter++)
		{
			ofs <<"------------------------"<<std::endl;
			ofs <<map_iter->first <<std::endl<<std::endl;
			ofs <<"Associated Files:"<<std::endl<<std::endl;
			for (list_iter = (map_iter->second).begin() ; list_iter != (map_iter->second).end(); list_iter++)
				ofs <<"-->"<<*list_iter << std::endl;
			ofs<<std::endl<<std::endl;
		}
	}
	ofs.close();
}


void MotoreDiRicerca::Search(const std::string& str)
{
	if(current_dir==NULL)
	{
		std::cout<<"Dir Not Set"<<std::endl;
	}
	else if(current_dir->HasError())
	{
		std::cout<<current_dir->GetError()<<std::endl;
	}
	else
	{
		std::list<std::string> words;
		std::string in=str;
		utils::str_split(words, in);
		
		std::list<std::string> intersection;
		
		std::list<std::string>::const_iterator words_iter =  words.begin();
		std::list<std::string>::iterator intersection_iter;
		
		if(GetList(*words_iter)!=NULL){
			intersection = *(GetList(*words_iter));
			words_iter++;
			std::list<std::string> ext;
			
			for (; words_iter !=  words.end(); words_iter++){
				if(GetList(*words_iter)!=NULL){
					ext = *(GetList(*words_iter));
					intersection_iter=intersection.begin();
					for (; intersection_iter != intersection.end(); intersection_iter++){
						if(std::find(ext.begin(),ext.end(),*intersection_iter)==ext.end()){ 
							intersection_iter=intersection.erase(intersection_iter);
							intersection_iter--;
						}
					}
				}
				else{
					intersection.clear();
					words_iter=words.end();
					words_iter--;
				}	
						
			}
		} 
	 
		if(intersection.empty())
			std::cout<<"No Documents"<<std::endl;
		else{
			std::list<std::string>::const_iterator list_iter;
			for (list_iter = intersection.begin() ; list_iter != intersection.end(); list_iter++)
				std::cout<<*list_iter << std::endl;
		}
	}
}

std::list<std::string>* MotoreDiRicerca::GetList(const std::string& str)
{
	if(current_dir->HasError())
		return NULL;
		
	std::map<std::string,std::list<std::string> >::iterator map_iter = docs_word.find(str);
	if(map_iter != docs_word.end()){
		return &(map_iter->second);
	}
	else
		return NULL;
}

void  MotoreDiRicerca::SetDir(Directory* dir)
{
	if(current_dir!=NULL)
		delete current_dir;
	
	current_dir = dir;
	if(!current_dir->HasError())
	{	
		std::map<std::string,int>::const_iterator map_iter;
		std::list<Document>::const_iterator list_iter = (current_dir->files_list).begin();
		for (; list_iter != (current_dir->files_list).end(); list_iter++)
			for (map_iter = list_iter->words.begin() ; map_iter != list_iter->words.end(); map_iter++)
				docs_word[map_iter->first].push_back(list_iter->name);
	}
};
