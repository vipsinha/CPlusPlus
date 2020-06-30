// Classes
/* Aut: Vipul Sinha, Date: 2020-02-20 */

#include "iostream"

using namespace std;

class BankAccount
{
    private:
        float bankBalance;
    public:
        // Default constructor
        BankAccount(void);
        void getBalance(void);
        void addMoney(float amount);
        void withdrawl(float amount);
};

BankAccount::BankAccount(void)
{
    bankBalance = 0;
}

void BankAccount::getBalance(void)
{
    cout << "Account Balance is : " << bankBalance << endl;
}

void BankAccount::addMoney(float amount)
{
    bankBalance += amount;
}

void BankAccount::withdrawl(float amount)
{
    bankBalance -= amount;
}

int main()
{
    BankAccount accHolder_A;
    BankAccount accHolder_B;

    accHolder_A.getBalance(); 
    accHolder_B.getBalance(); 

    accHolder_A.addMoney(100); 
    accHolder_B.addMoney(200); 

    accHolder_A.getBalance(); 
    accHolder_B.getBalance(); 

    accHolder_A.withdrawl(50); 
    accHolder_B.withdrawl(75); 

    accHolder_A.getBalance(); 
    accHolder_B.getBalance(); 

    return 0;
}
