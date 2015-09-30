#include <iostream>
#include "owl.hpp"

 void Owl::speak(std::ostream &os) const {
	os << name << ": WHUU" << std::endl;
}