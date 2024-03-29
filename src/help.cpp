﻿#include <iostream>

void help() {
    std::cout << "\nPATTERN FOR COMMAND \n\taGREP [Keys] -pPattern Directory\n\t\tExample: aGREP -n -p13pi /home/13pi/Dir\n\t\tResult: /home/13pi/13pi.cpp" << std::endl;
    std::cout << "OPTIONS\n" << std::endl;
	std::cout << "\t-h, --help Output a brief help message.\n" << std::endl;
	std::cout << "\t\tExample: aGREP --help\n" << std::endl;
	std::cout << "\t-i, --ignorcase Ignore case distinctions in both the PATTERN and the\n\t\tinput files. Ignore the case of characters, so the search will\n\t\tbe performed among uppercase and lowercase letters.\n" << std::endl;
	std::cout << "\t\tExample: aGREP -i -pGAME /home/mygames\n" << std::endl;
	std::cout << "\t-n, --name Mathing of patterns is seeking in the names of files, but\n\t\tnot in content.\n" << std::endl;
	std::cout << "\t\tExample: aGREP -n -pfile /home\n" << std::endl;
	std::cout << "\t-r, --recursive Serf files in directories inside the target one.\n" << std::endl;
	std::cout << "\t\tExample: aGREP -r -pGAME /home\n" << std::endl;
	std::cout << "\t-v, --version Print the version number of aGREP.\n" << std::endl;
	std::cout << "\t\tExample: aGREP --version\n" << std::endl;
}
