// Date: 2020-04-02
// - Static data members
// - Static member functions
// - Constant data members
// - Constant member function or accessers functions

#include<iostream>
using namespace std;

class classA
{
    private:
        /* Data member */
        /* Static data member */
        // Now it is class member, because of static 
        // Now it can be accessed by all object of class
        // It can be accessed by the class name
        // Static member is automatically initiased with zero
        // It has been declared here
        // It is created in data segment
        // One data can be shared between all the objects of a class
        int testData;
        static int classAData;
        const int constData;
    public:
        void printData();

        // Static data functions work only on static data members
        // Static data functions doesn't work on non-static data members
        // They are never assocaited with THIS operator
        // They can be called by class name or object name
        // They should not be constant or volatile or virtual
        static void staticDataFunction(int x, int y);

        // procedure to initialize the constant data member
        // constant member or any member can not be initialized in private section
        classA():constData(20)
        {
            testData = 10;
            cout << "In constructor with constant data : " << constData << endl;
        }

        // A constant function where the data can not modified
        // Data can only be read
        // CONST member function thin will work only if it is defined inside the class
        // else it will not work
        // variable state is not changed, it is called immutable objects and it is possible only with
        // accessor functions
        #if 0
        const void showData();
        #endif
        void showData() const
        {
            // modify of data is not allowed here
            classAData += 111;
            // Below line will give error
            //testData += 111;
            cout << "Const function-Data member are : " << classAData << ", " << testData << ", " << constData << endl;
        }

};

void classA::printData()
{
    cout << "Now-Static member data value is : " << classAData << endl;
    classAData += 10;
    cout << "Update-Static member data value is : " << classAData << endl;
}

void classA::staticDataFunction(int x, int y)
{
    if(x>y)
        cout << "X is bigger\n";
    else if (x<y)
    {
        /* code */
        cout << "Y is bigger\n";
    }
    else
    {
        /* code */
        cout << "X and Y are equal\n";
    }

    // Static member can be accessed
    cout << "Static member data: " << classAData << endl;
    // But non static member will give error
    //cout << "Non static member will give error :" << testData << endl;
}

#if 0
const void classA::showData()
{
    // modify of data is not allowed here
    // Below line will give error
    classAData += 111;
    testData += 111;
    cout << "Const function-Data member are : " << classAData << ", " << testData << ", " << constData << endl;
}

#endif
// Static should be defined outside class
int classA::classAData = 10;

int main()
{
    classA fCA_1, fCA_2;
    classA fCA_3;
    cout << "FCA 1\n";
    fCA_1.printData();
    cout << "FCA 2\n";
    fCA_2.printData();
 
    // Static member can be accessed by using the class, if
    // static member is defined in public section using ::

    cout << "Static data function\n";
    fCA_3.staticDataFunction(7,10);
    // Only allowed with the static member function
    classA::staticDataFunction(10,7);

    // calling a constant function
    fCA_3.showData();

    return(0);
}