// Random number generator 
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"
#include "math.h"
#include "ctime"

using namespace std;

int main()
{
    float numRand = 0;

    srand(time(0));
    numRand = rand();

    cout << "Rand number generated = " << numRand << endl;

    return 0;
}