// Date: 2020-03-31
// - Default argument
// - Class object as argument
// - Class object as return and argument

#include <iostream>
using namespace std;

class defArgument
{
    private:
        /* Data members */
    public:
        /* Member functions */
        int sum(int x, int y, int z);

};

class classAsArgument
{
    private:
        int data;
    public:
        void setData();
        void printData();
        void findBigger(classAsArgument obj);
        classAsArgument sumClassObject(classAsArgument obj);
};

int defArgument::sum(int x=10, int y=20, int z=30)
{
    return(x+y+z);
}

void classAsArgument::setData()
{
    cout << "Enter the value\n";
    cin >> data;
}

void classAsArgument::printData()
{
    cout << "The Data is = " << data << endl;
}

void classAsArgument::findBigger(classAsArgument obj)
{
    if(this->data > obj.data)
    {
        cout << "Object 1 is bigger\n";
    }
    else if (this->data < obj.data)
    {
        /* code */
        cout << "Object 2 is bigger\n";
    }
    else
    {
        /* code */
        cout << "Both Object are equal\n";
    }
}

classAsArgument classAsArgument::sumClassObject(classAsArgument objectData)
{
    classAsArgument retObject;

    retObject.data = this->data + objectData.data;
    return(retObject);
}

int main()
{
    defArgument defArg;
    classAsArgument objectData_1, objectData_2, objectData_3;

    int output = 0;

    cout << "## Default argument ##\n";
    cout << "a=100,b=200,c=300\n";
    output = defArg.sum(100,200,300);
    cout << "Output 1 is = " << output << endl;

    cout << "a=100,b=200\n";
    output = defArg.sum(100,200);
    cout << "Output 2 is = " << output << endl;

    cout << "a=100\n";
    output = defArg.sum(100);
    cout << "Output 3 is = " << output << endl;

    cout << "None\n";
    output = defArg.sum();
    cout << "Output 4 is = " << output << endl;

    cout << "## Class object as argument ##\n";
    objectData_1.setData();
    objectData_2.setData();

    objectData_1.findBigger(objectData_2);

    cout << "## Class object as Return Argument ##\n";
    objectData_3 = objectData_1.sumClassObject(objectData_2);
    objectData_3.printData();

    return(0);
}