#include <regex>
#include <stdio.h>
#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
using namespace boost;
namespace po=boost::program_options;
bool findinfile(std::string filename,po::variables_map vm){
	std::string line;
	std::ifstream openedfile(filename);
	std::string match_key=vm["pattern"].as<std::string>();
	if (vm.count("ignorecase"))
	{
		std::transform(match_key.begin(),match_key.end(),match_key.begin(),::tolower);
		boost::regex match_keyword(match_key);
		if (vm.count("name"))
		{
			std::transform(filename.begin(),filename.end(),filename.begin(),::tolower);
			if (boost::regex_search(filename,match_keyword))
			{
				openedfile.close();
				return true;
			}
			openedfile.close();
			return false;
		}
		else
		{
		while(openedfile)
		{
			std::getline(openedfile, line);
			std::transform(line.begin(),line.end(),line.begin(),::tolower);
			if (boost::regex_search(line,match_keyword))
			{
				openedfile.close();
				return true;
			}

		}
		}
	}
	else 
	{
		boost::regex match_keyword(match_key);
		if (vm.count("name"))
		{
			if (boost::regex_search(filename,match_keyword))
			{
				openedfile.close();
				return true;
			}
			openedfile.close();
			return false;
		}
		else{
		while(openedfile)
		{

			std::getline(openedfile, line);
			if (boost::regex_search(line,match_keyword))
			{
				openedfile.close();
				return true;
			}

		}
		}
	}
	openedfile.close();
	return false;
}