#include "pokemon.hpp"

void addPokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id) {

	collection.push_back(std::make_pair(name, id));
}

bool removePokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id) {

	auto it = find(collection.begin(), collection.end(),make_pair(name, id));

	if(it != collection.end()) {

		collection.erase(it);
		return true;

	} else {

		return false;
	}
}

void printPokemon(const std::pair<std::string, size_t> pair) {

	std::cout << "id: " << pair.second << ", name: " << pair.first << std::endl;
}

void printCollection(std::list<std::pair<std::string, size_t>>::const_iterator begin, std::list<std::pair<std::string, size_t>>::const_iterator end) {

	for_each(begin, end, printPokemon);
}

bool sortNameFirst(const std::pair<std::string, size_t>& lpair, const std::pair<std::string, size_t>& rpair) {
	if(lpair.first == rpair.first) {
		return lpair.second < rpair.second;
	} else {
		return lpair.first < rpair.first;
	}
}

bool sortIDFirst(const std::pair<std::string, size_t>& lpair, const std::pair<std::string, size_t>& rpair) {
	if(lpair.second == rpair.second) {
		return lpair.first < rpair.first;
	} else {
		return lpair.second < rpair.second;
	}
}

void sortCollection(std::list<std::pair<std::string, size_t>>& collection, size_t sortType) {

	if(sortType) {
		collection.sort(sortNameFirst);
		//If the parameter sortType is 1 the collection is sorted first by name then by id,
 		//in case the names are equal then by id.
	
	} else {
		collection.sort(sortIDFirst);
		//If the parameter sortType is 0 the collection is sorted first by id,
 		//in case the ids are equal then by name.
	}
}

bool uniquePokemon(const std::pair<std::string, size_t>& lpair, const std::pair<std::string, size_t>& rpair) {
	return (lpair.first == rpair.first);
}

std::list<std::pair<std::string, size_t>> mergeCollections(std::list<std::pair<std::string, size_t>> const& c1, std::list<std::pair<std::string, size_t>> const& c2) {

	std::list<std::pair<std::string, size_t>> newCollection;


	// add all elements to newCollection
	for(auto& it:c2) {
		newCollection.push_back(it);
	}
	for(auto& it:c1) {
		newCollection.push_back(it);
	}
	
	//sort the new collection
	newCollection.sort(sortIDFirst);

	// remove duplicates from new collection
	newCollection.unique(uniquePokemon);

	return newCollection;

}