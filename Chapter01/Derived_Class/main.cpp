// Derived_Class.cbp
#include <iostream>

using namespace std;

class Animal
{
private:
    string m_name;

public:
    Animal(string name) : m_name(name)
    {

    }

    // The interface that has to be implemented
    // in derived class
    virtual string MakeSound() = 0;

    string GetName()
    {
        return m_name;
    }
};

class Dog : public Animal
{
public:
    // Forward the constructor arguments
    Dog(string name) : Animal(name) {}

    // here we implement the interface
    string MakeSound() override
    {
        return "woof-woof!";
    }

};

int main()
{
    Dog dog = Dog("Bulldog");

    cout << dog.GetName() << " is barking: ";
    cout << dog.MakeSound() << endl;

    return 0;
}
