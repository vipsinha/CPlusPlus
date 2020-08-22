// Date: 2020-04-12
// Virtual class
// Pure virtual function
// Abstract base class
// Virtual destructors (There is no virtual constructor)
// Local class

// - A pure virtual function is one which is declared in base class, but has no defination
//   related to base class. But then they are redifined in derived classes
// - A pure virtual function is also called do nothing function
// - A class which contains pure virtual function is called abstract base class
// - Abstract class is used to create a base class pointer to create time polymorphism
// - Abstract base class is not used to declare objects
// - Local class is one which is defined inside the member function. Hence function defination is 
//   not allowed outside the class. Object calling and creation also inside the function
// - Local class does not allow static data members, but it allows static member functions
// - Local class are able to access global variables 

#include<iostream>
using namespace std;

int localGlobalData = 100;

// - Abstract base class 
class baseClassA
{
    private:
        int baseClassAData;
    protected:
        float baseClassADataProtected;
    public:
        // base class constructor
        baseClassA();
        // base class destructor
        ~baseClassA();
        void printBaseClassA();
        // pure virtual function
        // Function is declared with virtual key word and initialised with zero
        // Initializing with other values will give error 
        virtual void printVirtualFunction() = 0;
};

// Adding virtual name , will renove the duplicacy of multiple 
// definaion in derived class C
class derivedClassA : public virtual baseClassA
{
    private:
        int derivedClassAData;
    public:
        derivedClassA();
        ~derivedClassA();
        void printDerivedClassA();
        virtual void printVirtualFunction();
};

class derivedClassB : public virtual baseClassA
{
    private:
        int derivedClassBData;
    public:
        void printDerivedClassB();
        //virtual void printVirtualFunction();
};

class derivedClassC : public derivedClassA, public derivedClassB
{
    private:
        int derivedClassCData;
    public:
        void printDerivedClassC();
};

void localFunction()
{
    class localClassA
    {
        private:
            int localGlobalData;
        public:
            void printLocalClassData()
            {   
                localGlobalData = 300;
                cout << "In Local class function\n";
                cout << "Local data : LocalGlobal variable: "<< localGlobalData << endl;
                cout << "Global data : LocalGlobal variable: "<< ::localGlobalData << endl;
            }
    };

    // It can not be defined outside the function, hence local class 
    // void localClassA::printLocalClassData()
    // {    
    //     cout << "Local data : LocalGlobal variable: "<< localGlobalData << endl;
    //     cout << "Global data : LocalGlobal variable: "<< ::localGlobalData << endl;
    // }

    // Both object creation and calling needs to be done inside the function. It is mandatory
    localClassA LocalClassObjA;
    LocalClassObjA.printLocalClassData();
}

baseClassA::baseClassA()
{
    cout << "In base class A constructor\n";
}

baseClassA::~baseClassA()
{
    cout << "In base class A destructor\n";
}

void baseClassA::printBaseClassA()
{
    int localGlobalData = 200;
    cout << "Base class A data : " << baseClassAData << endl;
    cout << "Enter the data for protected base class A data\n";
    cin >> baseClassADataProtected;
    cout << "Local data : LocalGlobal variable: "<< localGlobalData << endl;
    cout << "Global data : LocalGlobal variable: "<< ::localGlobalData << endl;
}

derivedClassA::derivedClassA()
{
    cout << "In derived class A constructor\n";
}

derivedClassA::~derivedClassA()
{
    cout << "In derived class A destructor\n";
}

void derivedClassA::printDerivedClassA()
{
    cout << " Derived class A\n";
    printBaseClassA();
}

void derivedClassA::printVirtualFunction()
{
    baseClassADataProtected = baseClassADataProtected * 0.5;
    cout << "In virtual derived class A and data is: " << baseClassADataProtected << endl;
}

void derivedClassB::printDerivedClassB()
{
    cout << " Derived class B\n";
    printBaseClassA();
}

// Pure virtual function can be used in many classes
// Below one is commented, because of the hybrid inheritance

// void derivedClassB::printVirtualFunction()
// {
//     baseClassADataProtected = baseClassADataProtected * 1.5;
//     cout << "In virtual derived class B and data is: " << baseClassADataProtected << endl;
// }

void derivedClassC::printDerivedClassC()
{
    cout << " Derived class C\n";
    // Here we will get error, as the derived class A and B is derived from same base class
    // hence derived class C is facing dilemma from where to get the base class A defination
    // So, to solve this issue make derived class A and B as virtual

    // This issue is caused in hybrid inheritance
    printBaseClassA();
}

int main()
{
    // This is not allowed, as it is abstract class
    // baseClassA baseObjA;
    derivedClassC DerObjC;
    // Here we will get error, as the derived class A and B is derived from same base class
    // hence derived class C is facing dilemma from where to get the base class A defination
    // So, to solve this issue make derived class A and B as virtual

    // This issue is caused in hybrid inheritance
    // This happens due to duplicacy
    // Hence add virtual keyword
    DerObjC.printBaseClassA();
    DerObjC.printVirtualFunction();

    // Base class pointer object, which is assigned with derived class
    // LIFO base and derived class constructor and destructor
    baseClassA *BaseClassObj = new derivedClassA;
    delete BaseClassObj;

    // Local class function calling
    localFunction();

    return (0);
}