#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include "../src/bugw.hpp"
#include "../src/softwarew.hpp"
#include "../src/bug.h"
#include "../src/software.h"

TEST(test_wrapper, test_bug_getId) {
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);

    EXPECT_EQ("FTDH145643", b1.getId());
    EXPECT_EQ("KDFT087546", b2.getId());
}

TEST(test_wrapper, test_bug_getDesc) {
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);

    EXPECT_EQ("Failed to start.", b1.getDescription());
    EXPECT_EQ("Problem with reading from file", b2.getDescription());
}

TEST(test_wrapper, test_bug_getPriority) {
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);

    EXPECT_EQ(CRITICAL, b1.getPriority());
    EXPECT_EQ(MINOR, b2.getPriority());
}

TEST(test_wrapper, test_bug_fix) {
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);

    EXPECT_EQ(false, b1.isFixed());
    EXPECT_EQ(false, b2.isFixed());

    b1.fix();
    b2.fix();

    EXPECT_EQ(true, b1.isFixed());
    EXPECT_EQ(true, b2.isFixed());
}

TEST(test_wrapper, test_bug_print) {
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);

    int bak, n;
    fflush(stdout);
    bak = dup(1);
    n = open("out.txt", O_WRONLY);
    dup2(n, 1);
    close(n);
    std::cout << b1;
    b2.fix();
    std::cout << b2;
    fflush(stdout);
    dup2(bak, 1);
    close(bak);
    
    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Id: FTDH145643, Desc: Failed to start., Fixed: No";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Id: KDFT087546, Desc: Problem with reading from file, Fixed: Yes";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_wrapper2, test_bug_print_err) {
    try {
        Bug b1("DFGH134", "Failed to start.", MINOR);
        std::ofstream o;
        o << b1;
    }       
    catch(std::runtime_error const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid output stream, C interface is only defined for std::cout"));
    }
}

TEST(test_wrapper2, test_bug_err) {
    //open file
    std::ifstream in;
    in.open("../src/bugw.cpp");
    if(in.is_open()){
        std::string line;
        int i=0;
        while(1){
            std::getline(in, line);
            if(line.find("The bug_construct function failed")!=std::string::npos){
                i=1;
                break;
            }
        }
        EXPECT_EQ(1, i);
        i=0;

        while(1){
            std::getline(in, line);
            if(line.find("The bug_copy function failed")!=std::string::npos){
                i=1;
                break;
            }
        }
        EXPECT_EQ(1, i); 
    }
}

TEST(test_wrapper3, test_software_getName) {
    Software s1("Test Software", 234);    
    Software s2("Firefox", 322);
    EXPECT_EQ("Test Software", s1.getName());
    EXPECT_EQ("Firefox", s2.getName());
}

TEST(test_wrapper3, test_software_getRevision) {
    Software s1("Test Software", 234);    
    Software s2("Firefox", 322);
    EXPECT_EQ(234, s1.getRevision());
    EXPECT_EQ(322, s2.getRevision());
}

TEST(test_wrapper3, test_software_bugs) {
    Software s1("Test Software", 234);    
    Software s2("Firefox", 322);
    
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);
    Bug b3("SDFGR35634", "Problem with shutdown", MAJOR);

    s1.reportBug(b1);
    s2.reportBug(b2);
    s2.reportBug(b3);

    EXPECT_EQ(1, s1.numberOfBugs());
    EXPECT_EQ(2, s2.numberOfBugs());
}

TEST(test_wrapper3, test_software_print) {
    Software s1("Test Software", 234);    
    Software s2("Firefox", 322);
    
    Bug b1("FTDH145643", "Failed to start.", CRITICAL);
    Bug b2("KDFT087546", "Problem with reading from file", MINOR);
    Bug b3("SDFGR35634", "Problem with shutdown", MAJOR);

    s1.reportBug(b1);
    s2.reportBug(b2);
    s2.reportBug(b3);
    
    s2.fixBug("KDFT087546");

    int bak, n;
    fflush(stdout);
    bak = dup(1);
    n = open("out.txt", O_WRONLY);
    dup2(n, 1);
    close(n);
    std::cout << s1;
    std::cout << s2;
    fflush(stdout);
    dup2(bak, 1);
    close(bak);
    
    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Test Software, revision: 234";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Trivial";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Minor";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Major";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
        
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Critical";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Id: FTDH145643, Desc: Failed to start., Fixed: No";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Blocker";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Bugs in report: 1, Bugs fixed: 0/1";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Firefox, revision: 322";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Trivial";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Minor";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Id: KDFT087546, Desc: Problem with reading from file, Fixed: Yes";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Major";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Id: SDFGR35634, Desc: Problem with shutdown, Fixed: No";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Critical";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Priority: Blocker";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "None";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Bugs in report: 2, Bugs fixed: 1/2";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_wrapper4, test_software_print_err) {
    try {
        Software s1("Test Software", 234);    
        std::ofstream o;
        o << s1;
    }       
    catch(std::runtime_error const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid output stream, C interface is only defined for std::cout"));
    }
    
    try {
        Software s1("Test Software", 234);    
        Bug b("SDFGR35634", "Problem with shutdown", MAJOR);
        s1.fixBug("SDFGR35634");    
    }       
    catch(std::runtime_error const & err) {
        EXPECT_EQ(err.what(),std::string("The software_fix_bug function failed"));
    }
}

TEST(test_wrapper4, test_software_err) {
    //open file
    std::ifstream in;
    in.open("../src/softwarew.cpp");
    if(in.is_open()){
        std::string line;
        int i=0;
        while(1){
            std::getline(in, line);
            if(line.find("The software_construct function failed")!=std::string::npos){
                i=1;
                break;
            }
        }
        EXPECT_EQ(1, i);
        i=0;

        while(1){
            std::getline(in, line);
            if(line.find("The software_copy function failed")!=std::string::npos){
                i=1;
                break;
            }
        }
        EXPECT_EQ(1, i);
        i=0;

        while(1){
            std::getline(in, line);
            if(line.find("The software_report_bug function failed")!=std::string::npos){
                i=1;
                break;
            }
        }
        EXPECT_EQ(1, i); 
    }
}
