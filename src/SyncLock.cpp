//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "future"

class TestSync
{
    std::unique_ptr<std::mutex> mutex;
    int Sync(int i) {
        std::this_thread::sleep_for(std::chrono::microseconds(i));
        /*
         * 兩種使用 std::mutex 的方式:
         * 1. mutex.lock & mutex.unlock
         * 2. std::lock_guard<std::mutex> | std::unique_lock<std::mutex>
         * 第一種方式不安全，因為當發生錯誤或例外拋出時，會造成死鎖
         * 第二種方式比較安全，當發生錯誤或例外拋出時，會進行解鎖
         */
        std::unique_lock<std::mutex> lockGuard(*mutex);
        std::cout << "i = " << i << std::endl;
        return i;
    }

public:
    TestSync()
    {
        mutex = std::make_unique<std::mutex>();
    };
    static void Run()
    {
        auto test_sync = std::make_unique<TestSync>();
        auto begin = std::chrono::high_resolution_clock::now();
        for (auto i = 0; i < 5; i++)
        {
            auto async_work = std::async(std::launch::async, [&test_sync] () {
                return test_sync->Sync(1000000);
            });
            std::cout << async_work.get() << std::endl;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

//    std::cin.get();
    }
};
//std::unique_ptr<std::mutex> TestSync::mutex;