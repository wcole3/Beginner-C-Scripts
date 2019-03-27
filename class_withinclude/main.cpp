//Toy prgram to try using a locally grown include file
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "saving"


using namespace std;

int main()
{
    Saving s;
    cout << "Please enter Saving acct number"<<"\n" << endl;
    cin>>s.acctNum;
    cout<<"Please enter current balance"<<"\n"<<endl;
    cin>>s.balance;
    double amt;
    cout<<"How much would you like to deposit?"<<"\n"<<endl;
    cin>>amt;
    s.deposit(amt);
    cout<<"Your new balance is..."<<s.balance<<"\n"<<endl;
    cout<<"Press enter to continue..."<<"\n"<<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
