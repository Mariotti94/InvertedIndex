/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <list>
#include <map>

namespace utils{
	
	bool has_suffix(const std::string &str, const std::string &suffix);
	
	void str_normalize(std::string& str, const std::list<char>& to_change, char change_with);
		
	void str_split(std::list<std::string>& words, std::string& str);
	
	void str_split(std::map<std::string,int >& words, std::string& str);
	
};

#endif
