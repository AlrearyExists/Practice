//function finds all files and calls for them searching in them
#include "folderWalk.h"
#include <dirent.h> 
#include <sys/types.h>
#include <iostream>
int folderWalk (std::string path, bool r, po::variables_map vm)	//1 arg - a folder where to search, it's important that "/" was not at the end of path. 2 arg means recourcivity, 3 arg is for file function.
{	
	const char UPDIR[3]="..";//{'.', '.', '\0'};
	const char CURDIR[2]=".";
	DIR *d;
	struct dirent *dir;
	const char *cPath=path.c_str();
	d = opendir(cPath);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{	
			std::cout << path<<std::endl;
			if (dir->d_type==DT_REG);// !!!it's a regular file. d_name contains its name. Call the file func for it.
			if ((true==r)&&(dir->d_type==DT_DIR)&&(strcmp(dir->d_name, UPDIR)!=0)&&(strcmp(dir->d_name, CURDIR)!=0))
			{
				std::string foundFolder=(const char*)dir->d_name;
				folderWalk(path+"/"+foundFolder, true);
			}
      			
		}
   	closedir(d);
	return 0;	
	}
	else 
	{
		std::cout << "No such directory!\n";
		return 1;
	}
}
