#include "src/permutation/Factorial.cpp"
#include "src/JsonDemo.cpp"
#include "src/AsyncThread.cpp"
#include "src/SyncLock.cpp"
#include "src/Lambda.cpp"
#include "third_party_lib/reflect/Reflection.hpp"

auto CleanNumberPrefix(std::string& string)
{
    auto prefix_num = 0;
    for (char c : string)
    {
        if (c >= '0' && c <= '9') prefix_num++;
    }
    string.replace(0, prefix_num, "");
}

auto CleanNumberPrefix(std::string&& string)
{
    auto prefix_num = 0;
    for (char c : string)
    {
        if (c >= '0' && c <= '9') prefix_num++;
    }
    std::cout << prefix_num << std::endl;
    return string.replace(0, prefix_num, "");
}

template<class CLS>
auto Foo(const CLS& cls) -> void*
{
    auto name = std::string(typeid(cls).name());
    CleanNumberPrefix(name);
    void* c = (void*) ObjectFactory::createObject(name);
    return (void*) c;
}

int main()
{
    TestJson::Run();
//    TestSync::Run();
//    TestAsync::Run();
//    TestLambda::Run();
    return 0;
}
