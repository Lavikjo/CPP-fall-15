#ifndef OWL_HH
#define OWL_HH

#include "bird.hpp"

// Implement the class here

class Owl: public Bird {
	public:
		Owl(const std::string& n) : Bird(n) {}


		void speak(std::ostream &os) const;


};
#endif
