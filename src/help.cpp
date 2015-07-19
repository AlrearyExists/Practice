#include <iostream>

void help() {
    std::cout << "Pattern for command: aGREP [Keys] -pPattern Directory\nAs result - list of files, where is the match had been founded\nExample: aGREP -n -p13pi /home/13pi/Dir\n" << std::endl;
    std::cout << "OPTIONS\n--help Output a brief help message.\n-i, —ignorcase Ignore case distinctions in both the PATTERN and the input files.\nIgnore the case of characters, so the search will be performed among uppercase and lowercase letters.\n" << std::endl;
    std::cout << "-n, —name mathing of patterns is seeking in the names of files, but not in content\n Example: aGREP -n file /home\n-r, —recursive Read all files under each directory, recursively\nExample: aGREP -r menu /boot\n" << std::endl;
    std::cout << "--version Print the version number of aGREP" << std::endl;
}
