#ifndef DUCK_HH
#define DUCK_HH

#include "bird.hpp"
// Implement the class here
class Duck: public Bird {
	public:
		Duck(const std::string& n) : Bird(n) {}


		virtual void speak(std::ostream &os) const;


};

#endif
