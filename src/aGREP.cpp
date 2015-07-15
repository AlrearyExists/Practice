#include <regex>
#include <stdio.h>
#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
using namespace boost;
namespace po=boost::program_options;
#include "findinfile.h"
#include "folderWalk.h"
#include "help.h"
int main(int argc, char const *argv[])
{
	if (argc==1)
	{
		std::cout<<"There is something like Grep"<<std::endl;
		return 0;
	};
	po::options_description desc("General options");
	desc.add_options()
	("help,h", "Show help")
	("version", "Show the version information")
	("recursive,r","Recursive research")
	("name,n","Only name research")
	("ignorecase,i","Non case-sensitive research")
	("pattern,p",po::value<std::string>(),"Pattern string")
	("folder",po::value<std::string>(),"Folder path")
	;
	po::positional_options_description p;
	po::positional_options_description g;

	p.add("folder",-1);
	po::variables_map vm;
	po::store(po::command_line_parser(argc,argv).options(desc).positional(p).run(),vm);

	if (vm.count("help"))
		{
			help();
			return 0;
		};
	if (vm.count("version"))
		{
			std::cout<<"Version of aGREP 1.0.0"<<std::endl;
			return 0;
		};


	po::notify(vm);

	if (!vm.count("folder") || !vm.count("pattern"))
	{
		std::cout<<"Folder and Pattern args are required"<<std::endl;
		return 0;
	};

	folderWalk(vm["folder"].as<std::string>(),vm);
	return 0;
};