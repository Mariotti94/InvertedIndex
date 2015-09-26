/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#include <algorithm>
#include <sstream>

#include "utils.h"


void utils::str_normalize(std::string& str, const std::list<char>& to_change, char change_with) 
{
	std::list<char>::const_iterator list_iter;
	for (list_iter= to_change.begin(); list_iter != to_change.end(); list_iter++)
  		std::replace( str.begin(), str.end(), *list_iter, change_with);
}


void utils::str_split(std::list<std::string>& words, std::string& str) 
{
	char delimiter = '\0';
	std::list<char> splitters = {',','.','<','>',' ','!','"','#','%','&','\'','(',')',';','=','?','[',']','*','+','-',':','^','_','{','|','}','~','\\','/','\t' };
	str_normalize(str,splitters, delimiter);
	std::istringstream iss(str);
	while(iss)
	{	
		std::string in;
		std::getline(iss, in, delimiter);
		if(in!=""){
			std::transform(in.begin(),in.end(),in.begin(), tolower);
			words.push_back(in);			
		}
	}
}

void utils::str_split(std::map<std::string,int >& words, std::string& str) 
{
	char cutter = '\0';
	std::list<char> splitters = {',','.','<','>',' ','!','"','#','%','&','\'','(',')',';','=','?','[',']','*','+','-',':','^','_','{','|','}','~','\\','/','\t' };
	str_normalize(str,splitters, cutter);
	std::istringstream iss(str);
	while(iss)
	{	
		std::string in;
		std::getline(iss, in, cutter);
		if(in!=""){
			std::transform(in.begin(),in.end(),in.begin(), tolower);
			words[in]++;
		}	
	}
}

bool utils::has_suffix(const std::string &str, const std::string &suffix)
{
	return (str.size()>=suffix.size())&&(str.compare(str.size()-suffix.size(),suffix.size(),suffix)==0);
}

