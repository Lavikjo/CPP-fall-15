#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include "../src/files.hpp"

TEST(test_files, test_read_lines) {
    std::vector<std::string> v;
    ReadFileToVec("teapot.ply", v);

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 3000);
    int b = (rand()) / (RAND_MAX / 3000);

    std::ifstream t("teapot.ply");
    std::string line;
    for (int l = 0; std::getline(t, line) && l < a; l++);
    
    EXPECT_EQ(line, v[a]);
 
    std::ifstream t2("teapot.ply");
    for (int l = 0; std::getline(t2, line) && l < b; l++);

    EXPECT_EQ(line, v[b]);
}

TEST(test_files, test_read_lines2) {
    std::vector<std::string> v;
    ReadFileToVec2("teapot.ply", v);

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 3000);
    int b = (rand()) / (RAND_MAX / 3000);

    std::ifstream t("teapot.ply");
    std::string line;
    for (int l = 0; t>>line && l < a; l++);
    
    EXPECT_EQ(line, v[a]);
 
    std::ifstream t2("teapot.ply");
    for (int l = 0; t2>>line && l < b; l++);

    EXPECT_EQ(line, v[b]);
}

TEST(test_files, test_get_size) {
    EXPECT_EQ(63133, getFileSize("teapot.ply"));
    EXPECT_EQ(52842, getFileSize("apple.ply"));
}
