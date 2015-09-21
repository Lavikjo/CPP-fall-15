#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../src/overload.hpp"

#define pi 3.14

TEST(test_overload, test_area) {
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int r1 = (rand()) / (RAND_MAX / 1000);
    int r2 = (rand()) / (RAND_MAX / 1000);

    EXPECT_EQ((double)pi*r1*r1, area(r1));
    EXPECT_EQ((double)pi*r2*r2, area(r2));

    int w1 = (rand()) / (RAND_MAX / 1000);
    int w2 = (rand()) / (RAND_MAX / 1000);
    int h1 = (rand()) / (RAND_MAX / 1000);
    int h2 = (rand()) / (RAND_MAX / 1000);

    EXPECT_EQ(w1*h1, area(w1,h1));
    EXPECT_EQ(w2*h2, area(w2,h2));

    int a1 = (rand()) / (RAND_MAX / 1000);
    int a2 = (rand()) / (RAND_MAX / 1000);
    int b1 = (rand()) / (RAND_MAX / 1000);
    int b2 = (rand()) / (RAND_MAX / 1000);
    int h3 = (rand()) / (RAND_MAX / 1000);
    int h4 = (rand()) / (RAND_MAX / 1000);

    EXPECT_EQ((double)(a1+b1)/2*h3, area(a1,b1,h3));
    EXPECT_EQ((double)(a2+b2)/2*h4, area(a2,b2,h4));
}

TEST(test_overload2, test_add) {
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a1 = (rand()) / (RAND_MAX / 1000);
    int a2 = (rand()) / (RAND_MAX / 1000);
    int b1 = (rand()) / (RAND_MAX / 1000);
    int b2 = (rand()) / (RAND_MAX / 1000);

    EXPECT_EQ(a1+b1, add(a1,b1));
    EXPECT_EQ(a2+b2, add(a2,b2));

    double c1 = (rand()) / (RAND_MAX / 1000.0);
    double c2 = (rand()) / (RAND_MAX / 1000.0);
    double d1 = (rand()) / (RAND_MAX / 1000.0);
    double d2 = (rand()) / (RAND_MAX / 1000.0);

    EXPECT_EQ(c1+d1, add(c1,d1));
    EXPECT_EQ(c2+d2, add(c2,d2));

    const char alphanum[] = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string s1, s2;
    for (int i = 0; i < 100; ++i) {
        s1 = s1 + alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s1[100] = 0;

    for (int i = 0; i < 100; ++i) {
        s2 = s2 + alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s2[100] = 0;

    EXPECT_EQ(s1+s2, add(s1,s2));
}

TEST(test_overload3, test_sum) {
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a1 = (rand()) / (RAND_MAX / 1000);
    int a2 = (rand()) / (RAND_MAX / 1000);
    int b1 = (rand()) / (RAND_MAX / 1000);
    int b2 = (rand()) / (RAND_MAX / 1000);

    EXPECT_EQ(a1+b1, sum<int>(a1,b1));
    EXPECT_EQ(a2+b2, sum<int>(a2,b2));

    double c1 = (rand()) / (RAND_MAX / 1000.0);
    double c2 = (rand()) / (RAND_MAX / 1000.0);
    double d1 = (rand()) / (RAND_MAX / 1000.0);
    double d2 = (rand()) / (RAND_MAX / 1000.0);

    EXPECT_EQ(c1+d1, sum<double>(c1,d1));
    EXPECT_EQ(c2+d2, sum<double>(c2,d2));

    const char alphanum[] = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string s1, s2;
    for (int i = 0; i < 100; ++i) {
        s1 = s1 + alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s1[100] = 0;

    for (int i = 0; i < 100; ++i) {
        s2 = s2 + alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s2[100] = 0;

    EXPECT_EQ(s1+s2, sum<std::string>(s1,s2));
}
