//Toy program to pull the name of the month from int input
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char* getMonth(int nMonth);
char* monthList[] = {"Wrong","January","Febuary","March","April","May","June","July","August","September","October","November","December"};

int main()
{
    int nMonth;
    cout << "Please input the month number..." <<"\n"<< endl;
    cin>>nMonth;
    char* monthName=getMonth(nMonth);
    cout<<"The month is "<<monthName<<"\n"<<endl;

    cout<<"Please press enter to continue..."<<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}

char* getMonth(int nMonth)
{
    char* monthName;
    if(nMonth<1 || nMonth>12)
    {
        return "nonexistent...dumbass.";
    }
    return monthList[nMonth];
}
