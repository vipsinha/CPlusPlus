// Chip Game
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"

using namespace std;

void GetUserName(string plyName[]);
int AskMove(int playerTurn, uint chipsInPile, string name[]);

const int MAX_CHIPS = 100;
const float MAX_TAKEN = 0.5;
const int MAX_PLAYERS = 2;

int main()
{
    bool gameStatus = false;
    uint chipsInPile = 0;
    uint numPlayer = 0;
    string playerName[MAX_PLAYERS];

    // Ask the player name
    GetUserName(playerName);
    
    // random number generator
    srand(time(0));

    // cast is necessary else negative number can be 
    // generated
    chipsInPile = static_cast<uint>(rand() % MAX_CHIPS) + 1; 
    numPlayer = (rand()% MAX_PLAYERS);

    cout << "Chips in the pile = " << chipsInPile << endl;
 
    do
    {
        // the next player
        numPlayer = numPlayer ^ 1;

        // if chips in pile are not 0, ask for the pick up
        // of the chips from pile
        if(chipsInPile > 0)
        {
            // Ask for take the chips
            chipsInPile = AskMove(numPlayer, chipsInPile, playerName);
        }
        else
        {
            // Display the name of winner
            cout << playerName[numPlayer] << " Won !" << endl;
            // end the game
            gameStatus = true;
        }
    }while(gameStatus == false);

    return 0;
}

void GetUserName(string name[])
{
    cout << "Enter the player1 name\n";
    cin >> name[0];
   
    cout << "Enter the player2 name\n";
    cout << "If you want to play against computer write AI :";
    cin >> name[1];

    cout >> "Lets Play!\n"
}

int AskMove(int playerTurn, uint chipsInPile, string name[])
{
    uint maxChipsTaken = 0;
    uint chipsTaken = 0;

    // Maximum chips taken is half of the pile
    // should be cast to unisgned int, as the output will be float
    maxChipsTaken = static_cast<uint>(chipsInPile * MAX_TAKEN);

    do
    {
        cout << "Dear " << name[playerTurn] << " Please enter the chips upto ";
        // if the chips are greater than 0
        if(chipsInPile != 1)
        {
            cout << maxChipsTaken << "\n";
        }
        else
        {
            /* code */
            cout << "1\n";
        }

        // if the second player is computer and its turn for pick
        if((name[1] == "AI") && (playerTurn == 1))
        {
            // select the random number from the computer
            // it must be greater than 0, hence added 1
            chipsTaken = (rand()%maxChipsTaken) + 1; 
        }
        else
        {
            cin >> chipsTaken;
        }
    // if chips taken is greater than in greater than half of the 
    // max chips in the pile, then again ask for input
    // also the loop should not run, if the max chips that can be taken
    // is less than 1    
    } while ((maxChipsTaken < chipsTaken) && (maxChipsTaken > 1));
                
    // calculate the remaining chip            
    chipsInPile = chipsInPile - chipsTaken;
    cout << "Chips remained = "<< chipsInPile << endl;

    return(chipsInPile);
}