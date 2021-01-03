//
// Created by User on 2021/1/3.
//

#include <iostream>

class Foo
{
public:
    int data;
    Foo() = default;
    void operator()()
    {
        std::cout << "Hello" << std::endl;
        this->data = 5;
    }
};
void bar(Foo &foo)
{
    //
}

void MainTest()
{
    Foo foo{};
    foo();
    std::cout << "foo = " << foo.data << std::endl;
}

