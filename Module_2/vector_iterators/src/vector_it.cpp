#include <iostream>
#include <sstream>
#include <vector>
#include "vector_it.hpp"

std::vector<int> readVector() {
	int number = 0;
	std::vector<int> v;
	// cin returns false if input isn't int
	while(std::cin >> number) {
		v.push_back(number);	
	}
	return v;
	
	
}

void printSum1(std::vector<int>& v) {
	std::stringstream ss;
	int temp = 0;
	int sum = 0;
	int idx = 0;
	for(auto it = v.begin(); it != v.end(); it++) {
		
		if(it != v.begin()) {
			sum = *it + temp;
			ss << sum << " ";
		 }
		
		temp = *it;
		idx++;
	}


	std::cout << ss.str() << std::endl;
}

void printSum2(std::vector<int>& v) {
	auto startit = v.begin();
	// NOTE TO SELF: vector.end() doesn't point to last element!!!
	auto endit = v.end()-1;
	std::stringstream ss;
	int sum = 0;

	// when iterators are next to each other they are in the middle
	while(std::distance(startit,endit)>1) {
		sum = *startit + *endit;
		ss << sum << " ";
		startit++;
		endit--;
	}
	std::cout << ss.str() << std::endl;
}
