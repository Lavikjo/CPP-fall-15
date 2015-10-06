#ifndef OBJECT_HH
#define OBJECT_HH

#include <string>

class Object {
public:
  virtual bool equals(Object const *obj) const = 0;
  virtual std::string toString() const = 0;
  virtual ~Object() {}

};

#endif
