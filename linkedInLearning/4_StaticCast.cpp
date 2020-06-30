// Static Cast for egg problem
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"

using namespace std;

int main()
{
    int numEggs;

    cout << "Please enter the number of eggs" << endl;
    cin >> numEggs;
    cout << "Eggs you can eat is multiplied by 0.5\n";
    cout << "Number of eggs you can eat = " << numEggs * 0.5 << endl;
    cout << "But float is not possible\n";
    cout << "So you can eat = ";
    cout << static_cast <int>(numEggs * 0.5) << endl;
    cout << "Welcome to static cast\n";
    return 0;
}