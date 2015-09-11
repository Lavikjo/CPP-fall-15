#include <cstddef>
#include <iostream>
#include "book.hpp"
#include "customer.hpp"

int main(void) {
    /*TESTING BOOK*/
    std::cout << "****\nCreating a book\n****" << std::endl;
    auto b = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    std::cout << "\n****\nTesting getters\n****" << std::endl;
    std::cout << "Name: " <<  b.getName() << std::endl;
    std::cout << "Author: " << b.getAuthor() << std::endl;
    std::cout << "ISBN: " << b.getISBN() << std::endl;
    std::cout << "Loaned: " << (b.getStatus() ? "yes" : "no") << std::endl;
    std::cout << "\n****\nTesting print\n****" << std::endl;
    b.print();
    std::cout << "\n****\nTesting loan\n****" << std::endl;
    std::cout << "Loaning " << (b.loan() ? "succesful" : "failed") << std::endl;
    std::cout << "Loaned: " << (b.getStatus() ? "yes" : "no") << std::endl;
    b.print();
    std::cout << "Loaning " << (b.loan() ? "succesful" : "failed") << std::endl;
    std::cout << "\n****\nTesting restore\n****" << std::endl;
    b.restore();
    b.print();

    /*TESTING CUSTOMER*/
    std::cout << "\n****\nCreating customer\n****" << std::endl;
    auto c = Customer("Chris Customer", "34674568");
    std::cout << "\n****\nTesting getters\n****" << std::endl;
    std::cout << "Name: " <<  c.getName() << std::endl;
    std::cout << "Customer ID: " << c.getID() << std::endl;
    std::cout << "Number of loans: " << c.getLoanAmount() << std::endl;
    std::cout << "\n****\nTesting print\n****" << std::endl;
    c.print();
    std::cout << "\n****\nTesting loanBook\n****" << std::endl;
    c.loanBook(b);
    c.print();
    auto b2 = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    c.loanBook(b2);
    c.print();
    std::cout << "\n****\nTesting returnBook\n****" << std::endl;
    c.returnBook(b);
    c.print();

    return 0;
}
