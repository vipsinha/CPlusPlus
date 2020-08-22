// Date: 2020-04-18
// - Exception Handling

#include<iostream>
using namespace std;

// Exception handling is to protect the system
// Try - error causing program
// Throw - through is going to to throw some value
// Catch -  it is going to catch the error and provide the solution
// Before passing the object from throw to catch block, the destructor will execute, 
// if object is created inside the try block

class classA
{
    private:
        int dataA, dataB;
    public:
        classA();
        ~classA();
        void getData();
        void funcExcpetion();
};

classA::classA()
{
    cout << "In Constructor\n";
}

classA::~classA()
{
    cout << "In destructor\n";
}

void classA::getData()
{
    cout << "Enter the A & B value: \n";
    cin >> dataA >> dataB;
}

// After throw, the next lines will not be executed
void classA::funcExcpetion(void)
{
    if(dataB == 0){
        throw "Error: Division by zero";
        cout << "After Catch block\n";}
    else if(dataA == 0 && dataB != 0)
        throw 10;
    cout << "The division is: " << dataA/dataB << endl;
}

int main()
{
    try
    {
        /* code */
        classA ObjA;
        ObjA.getData();
        ObjA.funcExcpetion();
    }
    catch(const char* e)
    {
        cerr << e << '\n';
    }
    // Default exception 
    catch(...)
    {
        cerr << "Default catch block\n";
    }

    cout << "## Nested Try ##\n";

    try
    {
        cout << "In try outside block\n";
        try
        {
            cout << "In try inside block\n";
            throw 10;
        }
        catch(const int x)
        {
            std::cerr << "Inside inner throw block" << '\n';
            throw "a";
        }   
    }
    catch(...)
    {
        std::cerr << "Inside outer throw block" << '\n';
    }
 
    return(0);
}