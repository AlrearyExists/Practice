all: aGREP.cpp	
	g++ -I $(shell pwd)/boost_1_58_0/ aGREP.cpp findinfile.cpp folderWalk.cpp -o aGREP $(shell pwd)/boost_1_58_0/bin.v2/libs/program_options/build/gcc-4.8/release/link-static/threading-multi/libboost_program_options.a $(shell pwd)/boost_1_58_0/bin.v2/libs/regex/build/gcc-4.8/release/link-static/threading-multi/libboost_regex.a -std=c++11
install: aGREP
	sudo cp aGREP /usr/bin
	rm aGREP