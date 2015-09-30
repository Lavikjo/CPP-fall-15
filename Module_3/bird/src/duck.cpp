 #include <iostream>
#include "duck.hpp"

 void Duck::speak(std::ostream &os) const {
 	os << name <<": QUACK" << std::endl;
 }