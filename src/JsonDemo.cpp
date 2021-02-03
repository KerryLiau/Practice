//
// Created by User on 2021/1/4.
//

#include <vector>
#include <sstream>
#include "iostream"
#include "../third_party_lib/json/CJsonObject/CJsonObject.hpp"

class TestJson
{
public:
    static void Run()
    {
        std::cout << "============================= " << "Test Json" << " =============================" << std::endl;
        std::cout << "Test Json" << std::endl;
        neb::CJsonObject json_object(R"({"Hello":["World", "!"]})");
        auto key = std::string("Hello");
        std::cout << key + " " << clear_string(json_object[key][0].ToString()) << clear_string(json_object[key][1].ToString())  << std::endl;
        std::cout << "is array: " << json_object[key].IsArray() << std::endl;
        std::cout << "list size: " << json_object[key].GetArraySize() << std::endl;
        auto name_key = std::string("My name is: ");
        auto name = std::string("Kerry");
        json_object.Add(name_key, name);
        std::cout << "Whole JSON string: " << json_object.ToString() << std::endl;
        neb::CJsonObject json_array;
        json_array.Add(key);
        json_array.Add(name_key);
        json_array.Add(name);
        std::cout << "JSON array string: " << json_array.ToString() << std::endl;
        std::cout << "pretty JSON array: " << '\n' << PrettyPrint(&json_array) << std::endl;
        std::cout << "pretty JSON object: " << '\n' << PrettyPrint(&json_object) << std::endl;
        auto json_str = R"(
        {
            "name":"Marry"
        }
        )";
        auto marry_json = neb::CJsonObject(json_str);
        std::cout << "marry json: \n" << marry_json.ToFormattedString() << std:: endl;
        std::cout << "marry pretty json: \n" << PrettyPrint(&marry_json) << std:: endl;
    }

private:
    static std::string clear_string(std::string str)
    {
        long length = str.length();
        return str.replace(0, 1, "").replace(length - 2, length - 1, "");
    }

    static auto PrettyPrint(neb::CJsonObject&& jsonObject) -> std::string
    {
        return PrettyPrint(&jsonObject, 2);
    }

    static auto PrettyPrint(neb::CJsonObject&& jsonObject, const int& spacePerIndent) -> std::string
    {
        auto space = std::string();
        for (auto i = 0; i < spacePerIndent; ++i) {
            space += " ";
        }
        std::stringstream result;
        auto json_str = jsonObject.ToString();
        auto level = 0;
        auto isChar = false;
        try
        {
            for (char next : json_str)
            {
                switch (next)
                {
                    case '"':
                        if (isChar) isChar = false;
                        else isChar = true;
                        result << next;
                        break;
                    case '{':
                    case '[':
                        result << next;
                        if (!isChar)
                        {
                            level++;
                            result << '\n';
                            NewLine(result, level, space);
                        }
                        break;
                    case '}':
                    case ']':
                        if (!isChar)
                        {
                            level--;
                            result << '\n';
                            NewLine(result, level, space);
                        }
                        result << next;
                        break;
                    case ',':
                        result << next;
                        if (!isChar)
                        {
                            result << '\n';
                            NewLine(result, level, space);
                        }
                        break;
                    case ':':
                        result << next << ' ';
                        break;
                    default:
                        result << next;
                        break;
                }
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return "";
        }
        return result.str();
    }

    static void NewLine(std::stringstream& result, int& level, const std::string& space)
    {
        for (auto i = 0; i < level; ++i)
        {
            result << space;
        }
    }


};