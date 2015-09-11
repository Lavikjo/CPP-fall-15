#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/rectangle.hpp"

TEST(test_rectangle, test_1) {
    //create two random numbers
    srand(time(0));
    double a = (rand()) / (RAND_MAX / 100.0);
    double b = (rand()) / (RAND_MAX / 100.0);

    //write numbers to file
    std::string input = std::to_string(a) + " " + std::to_string(b);
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    rectangle();

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Please enter base and height";
    std::string correct = c.str();

    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Area: " << a * b ;
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "Circumference: " << 2 * a + 2 * b ;
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
}

TEST(test_rectangle, test_2) {
    //create two random numbers
//    srand(static_cast<unsigned> (time(NULL)));
    double a = (rand()) / (RAND_MAX / 100.0);
    double b = (rand()) / (RAND_MAX / 100.0);

    //write numbers to file
    std::string input = std::to_string(a) + " " + std::to_string(b);
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    rectangle();

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Please enter base and height";
    std::string correct = c.str();

    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Area: " << a * b ;
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "Circumference: " << 2 * a + 2 * b ;
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
}
