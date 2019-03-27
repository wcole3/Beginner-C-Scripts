//example showing how classes work
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//first define the class
class SavingAcct
{
    public:
    double balance;
    double deposit(double dep)
    {
        balance+=dep;
        return balance;
    }
};

int main()
{
    SavingAcct mySave;
    cout<<"What is your bank balance? \n"<<endl;
    cin>> mySave.balance;
    double testDip;
    cout<<"How much would you like to deposit?\n"<<endl;
    cin>> testDip;
    mySave.deposit(testDip);
    cout<<"Your new acct balance is..."<<mySave.balance;
    cout<<endl;

    cout<<"Please press 'Enter' to continue...\n";
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
