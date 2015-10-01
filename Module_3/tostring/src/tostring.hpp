#ifndef CONVERT_HH
#define CONVERT_HH

#include <sstream>


template <typename T>
std::string toString(T container) {
	std::stringstream ss;
	ss << "{ ";
	for(auto it = container.begin(); it != container.end(); it++) {
			
			if(it == container.begin()) {
				ss << *it;
		 	} else {
		 		ss << ", " << *it;
		 	}
	}
	ss << " }";
	return ss.str();
}

template <> std::string toString(std::string s) {
	std::stringstream ss;
	ss << "\"" << s << "\"";
	return ss.str();
}

template <typename T> std::string toString(T beginIt, T endIt) {
	std::stringstream ss;
	ss << "{ ";
	for(auto it = beginIt; it != endIt; it++) {
		if(it == beginIt) {
			ss << *it;
		} else {
			ss << ", " << *it;
		}
	}
	ss << " }";
	return ss.str();
}

/* As an introduction to templates you will write and specialize a template function 
 * for formatting the contents of a container (string, vector, list, ...) into a string, 
 * assuming that the elements of the container are printable (with the << operator). 
 *
 * This function is called toString and it returns the container contents in the following format 
 * (assuming a container of strings with three elements: "foo", "bar" and "baz"):
{ foo, bar, baz }
 * When passed a std::string, the function should, instead of returning a list of characters { f, o, o, b, a, r }, 
 * just put double quotes around the string:
"foobar"
 * Additionally, overload the function with a version that, instead of a container, 
 * takes begin and end iterators, and formats the contents in the format specified above for containers 
 * (no special handling for string iterators).
 *
 * Notes:
 * You may assume that std::strings have their regular interface. 
 * For other containers, only use the iterator interface (begin and end functions).
 * Your functions must work with at least bidirectional iterators. Note that such iterators do not have operators + and -
 * If you'd really want to provide printing support for containers, 
 * you should write operator<< for them instead of a toString function.
 * This would allow printing containers that contain other containers, etc.
 */

#endif

