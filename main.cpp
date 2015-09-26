#include<iostream>
#include <string>
#include <list>

#include "document.h"
#include "directory.h"
#include "motore_ricerca.h"

int main()
{
	MotoreDiRicerca mdr;
	std::string word;
	
	mdr.SetDir( new Directory("test_txt_no",".txt") );
	mdr.DumpTxt("dump_not_good");
	std::getline(std::cin,word);
	mdr.Search(word);
	
	mdr.SetDir( new Directory("test_txt",".txt") );
	mdr.DumpTxt("dump_good");
	std::getline(std::cin,word);
	mdr.Search(word);
	
	return 0;
}
