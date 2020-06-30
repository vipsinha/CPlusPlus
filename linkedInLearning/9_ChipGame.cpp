// Chip Game
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TAKEN = 0.5;
const int MAX_PLAYERS = 2;

int main()
{
    bool gameStatus = false;
    uint chipsTaken = 0;
    uint chipsInPile = 0;
    uint maxChipsTaken = 0;
    uint numPlayer = 0;
    string playerName[MAX_PLAYERS];

    cout << "Enter the player1 name\n";
    cin >> playerName[0];

    cout << "Enter the player2 name\n";
    cin >> playerName[1];
    
    srand(time(0));
    chipsInPile = static_cast<uint>(rand() % MAX_CHIPS) + 1; 
    numPlayer = (rand()% MAX_PLAYERS);

    cout << "Chips in the pile = " << chipsInPile << endl;
 
    do
    {
        maxChipsTaken = static_cast<uint>(chipsInPile * MAX_TAKEN);
        numPlayer = numPlayer ^ 1;

        if(chipsInPile > 0)
        {
            do
            {
                cout << "Dear " << playerName[numPlayer] << " Please enter the chips upto ";
                if(chipsInPile != 1)
                {
                    cout << maxChipsTaken << "\n";
                }
                else
                {
                    /* code */
                    cout << "1\n";
                }
                cin >> chipsTaken;
            } while ((maxChipsTaken < chipsTaken) && (maxChipsTaken > 1));
                        


            chipsInPile = chipsInPile - chipsTaken;
            cout << "Chips remained = "<< chipsInPile << endl;
        }
        else
        {
            cout << playerName[numPlayer] << " Won !" << endl;
            gameStatus = true;
        }
    }while(gameStatus == false);

    return 0;
}