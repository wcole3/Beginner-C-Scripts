//Toy program to print program arguements
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int numberOfArgs, char* pzsArgs[])
{
    //This program should pring the arguments passed to main
    cout<<"\n"<<"The arguments passed to pringArgs are ..."<<'\n'<<endl;

    for(int i=0; i<numberOfArgs;i++)
    {
        cout<<"Argurment "<<i<<" is "
            <<" < "<<pzsArgs[i]<<" > "<<endl;
    }

    cout<<"\n"<<"Thats all folks!!"<<"\n"<<endl;



    cout<<"Please press 'Enter' to Continue...\n"
        <<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
