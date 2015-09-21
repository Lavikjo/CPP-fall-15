#include <iostream>
#include <vector>
#include <math.h>
#include "matrix.hpp"

// Remember to use auto and ranged for-loops when they can be used!
// Assumes 'm' is a square matrix



Matrix readMatrix(int n) {
	Matrix m(n,n);
	int number;
	std::vector<int> row;
	/*
	while(amount != limit) {
		while(x != n) {
			
			std::cin >> number;
			Matrix[y][x] = number;
			amount++;
			x++;
		}
		x = 0;

		y++;
	}


	return Matrix;
*/
/*
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < n; x++) {
			if (amount != limit) {
				std::cin >> number;
				m = number;
			}
		}
	
	return m;
	}
	*/

	for(auto y = 0; y < n; y++) {
		row =  m[y];
		for(auto x = 0; x < n; x++) {
			std::cin >> number;
			x = number;
		}
	}
	return m;
}
Matrix rotate90deg(Matrix & m) {
	Matrix copy = m;
	// read y-axis vectors containing x-axis vector
	for(auto &y : m) {
		// read x-axis vectors containing int
		for(auto &x : y) {
			x.push_back()
			
			
		}
	}
}

void print(Matrix & m){
    std::cout << "Printing out a " << m.size() << " x " << m.size() << " matrix:" << std::endl;
}
