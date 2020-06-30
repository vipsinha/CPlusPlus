// Mathematical instructions of a number
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"
#include "math.h"

using namespace std;

int main()
{
    float numQuant;

    cout << "Please enter the float number" << endl;
    cin >> numQuant;
    cout << "Ceiling of number = "  << ceil(numQuant) << endl;
    cout << "Floor of number = " << floor(numQuant) << endl;
    cout << "Absolute of number = " << abs(numQuant) << endl;
    cout << "Power of number = " << pow(numQuant,2) << endl;
    cout << "Square root of number = " << sqrt(numQuant) << endl;
    cout << "Floating absolute of number = " << fabs(numQuant) << endl;
    return 0;
}