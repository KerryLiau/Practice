#include "src/permutation/Factorial.cpp"
#include "src/JsonDemo.cpp"
#include "src/AsyncThread.cpp"
#include "src/SyncLock.cpp"
#include "src/Lambda.cpp"

int main()
{
    std::cout << "============================= " << "Test Json" << " =============================" << std::endl;
    TestJson::Run();
    std::cout << "============================= " << "Test Synchronize" << " =============================" << std::endl;
    TestSync::Run();
    std::cout << "============================= " << "Test Asynchronous" << " =============================" << std::endl;
    TestAsync::Run();
    std::cout << "============================= " << "Test Lambda" << " =============================" << std::endl;
    TestLambda::Run();
    return 0;
}
