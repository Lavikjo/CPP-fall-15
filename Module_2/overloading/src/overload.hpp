#ifndef AALTO_ELEC_CPP_OVERLOAD
#define AALTO_ELEC_CPP_OVERLOAD

#include <string>

double area(int);
double area(int, int);
double area(int, int, int);
// Write three functions (called area) that calculate:
// 1. area of a circle (1 parameter, int) and returns the result as a double
// 2. area of a rectangle (2 parameters, 2 ints) and returns the result as a double
// 3. area of a trapezoid (3 parameters, 3 ints) and return the result as a double
int add(int, int);
double add(double, double);
std::string add(std::string, std::string);
// Write three functions (called add) that add together:
// 1. two integers and return the sum as int
// 2. two doubles and return the sum as double
// 3. two strings and return the result of concatenation as a string

template<class T>
T sum(T n1, T n2) {
	T result;
	result = n1 + n2;
	return result;
}
// Write one template function (called sum) that adds two variables of generic type T together and returns the sum as T
// Remember that also template implementations have to be in the header file!

#endif
