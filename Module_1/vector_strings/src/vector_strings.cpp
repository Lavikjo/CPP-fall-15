#include <iostream>
#include <vector>
#include "vector_strings.hpp"

void adder(std::vector<std::string>& names) {
	std::string name;
	std::cout << "Enter a name:" << std::endl;
	std::cin >> name;
	names.push_back(name);
	std::cout << "Number of names in the vector:" << std::endl << names.size() << std::endl;
}

void remover(std::vector<std::string>& names) {
	std::string last = names.back();
	names.pop_back();
	std::cout << "Removing the last element:" << std::endl << last << std::endl;
}

void printer(std::vector<std::string>& names) {
	for( unsigned int i = 0; i < names.size(); i++) {
		std::cout << names[i] << std::endl;
	}
}

void cmdReader() {

	std::string command; 
	std::vector<std::string> names;

	std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;

	std::cout << "Enter command:" << std::endl;
	// reads command and acts upon it
	std::cin >> command;

	if(command == "ADD") {
		adder(names);

	} else if(command == "REMOVE") {
		remover(names);

	} else if(command == "PRINT") {
		printer(names);

	} else if(command == "QUIT") {
		return;

	} else {
		std::cout << "This shouldn't happen!" << std::endl;
	}
}

