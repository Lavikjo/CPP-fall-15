#include <string>
#include "overload.hpp"

#define pi 3.14

double area(int radius) {
	double area = pi*radius*radius;
	return area;
}

double area(int a, int b) {
	double area = a*b; 
	return (double)area;

}

double area(int a, int b, int h) {
	double divider = 2;
	double area = (a+b)*h/divider;
	return area;
}

int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}
std::string add(std::string a, std::string b) {
	return a + b;
}