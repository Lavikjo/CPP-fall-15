#ifndef ELEC_CPP_FILES
#define ELEC_CPP_FILES

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

/* 
 * Write a function to open a file for input and read its contents into a vector of strings, 
 * storing each line as a separate element in the vector.
 */
void ReadFileToVec(const std::string& fileName, std::vector<std::string>& vec);

/* Write another function to open file for input and read its contents into a vector of strings,
 * storing each word in a separate element.
 */
void ReadFileToVec2(const std::string& fileName, std::vector<std::string>& vec);

/* Write a function that gets the size of the file */
int getFileSize(const std::string& fileName); 

#endif
