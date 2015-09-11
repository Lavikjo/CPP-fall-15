#include <iostream>
#include "rectangle.hpp"

// Write you function here and test it with the main.

void rectangle() {
double base;
double height;
double area;
double circumference;

std::cout << "Please enter base and height" << std::endl;
std::cin >> base  >> height;

area = base * height;
circumference = 2*base + 2*height;

std::cout << "Area: " << area << std::endl << "Circumference: " << circumference << std::endl; 
}

