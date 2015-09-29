#include "dragon.hpp"

/* Dragon class functions here*/

/* DragonCave class functions here*/
DragonCave::DragonCave() { }
   
// Made for you, as it uses a tiny bit of dynamic memory here! You will see more of this in the next round.
DragonCave::~DragonCave() 
{ 
  for (std::list<Dragon*>::iterator it = dragons.begin(); it != dragons.end(); it++)
    delete *it;
}
    
