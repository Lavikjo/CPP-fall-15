#include "customer.hpp"
 
#include <ctime>
#include <iostream>
 
Customer::Customer(std::string const &n, std::string const& number) {
    name = n;
    id = number;
}
 
const std::string& Customer::getName() const {
    return name;
}
 
const std::string& Customer::getID() const {
    return id;
}
 
int Customer::getLoanAmount() const {
    return loanAmount;
}
 
bool Customer::loanBook(Book &book) {
    if(book.loan()) {
         
        // add to loanAmount
        loanAmount += 1;
 
        // add loaned book to customer's loans
        loans.push_back(book);
 
        return true;
    } else {
        return false;
    }
}
 
void Customer::returnBook(Book &book) {
     
    loanAmount -= 1;
 
    // use iterator to find book from vector
 
/*  for(auto it: loans) {
        if(it.getISBN() == book.getISBN()) {
            it.restore();
 
            loans.erase(it);
        }
    }*/
 
    for(std::vector<Book>::iterator it = loans.begin();it != loans.end(); it++) {
        if(it->getISBN() == book.getISBN()) {
 
        // remove the book in question from vector and restore it
            book.restore();
            loans.erase(it);
 
        // after removing the book, exit the loop
        // NOTE: iterator will be invalidated otherwise causing Segfault !!!
            return;
        }
    }
}
 
const std::vector<Book>& Customer::getLoans() const {
    return loans;
}
 
void Customer::print() {
    std::cout << "Customer: " << name << ", " << id << ", has " << loanAmount << " books on loan:" << std::endl;
 
    for(auto& it: loans) {
    	std::cout << "* ";
        it.print();
    }
    /*for(std::vector<Book>::iterator it; it != loans.end(); it++) {
        if(it != loans.end()) {
            it->print();
        }
    }*/
}

