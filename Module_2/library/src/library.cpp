#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"


Library::Library(std::string const& n){
	name = n;
	std::vector<Book> books;
	std::vector<Customer> customers;
}

const std::string Library::getName() const {
	return name;
}

std::vector<Book>& Library::getBooks() {
	return books;
}

std::vector<Customer>& Library::getCustomers() {
	return customers;
}

Book Library::findBookByName(const std::string& bookName) {
	Book foundBook = Book();
	for(auto& book: books) {
		if(book.getName() == bookName) {
			foundBook = book;
		}
	}
	return foundBook;
}

std::vector<Book> Library::findBooksByAuthor(const std::string& author) {
	std::vector<Book> foundBooks;
	for(auto& book: books) {
		if(book.getAuthor() == author) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}

std::vector<Book> Library::findAllLoanedBooks() {
	std::vector<Book> loanedBooks;

	for(auto& book: books) {
		if(book.getStatus()) {
			loanedBooks.push_back(book);
		}
	}
	return loanedBooks;
}

Customer Library::findCustomer(const std::string& customerID) {
	Customer foundCustomer = Customer();
	for(auto& customer: customers) {
		if(customer.getID() == customerID) {

			foundCustomer = customer;
		}
	}
	return foundCustomer;
}
