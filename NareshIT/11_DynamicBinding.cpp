// Date: 2020-04-13
// Dynamic binding

#include<iostream>
using namespace std;

class baseClassA
{
    private:
        int baseClassAData;
    public:
        virtual void printData() = 0;
};

class derivedClassA : public baseClassA
{
    private:
        int derivedClassAData;
    public:
        void printData();
};

class derivedClassB : public baseClassA
{
    private:
        int derivedClassBData;
    public:
        void printData();
};

class derivedClassC : public baseClassA
{
    private:
        int derivedClassCData;
    public:
        void printData();
};

void baseClassA::printData()
{
    cout << "In Base class A\n";
}

void derivedClassA::printData()
{
    cout << "In Derived class A\n";
}

void derivedClassB::printData()
{
    cout << "In Derived class B\n";
}

void derivedClassC::printData()
{
    cout << "In Derived class C\n";
}

int main()
{
    baseClassA *baseClassPtr[3];
    int option;
    int length;
    int index;

    cout << "Enter the length of dynamic binding\n";
    cin >> length;

    for(index=0; index<length; index++)
    {
        cout << "Enter the option\n";
        cin >> option;        

        if(option == 1)
        {
            baseClassPtr[index] = new derivedClassA;
        }
        else if (option == 2)
        {
            /* code */
            baseClassPtr[index] = new derivedClassB;
        }
        else if(option == 3)
        {
            /* code */
            baseClassPtr[index] = new derivedClassC;
        }
        else
        {
            // Abstract base class can not be used 
            //baseClassPtr[index] = new baseClassA;
        }
        
    }

    cout << "Output\n";

    for(index=0; index<length;index++)
    {
        baseClassPtr[index] ->printData();
    }
    
    return(0);
}