#include <vector>
#include <string>
#include <iostream>
#include "files.hpp"

int main()
{
    std::vector<std::string> vec;
    ReadFileToVec("teapot.ply", vec);
    for (const auto &str : vec)
        std::cout << str << std::endl;                
 
    std::vector<std::string> vec2;
    ReadFileToVec2("teapot.ply", vec2);
    for (const auto &str : vec2)
        std::cout << str << std::endl;                

    int s = getFileSize("teapot.ply");
    std::cout << "Size of teapot.ply was " << s << std::endl;
    
    return 0;
}
