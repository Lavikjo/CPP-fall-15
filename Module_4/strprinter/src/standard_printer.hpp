#ifndef ELEC_CPP_PRINTER_HH
#define ELEC_CPP_PRINTER_HH

#include "printer.hpp"

/* Class StandardPrinter
 * A minimal StringPrinter implementation with no special functionality
 *  apart from the std::ostream& stream parameter
 * Note:
 *  The Constructor
 *  The implementation of clone()
*/
class StandardPrinter : public StringPrinter
{
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    StandardPrinter(std::ostream &os = std::cout) : StringPrinter(os)
    { }
    /* Copy this object */
    StandardPrinter* clone() const
    {
        return new StandardPrinter(os);
    }
    virtual StringPrinter& operator()(const std::string& str)
    {
        /* os is a protected member of the base class */
	os << str << std::endl;
        return *this;
    }
private:
};

#endif
