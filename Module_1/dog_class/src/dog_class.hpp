#ifndef AALTO_ELEC_CPP_DOG_CLASS
#define AALTO_ELEC_CPP_DOG_CLASS

#include <string>

//Definition of simple class with some errors

class Dog {
public:
    Dog(int age, std::string name);
    void setAge(int age);
    int getAge() const;
    void setName(std::string name);
    const std::string& getName() const;
private:
    int age;
    std::string name;
};
#endif

