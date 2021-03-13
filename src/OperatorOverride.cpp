//
// Created by User on 2021/1/3.
//

#include <iostream>

class TestOperatorOverride
{
public:
    static void Run()
    {
        std::cout << "============================= " << "Test Operator Override" << " =============================" << std::endl;
        TestOperatorOverride foo{};
        std::cout << "before call foo's operator '()', foo data = " << foo.data << std::endl;
        foo();
        std::cout << "after call foo's operator '()', foo data = " << foo.data << std::endl;
    }
private:
    int data;
    TestOperatorOverride() = default;
    void operator()()
    {
        std::cout << "Hello" << std::endl;
        this->data = 5;
    }
};
