#ifndef ELEC_AS_CPP_SW_HH
#define ELEC_AS_CPP_SW_HH

#include "software.h"
#include "bugw.hpp"

#include <string>
#include <iostream>

class Software {

    public:
        /* Required public member functions:
         * ---------------------------------
         */

        /* Constructor:
         *
         * The same as in the C interface, but in C++ fashion, i.e. takes std::strings
         * instead of char*, etc. The order of the parameters should be the same as
         * in the C implementation.
         *
         * The constructor should throw std::runtime_error in case the C implementation
         * returns NULL on creation.
         */
         Software(std::string name, int revision);

        /* RO3 (Rule of Three):
         * --------------------
         */

        /* Destructor:
         *
         * The destructor should call the corresponding C function to get rid of the
         * memory allocations.
         */
         ~Software();
        /* Copy constructor:
         *
         * A C++ style copy constructor, which creates a copy of the Software object.
         */
         Software(const Software&);
        /* Assignment operator overload:
         *
         * A C++ style assignment operator overload for the Software objects.
         */
        /* -------------------- */
         Software& operator=(const Software&);
        /* getName:
         *
         * Takes no parameters and returns the name of the Software object as a
         * std::string.
         */
         std::string getName() const;
        /* getRevision:
         *
         * Takes no parameters and returns the revision number of the Software object
         * as an integer (int).
         */
         int getRevision() const;
        /* numberOfBugs:
         *
         * Takes no parameters and returns the number of Bugs in the Software as an
         * integer (int).
         */
         int numberOfBugs() const;
        /* reportBug:
         *
         * Takes a Bug& as a parameter. The function reports a new Bug in the software,
         * in other words the parameter Bug is appended to the software's bugs list.
         *
         * If the C implementation fails, i.e. returns NULL the function throws an
         * std::runtime_error.
         */
         void reportBug(Bug&);
        /* fixBug:
         *
         * Takes a const std::string& representing the Bug's id as a parameter.
         *
         * The function sets the fixed state of the bug with a corresponding id,
         * in the software's bugs list, as fixed.
         *
         * If the C implementation fails, i.e. returns NULL the function throws an
         * std::runtime_error.
         */
         void fixBug(const std::string&);
        /* Other requirements:
         * -------------------
         */
         friend std::ostream& operator<<(std::ostream&, Software&);
        /* Output stream, << -operator overload:
         *
         * An overloaded output stream operator that uses the C implementation to
         * print the software to the output stream.
         *
         */
    private:

        struct Software_s* soft_ptr;
        /* A pointer to the Software_s structure. This is the link between the wrapper
         * and the C interface. The C interface functions can be used with this
         * pointer.
         */
};
    
    
#endif
