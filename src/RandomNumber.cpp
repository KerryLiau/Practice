//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "random"

class TestRandom
{
public:
    static void Run()
    {
        std::cout << "============================= " << "Test Random Number" << " =============================" << std::endl;
        std::random_device device;
        std::default_random_engine engine(device());// default_random_engine, mt19937, mt19937_64 ...
        std::uniform_int_distribution<int> func(0, 100);// for int, long
        std::uniform_real_distribution<double> func2(0, 100);// for float, double

        std::cout << "Integer random: " << std::endl;
        for (auto i = 0; i < 5; i++)
        {
            std::cout << func(engine) << std::endl;
        }
        std::cout << "Double random: " << std::endl;
        for (auto i = 0; i < 5; i++)
        {
            std::cout << func2(engine) << std::endl;
        }
    }
};
