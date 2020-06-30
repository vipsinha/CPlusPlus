// File Input output a string
/* Aut: Vipul Sinha, Date: 2020-02-02 */

#include "iostream"
#include "fstream"

using namespace std;

int main()
{
    ifstream inFileA;
    string sReadPhrase;
    int guessLength = 0;

    // Open a file
    inFileA.open("passphrase.txt");

    // check if the file is opened successfully
    if(!inFileA.fail())
    {
        // read till all the lines are read successfully
        while(inFileA >>  sReadPhrase)
        {
            cout << sReadPhrase << endl;
            cout << "Guess the magic number (length) : ";
            cin >> guessLength;

            // to read a length of the file
            if(guessLength == sReadPhrase.length())
            {
                cout << "Congrats\n";
            }
            else
            {
                /* code */
                cout << "You lost, try again\n";
            }
            

        }
    }

    // close the file
    inFileA.close();

    return 0;
}
