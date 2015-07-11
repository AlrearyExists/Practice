all: name.cpp	
	gcc -o name name.cpp
install: name
	sudo cp name /usr/bin
