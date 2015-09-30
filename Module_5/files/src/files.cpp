#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "files.hpp"

// line
void ReadFileToVec(const std::string& fileName, std::vector<std::string>& vec) {
	std::ifstream ifs(fileName);
	
	for(std::string line; std::getline(ifs, line);){
	vec.push_back(line);
	}

	
}
// word
void ReadFileToVec2(const std::string& fileName, std::vector<std::string>& vec) {
	std::ifstream ifs(fileName);
	std::string word;
	while(ifs >> word) {
		vec.push_back(word);

	}
}

int getFileSize(const std::string& fileName) {
	std::ifstream ifs(fileName, std::ios::binary | std::ios::ate);

	return ifs.tellg();
}