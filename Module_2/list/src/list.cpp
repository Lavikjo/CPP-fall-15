#include "list.hpp"
#include <iostream>

std::istream& getLines(std::istream& is, std::list<std::string>& list) {
	std::string line;
	while(std::getline(is, line)) {
		list.push_back(line);
	}
	
    return is;
}

void print(std::list<std::string> const& list) {
	for(auto& it : list) {
		std::cout << it << std::endl;
	}
}

void sortAndUnique(std::list<std::string>& list) {
	// sort list
	list.sort();
	// remove duplicates
	list.unique();
}


