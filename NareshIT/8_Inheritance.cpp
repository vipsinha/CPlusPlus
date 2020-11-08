// Date: 2020-04-04
// - Inheritance
// - Types of inheritance

// - Old class is refer as super class or base class
// - New class is refer as sub class or derived class
// - It provides the feature of reusability and extensibility
// - When a class is base and derived class, then that class is called intermidiate class
// - class derivedclass : pub/pri/pro baseclass()
// - : is inheritance operator
// - pub/pri/pro - visibility mode
// - derived class size is sum of base class and derived call memebers
// - Empty class will have size of 1 byte
// - if class is derived as public, then the private, public and protected 
//              will become not available, public and protected
// - if class is derived as private, then the private, public and protected 
//              will become not available, private and private
// - When data member is protected, then the data is accessed in base class and immidiately derived class
// - Above statement also depend on the visibility mode
// - Types of inheritance: Single level, Multi level, Multiple, Hybrid/ Multipath, Hierarhical
// - https://www.geeksforgeeks.org/inheritance-in-c/

#include<iostream>
using namespace std;

class BaseClassA
{
    private:
        int BaseClassAData;
    protected:
        int BaseClassAProtectedData;
    public:
        void getBaseClassAData();
        void printBaseClassAData();
};

class BaseClassB
{
    private:
        int BaseClassBData;
    public:
        void getBaseClassBData();
        void printBaseClassBData();
};

class DerivedClassA : public BaseClassA
{
    private:
        int DerivedClassAData;
    public:
        void getDerivedClassAData();
        void printDerivedClassAData();
};

class DerivedClassB : private BaseClassA
{
    private:
        int DerivedClassBData;
    public:
        void getDerivedClassBData();
        void printDerivedClassBData();
};

class DerivedClassC : public BaseClassA, public BaseClassB
{
    private:
        int DerivedClassCData;
    public:
        void getDerivedClassCData();
        void printDerivedClassCData();
};


class DerivedClassD : public DerivedClassC
{
    private:
        int DerivedClassDData;
    public:
        void getDerivedClassDData();
        void printDerivedClassDData();
};

class DerivedClassE : public BaseClassA
{
    private:
        int DerivedClassEData;
    public:
        void getDerivedClassEData();
        void printDerivedClassEData();
};

class DerivedClassF : public BaseClassA
{
    private:
        int DerivedClassFData;
    public:
        void getDerivedClassFData();
        void printDerivedClassFData();
};


class DerivedClassG : public DerivedClassF, public DerivedClassE 
{
    private:
        int DerivedClassGData;
    public:
        void getDerivedClassGData();
        void printDerivedClassGData();
};

void BaseClassA::getBaseClassAData()
{
    cout << "In Base class A\n";
    cout << "Enter the data\n";
    cin >> BaseClassAData;
}

void BaseClassA::printBaseClassAData()
{
    cout << "The base class A data is : " << BaseClassAData << endl;
}

void BaseClassB::getBaseClassBData()
{
    cout << "In Base class B\n";
    cout << "Enter the data\n";
    cin >> BaseClassBData;
}

void BaseClassB::printBaseClassBData()
{
    cout << "The base class B data is : " << BaseClassBData << endl;
}

void DerivedClassA::getDerivedClassAData()
{
    cout << "In Derived class A\n";
    cout << "Enter the data\n";
    cin >> DerivedClassAData;
}

void DerivedClassA::printDerivedClassAData()
{
    cout << "The derived class A data is : " << DerivedClassAData << endl;
    // private class member can be accessed here
}

void DerivedClassB::getDerivedClassBData()
{
    cout << "In Private Derived class B\n";
    cout << "Enter the data\n";
    cin >> DerivedClassBData;
    // private class member can not be accessed here
    //getclassBData();
}

void DerivedClassB::printDerivedClassBData()
{
    cout << "The private derived class B data is : " << DerivedClassBData << endl;
    // private class member can not be accessed here
    //printclassBData();
}


void DerivedClassC::getDerivedClassCData()
{
    cout << "In Private Derived class C\n";
    cout << "Enter the data\n";
    cin >> DerivedClassCData;
    // private class member can not be accessed here
    //getclassCData();
}

void DerivedClassC::printDerivedClassCData()
{
    cout << "The private derived class C data is : " << DerivedClassCData << endl;
    cout << "The base class A protected data is : " << BaseClassAProtectedData << endl;
    // private class member can not be accessed here
    //printclassCData();
}

void DerivedClassD::getDerivedClassDData()
{
    cout << "In Private Derived class D\n";
    cout << "Enter the data\n";
    cin >> DerivedClassDData;
}

void DerivedClassD::printDerivedClassDData()
{
    cout << "The private derived class D data is : " << DerivedClassDData << endl;
    cout << "The base class A protected data is : " << BaseClassAProtectedData;
}

void DerivedClassE::getDerivedClassEData()
{
    cout << "In Private Derived class E\n";
    cout << "Enter the data\n";
    cin >> DerivedClassEData;
}

void DerivedClassE::printDerivedClassEData()
{
    cout << "The private derived class E data is : " << DerivedClassEData << endl;
    cout << "The base class A protected data is : " << BaseClassAProtectedData;
}

void DerivedClassF::getDerivedClassFData()
{
    cout << "In Private Derived class F\n";
    cout << "Enter the data\n";
    cin >> DerivedClassFData;
}

void DerivedClassF::printDerivedClassFData()
{
    cout << "The private derived class F data is : " << DerivedClassFData << endl;
    cout << "The base class A protected data is : " << BaseClassAProtectedData << endl;
}

void DerivedClassG::getDerivedClassGData()
{
    cout << "In Private Derived class G\n";
    cout << "Enter the data\n";
    cin >> DerivedClassGData;

    getDerivedClassFData();
    getDerivedClassEData();
}

void DerivedClassG::printDerivedClassGData()
{
    cout << "The private derived class G data is : " << DerivedClassGData << endl;
   // cout << "The base class A protected data is : " << BaseClassAProtectedData;
   printDerivedClassFData();
   printDerivedClassEData();
}

int main()
{
    DerivedClassA DerObjA;
    DerivedClassB DerObjB;
    DerivedClassC DerObjC;
    DerivedClassD DerObjD;
    DerivedClassG DerObjG;

    cout << "## Single inheritane - Public ##\n";
    // If both derived and base class has same name, then the derived class function name is called
    DerObjA.getBaseClassAData();
    DerObjA.printBaseClassAData();
    DerObjA.getDerivedClassAData();
    DerObjA.printDerivedClassAData();

    cout << "## Single inheritane - Private ##\n";
    // This is not allowed,as this is private
    //DerObjB.getclassAData();
    //DerObjB.printclassAData();

    // This allowed
    DerObjB.getDerivedClassBData();
    DerObjB.printDerivedClassBData();

    cout << "## Multiple inheritane - Public ##\n";
    DerObjC.getBaseClassAData();
    DerObjC.printBaseClassAData();
    DerObjC.getBaseClassBData();
    DerObjC.printBaseClassBData();
    DerObjC.getDerivedClassCData();
    DerObjC.printDerivedClassCData();

    cout << "## Multilevel inheritane ##\n";    
    // DerObjD.getBaseClassAData();
    // DerObjD.printBaseClassAData();
    // DerObjD.getBaseClassBData();
    // DerObjD.printBaseClassBData();
    // DerObjD.getDerivedClassCData();
    // DerObjD.printDerivedClassCData();
    DerObjD.getDerivedClassDData();
    DerObjD.printDerivedClassDData();

    cout << "## Hierarchical inheritane ##\n";        
    // If one base class is used in two different derived class
    // This can be seen in above code as well. As Base class A is used in many Dervied classes

    cout << "## Hybrid inheritane ##\n";
    DerObjG.getDerivedClassGData();
    DerObjG.printDerivedClassGData();

    return (0);
}