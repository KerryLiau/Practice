#ifndef _REFLECTION_
#define _REFLECTION_

// this file realize a simple reflection mechanism
// usage :
// 1 use the macro to Register the class REG_REFLECTION_CLASS(ClassName).
// 2 then you can create the instance like that
//   ClassName *instance = (ClassName*) ObjectFactory::createObject("ClassName");
// example :
//  REG_REFLECTION_CLASS(int);
//  int *i = (int*) ObjectFactory::createObject("int");

#include <stdlib.h>
#include <tr1/unordered_map>

typedef void* (*FactoryCreate_PTR) ();

std::tr1::unordered_map<std::string,FactoryCreate_PTR> g_creator_map;
template <class T>
class RegisterReflectionClass {
public:
    RegisterReflectionClass (std::string name,FactoryCreate_PTR ptr)
    {
        std::tr1::unordered_map<std::string,FactoryCreate_PTR>::const_iterator it = g_creator_map.find(name);
        if(it == g_creator_map.end()){
            g_creator_map[name] = ptr;
        }else{
            std::cout << "exit error : Class \"" << name << "\" has been registered before" << std::endl;
            exit (EXIT_FAILURE);
        }
    }
};

class ObjectFactory{
public:
    static void* createObject(std::string name)
    {
        void* obj;
        std::tr1::unordered_map<std::string,FactoryCreate_PTR>::const_iterator it = g_creator_map.find(name);
        if(it != g_creator_map.end()){
            obj = (it->second)();
            return obj;
        }
    }
};

#define REFLECTION_CLASS_CREATOR(class_name)    \
    void* class_name##_creator()        \
    {                        \
    class_name *tmp = new class_name();    \
    return (void*)tmp;            \
    }                        \

#define REG_REFLECTION_CLASS(class_name)                \
    REFLECTION_CLASS_CREATOR(class_name)                \
    RegisterReflectionClass<class_name> Reg##class_name(#class_name,class_name##_creator); \

#endif