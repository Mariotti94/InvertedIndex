/*
 * InvertedIndex - Search words inside .txt files in a dir
 * Copyright (C) 2015 Gianfranco Mariotti
*/

#include <dirent.h>
#include <string>
#include <list>

#include "directory.h"
#include "utils.h"

void Directory::GetDirFiles(const std::string& dir_str,const std::string& ext)
{
	DIR *dir;
	struct dirent *ent;
	
	if ((dir = opendir (dir_str.c_str())) != NULL) 
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) 
		{
			if(utils::has_suffix((ent->d_name),ext))
				files_list.push_back(Document(dir_str,ent->d_name));
		}
		closedir (dir);
		error = false;
	} 
	else 
	{
		/* could not open directory */
		error = true;
		error_code = "Dir Cannot Be Opened";
	}
}

Directory::Directory(std::string dir_str_, std::string ext_) 
{
	dir_str = dir_str_;
	ext = ext_;
	GetDirFiles(dir_str,ext);
	if( files_list.empty() && error==false )
	{
		error = true;
		error_code = "No Files";
	}
}


