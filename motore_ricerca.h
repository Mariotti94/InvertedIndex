/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#ifndef MDR_H
#define MDR_H

#include "directory.h"

class MotoreDiRicerca
{
	private:
		Directory* current_dir;
		std::map< std::string, std::list<std::string> > docs_word;
		
		std::list<std::string>* GetList(const std::string& str);
		void Clear();
		
	public:	
	    MotoreDiRicerca() ;
		MotoreDiRicerca(Directory* dir) ;
		~MotoreDiRicerca() { delete current_dir; };
		
		void SetDir(Directory* dir);
		void Search(const std::string& str);
		void DumpTxt(std::string nome_dump);
		
};

#endif
