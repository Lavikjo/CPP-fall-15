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
         Bug() = default;
         Bug(const std::string &id, const std::string &description, Priority priority);

        /* RO3 (Rule of Three)
         * --------------------
         */

        /* Destructor:
         *
         * The destructor should call the corresponding C function to get rid of the
         * memory allocations.
         */

         ~Bug();

        /* Copy constructor:
         * 
         * A C++ style copy constructor, which creates a copy of the Bug object.
         */

         Bug(const Bug&);
        /* Assignment operator:
         * 
         * A C++ style assignment operator overload for the Bug objects.
         */
        Bug& operator=(const Bug&);

        /* -------------------- */

        /* getId:
         *
         * Takes no parameters and returns the id of the Bug object as a std::string.
         */
         std::string getId();
        /* getDescription:
         * 
         * Takes no parameters and returns the description of the Bug object as a
         * std::string.
         */
         std::string getDescription();
        /* getPriority:
         *
         * Takes no parameters and returns the priority of the Bug object.
         */
         Priority getPriority();
        /* isFixed:
         *
         * Takes no parameters and returns the fixed status of the Bug object as a
         * bool.
         */
         bool isFixed();
        /* fix:
         *
         * Takes no parameters and sets the fixed status of the Bug object as true (1).
         */
         void fix();
        /* getPtr:
         *
         * Accessor to the Bug object's struct Bug_s pointer. The function takes no
         * parameters and returns a struct Bug_s*.
         */
         struct Bug_s* getPtr();
        


        friend std::ostream& operator<<(std::ostream &os, const Bug& bug);
    private:

        /* A pointer to a Bug_s structure. This is the link between the wrapper and
         * the C interface. The C interface functions can be used with this pointer.
         */

        struct Bug_s* bug_ptr;
};

/* Other requirements:
         * -------------------
         */
         
        /* Output stream, << -operator overload:
         *
         * An overloaded output stream operator that uses the C implementation to
         * print the bug to the output stream.
         *
         */

#endif
