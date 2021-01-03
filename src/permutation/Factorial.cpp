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
    int sub = m - n;
    auto sf = factorial(sub);
    auto mf = factorial(m);
    auto nf = factorial(n);
    return mf / (nf * sf);
}
long permutation(int m, int n)
{
    auto mf = factorial(m);
    auto nf = factorial(n);
    return mf / nf;
}

void MainTest()
{
    std::cout << "Hello" << std::endl;
}
