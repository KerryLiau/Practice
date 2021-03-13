//
// Created by User on 2021/2/1.
//

#include <iostream>

class TestLambda
{
public:
    static void Run()
    {
        std::cout << "============================= " << "Test Lambda" << " =============================" << std::endl;
        auto example = std::make_unique<TestLambda>();
        example->LambdaFunctionVariable();
        example->LambdaAnonymousFunction();
    }

private:
    std::string _argv1 = "---------- this demo lambda anonymous function, and catch 'this' pointer ----------";
    int _argv2 = 5;
    void LambdaAnonymousFunction()
    {
        this->LambdaCaller([*this] (int i, int j)
        {
            std::cout << this->_argv1 << std::endl;
            std::cout << "test lambda as anonymous function\n" << "i = " << i << "\nj = " << j << "\ni + j = " << i + j << std::endl;
        });
    }

    void LambdaFunctionVariable()
    {
        std::string show = "\nlambda function result:";
        auto lambda_function = [show, *this] (int i) {
            if (!show.empty())
            {
                std::cout << show << std::endl;
            }
            return i + this->_argv2;
        };
        std::cout << "begin" << std::endl;
        std::cout << "---------- this demo lambda function as variable ----------" << lambda_function(5) << std::endl;
        std::cout << "end\n" << std::endl;
    }

    template<typename Function>
    void LambdaCaller(Function executor)
    {
        std::cout << "begin" << std::endl;
        int n,m;
        n = 5;
        m = 10;
        executor(n, m);
        std::cout << "end\n" << std::endl;
    }

};