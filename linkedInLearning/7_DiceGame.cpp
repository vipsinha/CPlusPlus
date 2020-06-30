// Dice Game
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"
#include "math.h"
#include "ctime"

using namespace std;

int main()
{
    // should of and int type
    // as ampercent operation may not happen on float
    // unsigned will always get output as 0
    // as random number is between 0 to 1
    int numRand = 0;

    //Generate the random number
    srand(time(0));
    numRand = rand();

    // Since the dice has values between 0 to 6
    // do an ampercent of the number 
    // so that the result is between 0 to 6
    numRand = numRand % 6;

    // the numRand is from 0 to 5, as dice will have output
    // 1 to 6, hence add +1
    numRand += 1;
    cout << "Dice output = " << numRand << endl;

    return 0;
}