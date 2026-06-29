// d2mcpp: https://github.com/mcpp-community/d2mcpp
// license: Apache-2.0
// file: dslings/cpp11/11-inherited-constructors-0.cpp
//
// Exercise: cpp11 | 11 - inherited constructors | Inherited Constructors
//
// Tips: Based on compiler output and error messages, add required constructors and understand basic usage of inherited constructors
//
// Docs:
//   - https://en.cppreference.com/w/cpp/language/using_declaration.html#Inheriting_constructors
//   - https://mcpp-community.github.io/d2mcpp/cpp11/11-inherited-constructors.html
//
// Auto-Checker command:
//
//   d2x checker inherited-constructors
//

#include <d2x/cpp/common.hpp>

#include <iostream>
#include <string>

class ObjectBase
{
public:
    ObjectBase(int x) { std::cout << "ObjectBase::ObjectBase(int): " << x << std::endl; }
    ObjectBase(double x) { std::cout << "ObjectBase::ObjectBase(double): " << x << std::endl; }

    ObjectBase(int x, double y)
    {
        std::cout << "ObjectBase::ObjectBase(int, double): " << x << ", " << y << std::endl;
    }

    void info() const { std::cout << "ObjectBase: " << this << std::endl; }
};

class ObjectA : public ObjectBase
{
public:
    ObjectA(int x) : ObjectBase(x) { std::cout << "ObjectA::ObjectA(int)" << std::endl; }
    ObjectA(double y) : ObjectBase(y) { std::cout << "ObjectA::ObjectA(double)" << std::endl; }

    ObjectA(int x, double y) : ObjectBase(x, y) { std::cout << "ObjectA::ObjectA(int, double)" << std::endl; }

    void tips_a() const
    {
        std::cout << "ObjectA: add constructors to ObjectA" << std::endl;
    }
};

class ObjectB : public ObjectBase
{
public:
    using ObjectBase::ObjectBase;
    void tips_b() const
    {
        std::cout << "ObjectB: add new constructors to ObjectBase" << std::endl;
    }
};

int main()
{ // Do not directly modify the code in the main function

    ObjectBase obj1(1), obj2(2.0), obj3{3, 4.0};
    ObjectA a1(11), a2(22.0), a3{33, 44.0};
    ObjectB b1(111), b2(222.0), b3{333, 444.0};

    obj1.info();
    a1.info();
    b1.info();

    a1.tips_a();
    b1.tips_b();

    return 0;
}