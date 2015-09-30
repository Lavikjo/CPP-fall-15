#include "bird.hpp"
#include "aviary.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

Bird* Aviary::operator[](int index) {
	return birds[index];
}

const Bird* Aviary::operator[](int index) const{
	return birds.at(index);
}

void Aviary::addBird(Bird *b) {
	
	if(!b) {
		throw std::logic_error("Bird is NULL!");
	}	
	birds.push_back(b);
	
}

Aviary::~Aviary() {
	for(size_t i = 0; i < this->size(); i++) {
		delete birds[i];
	}
}

void Aviary::speakAll(std::ostream &os) const {
	for(auto& bird : birds) {
		bird->speak(os);
	}
}

size_t Aviary::size() const {
    return std::distance(birds.begin(), birds.end());
}


