#include "printers.hpp"

#include <stdexcept>

Printers::Printers() {}

Printers::Printers(const Printers& other_printers) {
	index = other_printers.index;
}

Printers::~Printers() {
	for(auto it = index.begin(); it != index.end(); it++) {
		
		if(!it->second) {
		delete it->second;
		}
	}
}

void Printers::add(const std::string& name, StringPrinter* ptr) {
	auto it = index.find(name);
	if(it != index.end()) {
		throw std::invalid_argument("Duplicate index");
	}
	if(!ptr) {
		throw std::invalid_argument("Invalid printer");
	}
	index[name] = ptr;
}

StringPrinter& Printers::operator[](const std::string& name) {
	auto it = index.find(name);
	if(it == index.end()) {
		throw std::invalid_argument("Unknown index");
	}
	return *(it->second);
}

Printers& Printers::operator=(const Printers& other_printers) {
	if(this->index == other_printers.index) {
		return *this;
	}

	this->index.clear();

	if(this->index.empty()) {
		this->index = other_printers.index;
	}
	return *this;
}
