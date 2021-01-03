//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "random"

void Run()
{
    std::random_device device;
    std::default_random_engine engine(device());// default_random_engine, mt19937, mt19937_64 ...
    std::uniform_int_distribution<int> func(0, 100);// for int, long
    std::uniform_real_distribution<float> func2(0, 100);// for float, double

    for (auto i = 0; i < 10; i++) std::cout << func(engine) << std::endl;
    for (auto i = 0; i < 10; i++) std::cout << func2(engine) << std::endl;
}