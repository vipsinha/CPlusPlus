// Date: 2020-04-01
// - Constructors and destructors
// - Constructor overloading
// - Constructor called inside constructor
// - Copy constructor
// - Default constructor with default argument
// - Constructor & Destructor visualization with static member

#include <iostream>
using namespace std;

class constDest
{
    private:
        /* Data memebers */
        // Data values can not be initialzed 
        int a;
        float b;
        char c;
    public:
        // constructor
        // should defined in public area
        // used to initilize the private values
        // return type should be anything. It does not return anything
        // Arguments or parameters are allowed
        // Hence, constructor can be overloaded
        // constructors does not take part in inhertiance
        // They are implicit calls to new and delete. hence invoked automatically
        // Address of constuctors can not be checked
        // constructor are created only once, when object is created
        // This is default constructor, as it has no argument or zero parameterized
        constDest();

        // Construcor overloading
        // polymorphic feature of C++
        // Paramertized constructor
        constDest(int a);

        constDest(int a, float b);

        constDest(int a, float b, char);

        // Destructors
        // It releases the memory like delete
        // Should be declared in public
        // Should not have any argument
        // No return type
        // It calls new and delete operator
        ~constDest();

        // Copy constructor
        // It is used to initilize current object value with other object value
        // It create a copy or instance of an object
        // It has refernce type parameters
        // It has class type parameters
        constDest(constDest &old);
};

class constDestDefArg
{
    private:
        int a,b;
    public:
        constDestDefArg(int x, int y);
};

class constDestStaticStatus
{
    private:
        static int objectCount;
    public:
        // constructor
        constDestStaticStatus();
        // destructor
        ~constDestStaticStatus();
};

constDest::constDest()
{
    cout << "In default constructor\n";
    a = 10;
    b = 20;
    c = 'A';
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;
}

constDest::constDest(int a)
{
    cout << "In constructor overloading with 1 argument\n";
    this->a = a;
    b = 30;
    cout << "a,b values are " << a << " and "<< b << endl;
}

constDest::constDest(int a, float b)
{
    cout << "In constructor overloading with 2 argument\n";
    this->a = a;
    this->b = b;
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;
}

constDest::constDest(int a, float b, char c)
{
    cout << "In constructor overloading with 3 argument\n";
    constDest(a,b);
    this->c = c;
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;
}

constDest::~constDest()
{
    cout << "In destructor\n";
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;
}

constDest::constDest(constDest &old)
{
    cout << "In copy constructor\n";

    cout << "Before copy\n";
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;

    a = old.a;
    b = old.b;
    c = old.c;

    cout << "After copy\n";
    cout << "a,b,c values are " << a << "\t"<< b << "\t"<< c << endl;
}

constDestDefArg::constDestDefArg(int x=1, int y=2)
{
    cout << "Constructor with default argument\n";
    a = x;
    b = y;
    cout << "x,y values are " << a << "\t"<< b << endl;
}

constDestStaticStatus::constDestStaticStatus()
{
    cout << " constDestStaticStatus: In constructor\n";
    objectCount++;
    cout << "Object added: " << objectCount << endl;
}

constDestStaticStatus::~constDestStaticStatus()
{
    cout << " constDestStaticStatus: In destructor\n";
    cout << "Object deleted: " << objectCount << endl;
    objectCount--;
}

int constDestStaticStatus::objectCount = 0;

int main()
{
    cout <<  "## Constructors and Destructors ##\n";
    constDest cD1, cD2(40), cD3(50,1.5), cD4(60,2.5,'X');

    // To check the sequence of the operation enable below code
    //constDest cD5;
    // cout << "I am in main\n";

    cout << "## Copy Constructor ##\n";
    constDest cD6, cD7(cD6);

    constDestDefArg cDDA1(88);

    cout << "## Visualization of constructor and destructor ##\n";
    constDestStaticStatus cDSS_1, cDSS_2, cDSS_3;
}