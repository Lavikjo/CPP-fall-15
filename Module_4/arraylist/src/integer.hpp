#ifndef INTEGER_HH
#define INTEGER_HH

#include <sstream>
#include <string>
#include "object.hpp"

class Integer : public Object {
public:
  Integer(int i) : val(i) {}
  std::string toString() const { std::ostringstream os; os << val; return os.str(); }

  bool equals(Object const *obj) const {
    Integer const *i = dynamic_cast<Integer const *>(obj);
    if (i == NULL)
      return false;
    return i->val == val;
  }
    
  
private:
  int val;
};

#endif

