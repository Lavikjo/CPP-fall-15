#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include "../src/constpr.hpp"

TEST(test_constpr, test_str_print1) {
    std::string s = "This is a test string";

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    str_print(s);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    EXPECT_EQ(s, checkstr);
}

TEST(test_constpr, test_str_print2) {
    //create random string of length 100
    static const char al[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    std::string s;
    for(int i=0; i<=100; i++)
        s.push_back(al[rand()%(sizeof(al)-1)]);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    str_print(s);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    EXPECT_EQ(s, checkstr);
}

TEST(test_constpr, test_str_modifier) {
    //create random string of length 100
    static const char al[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    std::string s;
    for(int i=0; i<100; i++)
        s.push_back(al[rand()%(sizeof(al)-1)]);

    str_modifier(s);

    std::cout << "Testing output" << std::endl;
    std::string c = "This string has been changed.";
    EXPECT_EQ(c, s);
}

TEST(test_constpr, test_vector_add){
    //put 10 random numbers to vector
    std::vector<double> v; 
    srand(time(0));
    for(int i=0; i<10; i++)
        v.push_back(rand() / (RAND_MAX / 100.0));

    vector_add(v);

    EXPECT_EQ(10.0, v[10]);
}

TEST(test_constpr, test_vector_add2){
    //put 10 random numbers to vector
    std::vector<int> v; 
    srand(time(0));
    for(int i=0; i<10; i++)
        v.push_back(rand() / (RAND_MAX / 100));

    vector_add2(&v);

    EXPECT_EQ(9, v[10]);
}

TEST(test_constpr, test_vector_add2_2){
    //put 10 random numbers to vector
    std::vector<int> v; 
    srand(time(0));
    for(int i=0; i<10; i++)
        v.push_back(rand() / (RAND_MAX / 100));

    vector_add2(nullptr);
}

TEST(test_constpr, test_const){
    //open file
    std::ifstream in;
    in.open("../src/constpr.cpp");
    if(in.is_open()){
        std::string line;
        while(1){
            std::getline(in, line);
            if(line.find("str_print(")!=std::string::npos)
                break;
        }
        EXPECT_GT(30, line.find("const"));
        
        while(1){
            std::getline(in, line);
            if(line.find("vector_add2(")!=std::string::npos)
                break;
        }
        EXPECT_GE(40, line.find("const")) << "no const with function that needs it!" ; 
    
    }
}


