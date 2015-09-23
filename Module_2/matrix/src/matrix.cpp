#include <iostream>
#include <vector>
#include <math.h>
#include "matrix.hpp"
#include <sstream>

// Remember to use auto and ranged for-loops when they can be used!
// Assumes 'm' is a square matrix



Matrix readMatrix(int n) {
	Matrix m;
	int number;
	std::vector<int> row;


	for(int y = 0; y < n;y++) {
		m.push_back(row);

		for(int x = 0; x < n;x++) {
			std::cin >> number;
			m.at(y).push_back(number);

		}
	}
	return m;

}

Matrix rotate90deg(Matrix & m) {
	Matrix copy = m;
	int n = m.size();
	std::vector<int> row;

	for(int y = 0; y < n;y++) {
		for(int x = 0; x < n;x++) {
			copy.at(y).at(x) = m.at(x).at(y);

		}
	}
	return copy;
}

void print(Matrix & m){
	std::stringstream ss;
    std::cout << "Printing out a " << m.size() << " x " << m.size() << " matrix:" << std::endl;
    for(auto& y: m) {
    	for(auto& x: y) {
    		ss << x << " ";
    	}
    	ss << std::endl;
    }
    std::cout << ss.str() << std::endl;
}
