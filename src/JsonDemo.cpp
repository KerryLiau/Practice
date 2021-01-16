//
// Created by User on 2021/1/4.
//

#include "iostream"
#include "../third_party_lib/json/CJsonObject/CJsonObject.hpp"

class TestJson
{
public:
    static void Run()
    {
        std::cout << "Test Json" << std::endl;
        neb::CJsonObject json_object(R"({"Hello":"World"})");
        std::cout << json_object["Hello"].ToString() << std::endl;
    }

private:
    static std::string to_string(neb::CJsonObject json)
    {
        return "";
    }
};