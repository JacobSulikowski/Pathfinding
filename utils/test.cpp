#include "test.h"

template <typename T>
void Test::TEST_EQ(std::string _testSuite, T _val, T _expectedVal){
    if(_val == _expectedVal){
        std::cout<<_testSuite<<": passed"<<std::endl;
    } else {
        std::cout<<_testSuite<<": failed"<<std::endl;
    }
}