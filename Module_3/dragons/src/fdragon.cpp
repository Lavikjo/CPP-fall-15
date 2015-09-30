#include "fdragon.hpp"

/* FantasyDragon class functions */
//Constructor here
FantasyDragon::FantasyDragon(std::string const& name, size_t age, size_t size): Dragon(name, age, size) { }

/* Fantasy dragon eats: People and PeopleFood */
void FantasyDragon::eat(std::list<Food>& food)
{
	for (std::list<Food>::iterator it = food.begin(); it != food.end();)
    if (it->type == People or it->type == PeopleFood)
    {
      std::cout << "Fantasy dragon ate: " << it->name << std::endl;
      it = food.erase(it);
      size++;
    } else it++;
}

void FantasyDragon::hoard(std::list<Treasure>& treasures)
{
	for (std::list<Treasure>::iterator it = treasures.begin(); it != treasures.end();)
    if (it->type == Jewellery)
    {
      std::cout << "Fantasy dragon received: " << it->name << std::endl;
      this->treasures.push_back(*it);
      it = treasures.erase(it);
    } else it++;
}

