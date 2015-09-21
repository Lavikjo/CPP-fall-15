#include <iostream>
#include <string>
#include "overload.hpp"

int main(void) {
    int r = 5;
    int w = 4, h = 3;
    int a = 7, b = 2;
    std::cout << "Area of a circle with radius of 5 is " << area(r) << ". Should be: 78.5." << std::endl;
    std::cout << "Area of a rectangle with width of 4 and height of 3 is " << area(w, h) << ". Should be: 12.0." << std::endl;
    std::cout << "Area of a trapezoid with height of 3 and sides of 7 and 2 is " << area(a, b, h) << ". Should be: 13.5." << std::endl;

    double c = 3.364673, d = 6.345636;
    std::string s1 = "Hello ", s2 = "world!";
    std::cout << "Adding together " << a << " and " << b << ". Got " << add(a,b) << ". Should be: 9." << std::endl;
    std::cout << "Adding together " << c << " and " << d << ". Got " << add(c,d) << ". Should be: 9.71031." << std::endl;
    std::cout << "Adding together " << s1 << " and " << s2 << ". Got " << add(s1,s2) << ". Should be: Hello world!" << std::endl;

    std::cout << "Summing together " << a << " and " << b << ". Got " << sum<int>(a,b) << ". Should be: 9." << std::endl;
    std::cout << "Summing together " << c << " and " << d << ". Got " << sum<double>(c,d) << ". Should be: 9.71031." << std::endl;
    std::cout << "Summing together " << s1 << " and " << s2 << ". Got " << sum<std::string>(s1,s2) << ". Should be: Hello world!" << std::endl;
}
