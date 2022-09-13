#include <iostream>

#ifndef TEST_H
#define TEST_H 
class Test{
    

    public:
        template <typename T>
        static void TEST_EQ(std::string _testSuite, T _val, T _expectedVal);



};

#endif