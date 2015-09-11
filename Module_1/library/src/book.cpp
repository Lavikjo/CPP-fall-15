#include "book.hpp"

#include <ctime>
#include <iostream>
#include <sstream>


Book::Book( std::string const &n, std::string const &a, std::string const &nr, bool status, Date date) {
	name = n;
	author = a;
	isbn = nr;
	loaned = status;
	due_date = date;
}

const std::string Book::getName() const {
	return name;
}

const std::string Book::getAuthor() const {
	return author;
}

const std::string Book::getISBN() const {
	return isbn;
}

const std::string Book::getDueDate() const {
	std::stringstream dateStream;
	

	dateStream << due_date.day << "-" << due_date.month << "-" << due_date.year;
	return dateStream.str();
}

bool Book::getStatus() {
	return loaned;
}


bool Book::loan() {
	// fetch current date for setting the date
	std::time_t curTime = time(0);
	struct tm * timeinfo = localtime(&curTime);

	if(!loaned) {
		loaned = true;
		due_date.day = timeinfo->tm_mday;
		due_date.month = timeinfo->tm_mon + 2;
		due_date.year = timeinfo->tm_year + 1900;
		return true;

	} else {
		return false;
	}
}

void Book::restore() {
	due_date.day = 0;
	due_date.month = 0;
	due_date.year = 0;
	loaned = false;
}

void Book::print() {
	std::stringstream dateStream;
	
	dateStream << due_date.day << "-" << due_date.month << "-" << due_date.year;

	std::cout << "Book: " << name << ", author: " << author << ", ISBN: " << isbn << ", loaned " << loaned << ", due date: " << dateStream.str() << std::endl;
}