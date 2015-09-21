#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cstddef>
#include "../src/book.hpp"
#include "../src/customer.hpp"

std::string generate_isbn(){
    srand(time(0));
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr1(100, 999); // define the range
    std::uniform_int_distribution<> distr2(100, 999); // define the range
    std::string s = "978-0-"+std::to_string(distr1(eng))+"-"+std::to_string(distr2(eng))+"-2";
    return s;
}

Date get_current_date(){
    Date d;
    std::time_t t = time(0);
    struct tm * now = localtime(&t);
    d.day=now->tm_mday;
    d.month=now->tm_mon+1;
    d.year=now->tm_year+1900;
    return d;
}

TEST(test_book, test_constructor) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, true, Date{1,10,2015});
}

TEST(test_book, test_getName) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");

    EXPECT_EQ("The C++ programming language", b.getName());
    EXPECT_EQ("C++ primer", b2.getName());
}

TEST(test_book, test_getAuthor) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");

    EXPECT_EQ("Stroustrup, Bjarne", b.getAuthor());
    EXPECT_EQ("Lippman, Stanley B.", b2.getAuthor());
}

TEST(test_book, test_getISBN) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);

    EXPECT_EQ("978-0-321-56384-2", b.getISBN());
    EXPECT_EQ("978-0-321-71411-4", b2.getISBN());
    EXPECT_EQ(i, b3.getISBN());
}

TEST(test_book, test_getStatus) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true);

    EXPECT_FALSE(b.getStatus());
    EXPECT_EQ(true, b2.getStatus());
}

TEST(test_book, test_getDueDate) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, Date{1,11,2015});
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, true, Date{1234, 3758568, 23453456});
    EXPECT_EQ("0-0-0", b.getDueDate());
    EXPECT_EQ("1-11-2015", b2.getDueDate());
    EXPECT_EQ("1234-3758568-23453456", b3.getDueDate());
}

TEST(test_book2, test_loan) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);

    b.loan();
    b2.loan();
    b3.loan();
    EXPECT_EQ(true, b.getStatus());
    EXPECT_EQ(true, b2.getStatus());
    EXPECT_EQ(true, b3.getStatus());
    Date d = get_current_date();
    std::string s = std::to_string(d.day)+"-"+std::to_string(d.month+1)+"-"+std::to_string(d.year);
    EXPECT_EQ(s, b.getDueDate());
    EXPECT_EQ(s, b2.getDueDate());
    EXPECT_EQ(s, b3.getDueDate());
}

TEST(test_book2, test_restore) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);

    b.loan();
    b2.loan();
    b3.loan();
    b.restore();
    b2.restore();
    b3.restore();
    EXPECT_FALSE(b.getStatus());
    EXPECT_FALSE(b2.getStatus());
    EXPECT_FALSE(b3.getStatus());
    EXPECT_EQ("0-0-0", b.getDueDate());
    EXPECT_EQ("0-0-0", b2.getDueDate());
    EXPECT_EQ("0-0-0", b3.getDueDate());
}

TEST(test_book2, test_print) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    b.print();
    b2.print();
    b3.print();

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Book: The C++ programming language, author: Stroustrup, Bjarne, ISBN: 978-0-321-56384-2, loaned 0, due date: 0-0-0";
    std::string correct = c.str();

    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Book: C++ primer, author: Lippman, Stanley B., ISBN: 978-0-321-71411-4, loaned 1, due date: " << b2.getDueDate();
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Book: Test book, author: Test author, ISBN: " << b3.getISBN() << ", loaned 0, due date: " << b3.getDueDate();
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
}

TEST(test_customer, test_constructor) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");
}

TEST(test_customer, test_getName) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    EXPECT_EQ("Pertti Kovanen", c.getName());
    EXPECT_EQ("Satu Kivinen", c2.getName());
}

TEST(test_customer, test_getID) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    EXPECT_EQ("45647658657", c.getID());
    EXPECT_EQ("95871034857", c2.getID());
}

TEST(test_customer2, test_loanBook) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    int t = c.loanBook(b);
    EXPECT_EQ(1, t);

    t = c2.loanBook(b);
    EXPECT_EQ(0, t);

    t = c2.loanBook(b2);
    EXPECT_EQ(0, t);
    
    t = c2.loanBook(b3);
    EXPECT_EQ(1, t);
}

TEST(test_customer2, test_getLoanAmount) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    int t = c.loanBook(b);
    EXPECT_EQ(1, t);

    t = c2.loanBook(b);
    EXPECT_EQ(0, t);

    t = c2.loanBook(b2);
    EXPECT_EQ(0, t);
    
    t = c2.loanBook(b3);
    EXPECT_EQ(1, t);

    b2.restore();
    c2.loanBook(b2);

    EXPECT_EQ(1, c.getLoanAmount()); 
    EXPECT_EQ(2, c2.getLoanAmount()); 
}

TEST(test_customer2, test_getLoans) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    int t = c.loanBook(b);
    EXPECT_EQ(1, t);

    t = c2.loanBook(b);
    EXPECT_EQ(0, t);

    t = c2.loanBook(b2);
    EXPECT_EQ(0, t);
    
    t = c2.loanBook(b3);
    EXPECT_EQ(1, t);

    b2.restore();
    c2.loanBook(b2);

    auto c_loans = c.getLoans();
    auto c2_loans = c2.getLoans();
    EXPECT_EQ(1, c_loans.size());
    EXPECT_EQ(2, c2_loans.size());
    EXPECT_EQ("The C++ programming language", c_loans[0].getName());
    EXPECT_EQ("Test book", c2_loans[0].getName());
    EXPECT_EQ("C++ primer", c2_loans[1].getName());
}

TEST(test_customer2, test_returnBook) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    int t = c.loanBook(b);
    EXPECT_EQ(1, t);

    t = c2.loanBook(b);
    EXPECT_EQ(0, t);

    t = c2.loanBook(b2);
    EXPECT_EQ(0, t);
    
    t = c2.loanBook(b3);
    EXPECT_EQ(1, t);

    b2.restore();
    c2.loanBook(b2);

    EXPECT_EQ(1, c.getLoanAmount()); 
    EXPECT_EQ(2, c2.getLoanAmount()); 

    c.returnBook(b);
    EXPECT_EQ(0, c.getLoanAmount());
    EXPECT_EQ(true, c.getLoans().empty());

    c2.returnBook(b3);
    EXPECT_EQ(1, c2.getLoanAmount());
    EXPECT_FALSE(c2.getLoans().empty());
}

TEST(test_customer2, test_print) {
    auto c1 = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");

    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    Date dd = get_current_date();
    dd.month+=1;
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4", true, dd);
    auto i = generate_isbn();
    auto b3 = Book("Test book", "Test author", i, false, dd);

    int t = c1.loanBook(b);
    EXPECT_EQ(1, t);

    t = c2.loanBook(b);
    EXPECT_EQ(0, t);

    t = c2.loanBook(b2);
    EXPECT_EQ(0, t);
    
    t = c2.loanBook(b3);
    EXPECT_EQ(1, t);

    b2.restore();
    c2.loanBook(b2);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    c1.print();
    c2.print();

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Customer: Pertti Kovanen, 45647658657, has 1 books on loan:";
    std::string correct = c.str();
    
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Book: The C++ programming language, author: Stroustrup, Bjarne, ISBN: 978-0-321-56384-2, loaned 1, due date: " << b.getDueDate();
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Customer: Satu Kivinen, 95871034857, has 2 books on loan:";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Book: Test book, author: Test author, ISBN: " << b3.getISBN() << ", loaned 1, due date: " << b3.getDueDate();
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "Book: C++ primer, author: Lippman, Stanley B., ISBN: 978-0-321-71411-4, loaned 1, due date: " << b2.getDueDate();
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
}
