#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include <cassert>
#include "../src/object.hpp"
#include "../src/list.hpp"
#include "../src/arraylist.hpp"
#include "../src/integer.hpp"


TEST(test_arraylist, test_int_class) {
    Object *obj = new Integer(5);
    Object *obj2 = new Integer(6);
    EXPECT_TRUE(!obj->equals(obj2));

    delete obj2;
    obj2 = new Integer(5);

    EXPECT_TRUE(obj->equals(obj2));

    delete obj2;

    struct MyObj : public Object {
        bool equals(Object const *) const { return false; }
        std::string toString() const { return "foobar"; }
    };

    Object *myObj = new MyObj;

    EXPECT_TRUE(!obj->equals(myObj));

    delete obj;
    delete myObj;
}

TEST(test_arraylist2, test_simple) {
    List *l = new ArrayList(3);

    EXPECT_EQ(3, l->size());

    Integer *ints[3];
    for (int i = 0; i < 3; i++)
    {
        ints[i] = new Integer(i * 10);
        EXPECT_EQ(NULL, l->set(i, ints[i])); // there was a NULL pointer
        // before adding the first value

        EXPECT_TRUE(l->get(i)->equals(ints[i]));
    }

    Iterator *iter = l->iterator();
    int idx = 0;

    while (iter->hasNext())
    {
        EXPECT_TRUE(iter->next()->equals(ints[idx]));
        idx++;
    }

    delete iter;

    for (int i = 0; i < 3; i++)
        EXPECT_EQ(i, l->indexOf(ints[i]));
    Object *newObj = new Integer(31338);

    Object *oldObj = l->set(1, newObj);

    EXPECT_TRUE(oldObj->equals(ints[1]));
    delete oldObj;

    EXPECT_TRUE(l->get(1)->equals(newObj));

    iter = l->iterator();
    while (iter->hasNext())
        delete iter->next();
    delete iter;
    delete l;

}

TEST(test_arraylist3, test_big) {
    std::srand(time(0));

    int sz = std::rand() % 300 + 200;

    List *l = new ArrayList(sz);

    EXPECT_EQ(sz, l->size());

    Integer *ints[200002];
    for (int i = 0; i < sz; i++)
    {
        ints[i] = new Integer(i * 10);

        EXPECT_EQ(NULL, l->set(i, ints[i])); // there was a NULL pointer
        // before adding the first value

        EXPECT_TRUE(l->get(i)->equals(ints[i]));
    }

    Iterator *iter = l->iterator();
    int idx = 0;

    while (iter->hasNext())
    {
        EXPECT_TRUE(iter->next()->equals(ints[idx]));
        idx++;
    }

    delete iter;

    for (int i = 0; i < sz; i++)
        EXPECT_EQ(i, l->indexOf(ints[i]));
    Object *newObj = new Integer(31338);

    int place = std::rand() % (sz - 1);

    Object *oldObj = l->set(place, newObj);

    EXPECT_TRUE(oldObj->equals(ints[place]));
    delete oldObj;

    EXPECT_TRUE(l->get(place)->equals(newObj));

    iter = l->iterator();
    while (iter->hasNext())
        delete iter->next();
    delete iter;
    delete l;

}

TEST(test_arraylist4, test_exceptions) {
    std::srand(time(0));

    int sz = std::rand() % 300 + 200;

    List *l = new ArrayList(sz);

    EXPECT_EQ(sz, l->size());

    Integer *ints[200002];
    for (int i = 0; i < sz; i++)
    {
        ints[i] = new Integer(i * 10);

        EXPECT_EQ(NULL, l->set(i, ints[i])); // there was a NULL pointer
        // before adding the first value

        EXPECT_TRUE(l->get(i)->equals(ints[i]));
    }

    Iterator *iter = l->iterator();
    int idx = 0;

    while (iter->hasNext())
    {
        EXPECT_TRUE(iter->next()->equals(ints[idx]));
        idx++;
    }

    delete iter;

    for (int i = 0; i < sz; i++)
        EXPECT_EQ(i, l->indexOf(ints[i]));
    Object *newObj = new Integer(31338);

    int place = std::rand() % (sz - 1);

    Object *oldObj = l->set(place, newObj);

    EXPECT_TRUE(oldObj->equals(ints[place]));
    delete oldObj;

    EXPECT_TRUE(l->get(place)->equals(newObj));

    try {
        l->add(NULL);
    } 
    catch (UnsupportedOperationException const &) { 
        EXPECT_TRUE("l->add threw UnsupportedOperationException");
    }

    iter = l->iterator();
    while (iter->hasNext())
        delete iter->next();
    delete iter;
    delete l;

}

