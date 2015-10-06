#include "object.hpp"
#include "list.hpp"
#include "arraylist.hpp"
#include "integer.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
#define MYASSERT(x) std::cout << std::setw(35) << std::left << #x << "=>" << ((x) ? "OK" : "FAIL") << std::endl

int main()
{
  
  std::cout << "Testing our integer class" << std::endl;
  Object *obj = new Integer(5);
  Object *obj2 = new Integer(6);
  MYASSERT(!obj->equals(obj2));
  
  delete obj2;
  obj2 = new Integer(5);

  MYASSERT(obj->equals(obj2));

  delete obj2;

  struct MyObj : public Object {
    bool equals(Object const *) const { return false; }
    std::string toString() const { return "foobar"; }
  };
  
  std::cout << "Comparing an Integer to something else" << std::endl;
  
  Object *myObj = new MyObj;

  MYASSERT(!obj->equals(myObj));
  
  delete obj;
  delete myObj;

  std::cout << "Creating the ArrayList" << std::endl;
  List *l = new ArrayList(3);

  MYASSERT(l->size() == 3);
  
  Integer *ints[3];
  for (int i = 0; i < 3; i++)
    {
      ints[i] = new Integer(i * 10);
      MYASSERT(l->set(i, ints[i]) == NULL); // there was a NULL pointer
      // before adding the first value

      MYASSERT(l->get(i)->equals(ints[i]));
    }

  Iterator *iter = l->iterator();
  int idx = 0;

  while (iter->hasNext())
    {
      MYASSERT(iter->next()->equals(ints[idx]));
      idx++;
    }
  
  delete iter;

  for (int i = 0; i < 3; i++)
    MYASSERT(l->indexOf(ints[i]) == i);
  Object *newObj = new Integer(31338);
  
  Object *oldObj = l->set(1, newObj);
  
  MYASSERT(oldObj->equals(ints[1]));
  delete oldObj;
  
  MYASSERT(l->get(1)->equals(newObj));

  std::cout << "Testing exceptions" << std::endl;

  try {
    l->add(NULL);
    std::cout << "l->add didn't throw" << std::endl;
  } catch (UnsupportedOperationException const &) { std::cout << "l->add threw UnsupportedOperationException" << std::endl; }
  
  iter = l->iterator();
  while (iter->hasNext())
    delete iter->next();
  delete iter;
  delete l;
}
