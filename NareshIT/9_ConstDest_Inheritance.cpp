// Date: 2020-04-08
// - Constructor in inhertiance
// - Destructor in inheritance
// - Parameterised constructor

#include<iostream>
using namespace std;

// - Base class constructor automatically binded with the derived class constructor
// - Base class constructor is created first
// - Base class constructor has more priority
// - Derived class destructor is called
// - Base class destructor is called
// - It works like stack LIFO
// - In parameterised constructor
// - Base class should have to call a default constructor
// - Base class parameterised constructor should be invoked inside dervied class parameterised constructor
// - Base class parameterised construcotr should be the first statement inside the derived class constructor
// - Only one base class constructor is called inside the derived class constructor
 
class baseClassA
{
    private:
        int baseClassAData;
    public:
        // Default construtor
        baseClassA();  
        baseClassA(int Data);
        ~baseClassA();
};

class derivedClassA : public baseClassA
{
    private:

    public:
        // base class constructor automatically added by compiler 
        derivedClassA();
        derivedClassA(int Data);
        ~derivedClassA();
        // base class destructor automatically added by compiler 
};

baseClassA::baseClassA()
{
    cout << "Base class A - default constructor\n";
}

baseClassA::baseClassA(int a)
{
    cout << "Base class A - parmeterised constructor\n";
}

baseClassA::~baseClassA()
{
    cout << "Base class A - default destructor\n";
}

derivedClassA::derivedClassA()
{
    cout << "Derived class A - default constructor\n";
}

derivedClassA::derivedClassA(int a)
{
    baseClassA(2);
    cout << "Derived class A - parmeterised constructor\n";
}

derivedClassA::~derivedClassA()
{
    cout << "Derived class A - default destructor\n";
}

int main()
{
    derivedClassA DerObjA;
    derivedClassA DerObjB(1);

    return(0);
}