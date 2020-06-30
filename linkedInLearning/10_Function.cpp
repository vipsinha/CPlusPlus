// Funtion calling
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"

using namespace std;

// function prototype
void PrintHBD(void);

int main()
{
    
    int count = 3;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        //Calling statement
        PrintHBD();
    }
    
    cout << "Happy birthday in MAIN\n";
    return 0;
}

// function header
void PrintHBD(void)
{
    cout << "Happy birthday in FUNCTION\n";
}