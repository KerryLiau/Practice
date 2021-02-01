//
// Created by User on 2021/1/4.
//

#include <vector>
#include "iostream"
#include "../third_party_lib/json/CJsonObject/CJsonObject.hpp"

class TestJson
{
public:
    static void Run()
    {
        std::cout << "Test Json" << std::endl;
        neb::CJsonObject json_object(R"({"Hello":["World", "!"]})");
        std::string key = "Hello";
        std::cout << key + " " << clear_string(json_object[key][0].ToString()) << clear_string(json_object[key][1].ToString())  << std::endl;
        std::cout << "is array: " << json_object[key].IsArray() << std::endl;
        std::cout << "list size: " << json_object[key].GetArraySize() << std::endl;
    }

private:
    static std::string clear_string(std::string str)
    {
        long length = str.length();
        return str.replace(0, 1, "").replace(length - 2, length - 1, "");
    }
};