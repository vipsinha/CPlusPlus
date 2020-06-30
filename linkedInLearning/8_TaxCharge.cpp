// Dice Game
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"
#include "iomanip"

using namespace std;

const float TAX_RATE = 0.05;

int main()
{
    float price = 4.5;
    float chargedPrice;
    float taxCharge = 0;
    int quantity = 0;

    cout << "Enter the quantity of item\n";
    cin >> quantity;

    //for testing, comment below lines and 
    //check the difference in output format
    //format output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    chargedPrice = price * quantity;
    taxCharge = chargedPrice * TAX_RATE;
    cout << "Total price = " << setprecision(2) << chargedPrice << endl;
    cout << "Tax charged = "<< setprecision(2) << taxCharge << endl;    

    return 0;
}