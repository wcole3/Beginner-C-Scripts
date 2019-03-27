//This is a demo program for playing with pointers

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{
    //This is the input string
    const int arraysize=5;
    char inpArray[arraysize] = "Will";
    //Now make sure the program reconizes the array
    cout<<"Hello everyone"<<"\n"
        <<endl;

    //Now display the string using typical array indexing

    cout<<"The string is...";

    for(int i=0; i<arraysize; i++)
    {
        cout<<inpArray[i];
    }

    cout<<"\n"<<"Thats it\n"
        <<"The string is...";


    const char* ptr;
    ptr = inpArray;
    while(*ptr)
    {
        cout<<*(ptr++);
    }

    cout<<"\n"<<"Thats it\n";


    cout<<"Please press 'Enter' to continue...\n"
        <<endl;

    cin.ignore(10,'\n');
    cin.get();
    return 0;
}

