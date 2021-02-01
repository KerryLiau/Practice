//
// Created by User on 2021/2/1.
//

#include <iostream>

class TestLambda
{
public:
    static void Run()
    {
        LambdaFunctionVariable();
        LambdaCaller([]()
        {
            std::cout << "test lambda as argument" << std::endl;
        });
    }

private:
    static void LambdaFunctionVariable()
    {
        auto lambda_function = [](int i) {
            return ++i;
        };
        std::cout << "lambda function result: " << lambda_function(5) << std::endl;
    }

    template<typename Function>
    static void LambdaCaller(Function executor)
    {
        std::cout << "begin" << std::endl;
        executor();
        std::cout << "end" << std::endl;
    }

};