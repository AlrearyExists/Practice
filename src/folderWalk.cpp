//function finds all files and calls for them searching in them
#include <dirent.h> 
#include <sys/types.h>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/regex.hpp>
using namespace boost;
namespace po=boost::program_options;
#include "findinfile.h"
int folderWalk (std::string path, po::variables_map vm)	//1 arg - a folder where to search, it's important that "/" was not at the end of path. 2 arg means recourcivity, 3 arg is for file function.
{	
	const char UPDIR[3]="..";//{'.', '.', '\0'};
	const char CURDIR[2]=".";
	DIR *d;
	struct dirent *dir;
	const char *cPath=path.c_str();
	d = opendir(cPath);
	if (d)
	{
		std::cout << path<<std::endl;
		while ((dir = readdir(d)) != NULL)
		{	
			if (dir->d_type==DT_REG)
			{	
				std::string f_name=(const char*)dir->d_name;
					
				int g=findinfile(f_name,vm);
				if(g<0)
				{
					std::cout<<f_name<<std::endl;					
				}
				else 
				{
					if (g)
						std::cout<<f_name<<std::endl<<"Line number: "<<g<<std::endl;

				}

			}
			if ((vm.count("recursive"))&&(dir->d_type==DT_DIR)&&(strcmp(dir->d_name, UPDIR)!=0)&&(strcmp(dir->d_name, CURDIR)!=0))
			{
				std::string foundFolder=(const char*)dir->d_name;
				folderWalk(path+"/"+foundFolder, vm);
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
