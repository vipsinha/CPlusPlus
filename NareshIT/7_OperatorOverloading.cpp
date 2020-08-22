// Date: 2020-04-03
// - Operator overloading
// - Overloading unary operator
// - Overloading using the friend function
// - Operator overloading for extraction and insertion operators

#include<iostream>
#include<string.h>
using namespace std;

// ::, . , .* operator can not overloaded
// sizeof(), ?, ! operator can't be oveloaded
// friend function does not work with '=', '()', "[]" , "->"


class classA
{
    private:
        /* Data members */
        int classAData;
        char classAString[100];
    public:
        /* Member functions */
        void getData();
        void getString();
        void printData();
        void printString();
        // Overload == operator
        void operator==(classA Object);
        // Overload + operator
        classA operator+(classA Object);
        // Unary operator overloading
        // int is required inside paranthesis for x--
        void operator--(int);
        // int is not required inside paranthesis for --x
        void operator--();
        // friend function for operator overloading
        friend void operator-(classA &Object);
        // Operator overloading of extraction & insertion operator
        friend void operator>>(istream &in, classA &Object);
        friend void operator<<(ostream &out, classA &Object);
};

void classA::operator==(classA Object)
{
    if(Object.classAData == classAData)
        cout << "Both object are equal\n";
    else
    {
        /* code */
        cout << "Both object are not equal\n";
    }
}

classA classA::operator+(classA Object)
{
    strcat(classAString, " ");
    strcat(classAString, Object.classAString);
    //strcpy(fCA.classAString, Object.classAString);

    return(*this);
}

void classA::operator--(int)
{
    cout << "Post decrement\n";
    classAData--;
}

void classA::operator--()
{
    cout << "Pre decrement\n";
    classAData--;
}

void operator-(classA &Object)
{
    cout << "Negate the object\n";
    Object.classAData = -Object.classAData; 
}

void operator>>(istream &in, classA &Object)
{
    cout << "Get the data for >> overloading\n";
    in >> Object.classAData;
    in >> Object.classAString;
}

void operator<<(ostream &out, classA &Object)
{
    cout << "The data for << overloading\n";
    out << Object.classAData << ", ";
    out << Object.classAString << endl;
}

void classA::getData()
{
    cout << "Enter the data\n";
    cin >> classAData;
}

void classA::getString()
{
    cout << "Enter the String\n";
    cin >> classAString;
}

void classA::printString()
{
    cout << "The String is "<< classAString << endl;
}

void classA::printData()
{
    cout << "The data is "<< classAData << endl;
}

int main()
{
    classA fCA_1, fCA_2;
    classA fCA_3, fCA_4, fCA_5;
    classA fCA_6;
    classA fCA_7;
    classA fCA_8;

    fCA_1.getData();
    fCA_2.getData();

    fCA_1 == fCA_2;

    fCA_3.getString();
    fCA_4.getString();

    fCA_5 = fCA_3 + fCA_4;
    fCA_5.printString();

    fCA_6.getData();
    fCA_6--;
    fCA_6.printData();
    --fCA_6;
    fCA_6.printData();

    fCA_7.getData();
    -fCA_7;
    fCA_7.printData();

    cin >> fCA_8;
    cout << fCA_8;

    return(0);
}