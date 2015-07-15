//function finds all files and calls for them searching in them
#include <string>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
int folderWalk (std::string path, bool r, po::variables_map vm); //1 arg - a folder where to search, it's important that "/" was not at the end of path. 2 arg means recourcivity, 3 arg is for file function.
