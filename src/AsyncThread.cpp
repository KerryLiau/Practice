//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "future"

class TestAsync {

public:
    static void Run()
    {
        std::cout << "============================= " << "Test Asynchronous" << " =============================" << std::endl;
        auto begin = std::chrono::high_resolution_clock::now();
        // use std::launch::async to asynchronous thread
        auto async_1 = std::async(std::launch::async, Async, 1);
        auto async_2 = std::async(std::launch::async, Async, 1);

        std::cout << async_1.get() << std::endl;
        std::cout << async_2.get() << std::endl;

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

//        std::cin.get();
    }

private:
    static int Async(int i) {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "i = " << i << std::endl;
        return i;
    }
};
