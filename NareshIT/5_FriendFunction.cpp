// Date: 2020-04-01
// - Friend function
// - Friend function shared between two classes 
// - Composition (reusibility of class)
// - A class can be defined as private member of another class

#include<iostream>
using namespace std;

// - A friend function is one which can access my private data, even though
//   it doesn't have access
// - It is non-member of class
// - There should be declaration within the class with friend keyword
// - Friend defination should be outside the class without friend keyword
// - Friend function can be declared in any number of classes
// - They have object as arguments, so that it can access private variables
// - They are non members, hence . operator is not required

// This declaration is required, then only class B can be seen in class A
class classB;

class classA
{
private:
    /* data member */
    int classAData;
public:
    classA(/* args */);
    ~classA();
    void getData();
    // Friend function
    friend void friendFunc(classA Object);
    // Friend function shared between two classes
    friend void friendBigData(classA ObjectA, classB ObjectB);
};

class classB
{
private:
    /* data member */
    int classBData;
public:
    classB(/* args */);
    ~classB();
    void getData();
    // Friend function shared between two classes
    friend void friendBigData(classA ObjectA, classB ObjectB);
};

// Friend class allows reusability of the class is called composition
// Composition is not same as inheritance, as composition doesnot allow the extensionsibility
// With inheritance we can extend the functionality
// Container of the friend class sharing
// Container and Contained together is called compostion
class classC
{
private:
    /* data member */
    int classCData;
public:
    void getData();
    // Friend class
    // Remeber the declaration
    friend class classD;
};

// Contained of the friend class sharing
// Container and Contained together is called compostion
class classD
{
private:
    /* data member */
    int classDData;
    // Another example of composition
    classC friendClassC; 
public:
    void getData();
    void friendClass(classC);
    void friendClassAccess();
};

classA::classA(/* args */)
{
    cout << "In Friend class default constructor\n";
    classAData = 100;
    cout << "Data in constructor = " << classAData << endl;
}

classA::~classA()
{
    cout << "In friend class A default destructor\n";
}

void classA::getData()
{
    cout << "Enter the data\n";
    cin >> classAData;
}

void friendFunc(classA Object)
{
    cout << "In friend function\n";
    Object.classAData += 10;
    cout << "Data in friend function = " << Object.classAData << endl;
}

classB::classB(/* args */)
{
    cout << "In Friend class default constructor\n";
    classBData = 100;
    cout << "Data in constructor = " << classBData << endl;
}

classB::~classB()
{
    cout << "In friend class B default destructor\n";
}

void classB::getData()
{
    cout << "Enter the data\n";
    cin >> classBData;
}

void classC::getData()
{
    cout << "Enter the data\n";
    cin >> classCData;
}

void classD::getData()
{
    cout << "Enter the data\n";
    cin >> classDData;
}

void classD::friendClass(classC Object)
{
    cout << "Class C data = " << Object.classCData << endl;
    cout << "Class D data = " << classDData << endl;
}

void classD::friendClassAccess()
{
    // no need to this class declaration, as it is already decalred in private 
    //classC cAccess;
    // New instance of the class is created, hence it will contain the garbage value
    //cout << "class C data accessed at Class D = " << cAccess.classCData << endl;
    cout << "class C data accessed at Class D = " << friendClassC.classCData << endl;
}

void friendBigData(classA ObjectA, classB ObjectB)
{
    if(ObjectA.classAData > ObjectB.classBData)
        cout << "Class A data is bigger\n";
    else if (ObjectA.classAData < ObjectB.classBData)
        cout << "Class B data is bigger\n";
    else
        cout << "Both classes are equal\n";
}

int main()
{
    classA fCA;
    classB fCB;
    classC fCC;
    classD fCD;

    fCA.getData();
    fCB.getData();
    fCC.getData();
    fCD.getData();

    friendFunc(fCA);

    friendBigData(fCA,fCB);

    fCD.friendClass(fCC);
    fCD.friendClassAccess();

    return(0);
}