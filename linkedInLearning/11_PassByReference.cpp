// Pass by refernece
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"

using namespace std;

// function prototype
void PrintHBD(string name, uint& age);

int main()
{
    uint globalAge = 0;

    cout << "Enter your age\n";
    cin >> globalAge;
    cout << "1. Your age is = " << globalAge << endl;    
    PrintHBD("Vipul", globalAge);
    cout << "2. Your age is = " << globalAge << endl;  

    return 0;
}

// function header
void PrintHBD(string name, uint& age)
{
    cout << "Happy birthday," << name <<"\n";
    age += 10;
}