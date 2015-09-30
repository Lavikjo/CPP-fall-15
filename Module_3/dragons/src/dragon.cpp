#include "dragon.hpp"

/* Dragon class functions here*/
const std::string& Dragon::getName() const {
	return name;
}

size_t Dragon::getAge() const {
	return age;
}

size_t Dragon::getSize() const{
	return size;
}
const std::list<Treasure>& Dragon::getTreasures() const {
	return treasures;
}

std::ostream& operator<<(std::ostream& os, Dragon const& dragon) {
	os << "Dragon named: " << dragon.getName() << ", age: " << dragon.getAge() << ", size: " << dragon.getSize() << std::endl
	<< "Treasures:" << std::endl;

	for(auto treasure: dragon.getTreasures()) {
		os << treasure.name << std::endl;
	}
	return os;
}

/* DragonCave class functions here*/   
DragonCave::DragonCave() {

}
// Made for you, as it uses a tiny bit of dynamic memory here! You will see more of this in the next round.
DragonCave::~DragonCave() 
{ 
  for (std::list<Dragon*>::iterator it = dragons.begin(); it != dragons.end(); it++)
    delete *it;
}
const std::list<Dragon*>& DragonCave::getDragons() const {
	return dragons;
}
   
void DragonCave::accommodateDragon(Dragon* d) {
	dragons.push_back(d);
} 

void DragonCave::evictDragon(const std::string &name) {
	for(auto it = dragons.begin(); it != dragons.end(); it++) {
		if((*it)->getName() == name){
			dragons.erase(it);
			return;
		}
	}
}

std::ostream& operator<<(std::ostream& os, DragonCave const& cave) {
	os << "DragonCave dwellers:" << std::endl; 

	for(auto dragon: cave.getDragons()) {
		os << std::endl << *dragon ;
	}
	return os;
}


