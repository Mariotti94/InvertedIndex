/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "document.h"

class Directory
{
	friend class MotoreDiRicerca;
	
	private:
		std::list<Document> files_list;
		std::string dir_str;
		std::string ext;
		
		bool error;
		std::string error_code;

		void GetDirFiles(const std::string& dir_str,const std::string& ext);
	
	public:		
		Directory(std::string dir_str_, std::string ext_) ;
		inline bool HasError() const { return error; } ;
		inline std::string GetError() const { if(error) return error_code; else return "No Error"; };
};

#endif
