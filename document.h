/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <map>

class Document
{
	friend class MotoreDiRicerca;
	
	private:
		std::string name;
		std::map<std::string,int> words;
		
		void LoadWords(const std::string& dir_str);
		
	public:	
		Document(const std::string& dir_str, const std::string& name_);

};

#endif
