//
// Created by User on 2021/1/3.
//
#include <iostream>

/**
 * 計算階乘(n!)
 * @param n
 */
long factorial(int n)
{
    long f = n;
    while (n > 1) f *= --n;
    return f;
}
long combination(int m, int n)
{
    try
    {
        int sub = m - n;
        auto sf = factorial(sub);
        auto mf = factorial(m);
        auto nf = factorial(n);
        std::cout << "mf: " << mf << ", nf: " << nf << ", sf: " << sf << std::endl;
        return mf / (nf * sf);
    } catch (const std::exception& e)
    {
        std::cout << "err: " << e.what() << std::endl;
        throw e;
    }
}
long permutation(int m, int n)
{
    try
    {
        auto mf = factorial(m);
        auto nf = factorial(n);
        return mf / nf;
    } catch (const std::exception& e)
    {
        std::cout << "err: " << e.what() << std::endl;
        throw e;
    }
}

void Run()
{
    std::cout << combination(7, 3) << std::endl;
}
