#ifndef ELEC_AS_CPP_BUG_HH
#define ELEC_AS_CPP_BUG_HH

#include "bug.h"
#include <string>
#include <iostream>

class Bug {
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

        /* RO3 (Rule of Three):
         * --------------------
         */

        /* Destructor:
         *
         * The destructor should call the corresponding C function to get rid of the
         * memory allocations.
         */
        /* Copy constructor:
         * 
         * A C++ style copy constructor, which creates a copy of the Bug object.
         */

        /* Assignment operator:
         * 
         * A C++ style assignment operator overload for the Bug objects.
         */
        /* -------------------- */

        /* getId:
         *
         * Takes no parameters and returns the id of the Bug object as a std::string.
         */
        /* getDescription:
         * 
         * Takes no parameters and returns the description of the Bug object as a
         * std::string.
         */
        /* getPriority:
         *
         * Takes no parameters and returns the priority of the Bug object.
         */
        /* isFixed:
         *
         * Takes no parameters and returns the fixed status of the Bug object as a
         * bool.
         */
        /* fix:
         *
         * Takes no parameters and sets the fixed status of the Bug object as true (1).
         */
        /* getPtr:
         *
         * Accessor to the Bug object's struct Bug_s pointer. The function takes no
         * parameters and returns a struct Bug_s*.
         */
        /* Other requirements:
         * -------------------
         */

        /* Output stream, << -operator overload:
         *
         * An overloaded output stream operator that uses the C implementation to
         * print the bug to the output stream.
         *
         */
    private:

        /* A pointer to a Bug_s structure. This is the link between the wrapper and
         * the C interface. The C interface functions can be used with this pointer.
         */
};

#endif
