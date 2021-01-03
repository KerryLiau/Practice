//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "future"

std::mutex mutex;

int Async(int i) {
    std::this_thread::sleep_for(std::chrono::microseconds(i));
    std::lock_guard<std::mutex> lockGuard(mutex);// safe way, will unlock when exception throw or error occurred

//    mutex.lock();// not safe, cause dead lock when exception throw or error occurred
    std::cout << "i = " << i << std::endl;
//    mutex.unlock();// not safe, cause dead lock when exception throw or error occurred
    return i;
}

void Run()
{
    auto begin = std::chrono::high_resolution_clock::now();

    auto async_1 = std::async(std::launch::async, async, 1000000);
    auto async_2 = std::async(std::launch::async, async, 1000000);

    std::cout << async_1.get() << std::endl;
    std::cout << async_2.get() << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

//    std::cin.get();
}