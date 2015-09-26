/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#include <string>
#include <fstream>

#include "document.h"
#include "utils.h"


void Document::LoadWords(const std::string& dir_str)
{
	std::ifstream ifs;
	ifs.open ((dir_str+"/"+name).c_str(), std::ifstream::in);

	if (ifs.is_open())
	{	
		std::string in;
		while(!ifs.eof())
		{
			char cutter = '\n';
			std::getline(ifs, in, cutter);
			utils::str_split(words, in);
		}
	}
	ifs.close();		
}


Document::Document(const std::string& dir_str, const std::string& name_) {  name=name_; LoadWords(dir_str); }


