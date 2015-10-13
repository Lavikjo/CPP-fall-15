#ifndef ELEC_CPP_DIAGONAL_HH
#define ELEC_CPP_DIAGONAL_HH

#include "printer.hpp"

/* Implement the class DiagonalPrinter here
 * The class inherits (public inheritance) class StringPrinter
 *
 * DiagonalPrinter prints a string diagonally
 * l        -
 *  i       -
 *   k      -
 *    e     -
 *          -
 *      t   -
 *       h  -
 *        i -
 *         s-
 * Where the dash (-) indicates a newline character.
 * Additionally and optionally, this printer can print a special first and
 *  last line for its output. This functionality is disabled by default.
 *
 * The DiagonalPrinter is constructed with three parameters
 *  The first line - "" by default, i.e. it is not printed at all
 *  The last line  - "" by default, i.e. it is not printed at all either
 *  The output stream
 *
 * Note that the default print functionality does not suffice for this class
 *  and you will have to implement the print overload yourself.
 *
 * Implement the class accordingly.
 */
std::string operator*(const std::string& s, size_t n) {
    std::stringstream ss;
    if(!n) {
    	return "";
    }
    while (n--)
        ss << s;
    return ss.str();
}


 class DiagonalPrinter : public StringPrinter
{
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    DiagonalPrinter(std::string first = "" ,std::string last = "", std::ostream &os = std::cout) : StringPrinter(os), first(first), last(last) {}
    /* Copy this object */

    DiagonalPrinter* clone() const {

        return new DiagonalPrinter(first, last, os);
    }

    virtual DiagonalPrinter& operator()(const std::string& str)
    {   std::string space = " ";
        /* os is a protected member of the base class */
    	if(!first.empty()) {
    		os << first << std::endl;
    	}
    	for(size_t ch = 0; ch < str.length(); ch++) {
    		os << space*ch << str.at(ch) << space*(str.length() - ch - 1) << std::endl;
    	}

		if(!last.empty()) {
			os << last << std::endl;
		}

        return *this;
    }

private:
	std::string first;
	std::string last;
};
#endif
