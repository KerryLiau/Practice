//
// Created by User on 2020/8/8.
//

#include "iostream"
#include "future"

class TestSync
{
public:
    TestSync()
    {
        mutex = std::make_unique<std::mutex>();
    };
    static void Run()
    {
        std::cout << "============================= " << "Test Synchronize" << " =============================" << std::endl;
        auto test_sync = std::make_unique<TestSync>();
        auto begin = std::chrono::high_resolution_clock::now();
        for (auto i = 0; i < 5; i++)
        {
            auto async_work = std::async(std::launch::async, [&test_sync, i] () {
                return test_sync->Sync(1000000 * i);
            });
            std::cout << "Thread going to sleep " << i << " seconds" << std::endl;
            auto result = async_work.get();
            std::cout << "i * 2 = " << result << std::endl;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        std::cout << "the duration: " << duration << " milli seconds" << std::endl;
    }

private:
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
        return i * 2;
    }
};