#include <iostream>
#include <vector>
#include <math.h>
#include "matrix.hpp"

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
	return m;
}

void print(Matrix & m){
    std::cout << "Printing out a " << m.size() << " x " << m.size() << " matrix:" << std::endl;
}
