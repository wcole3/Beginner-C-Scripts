//Demo to show how to use for loops

#include <cstdio>
#include <cstdlib>

#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    //Want a outer loop that runs forever
    cout<<"\n";
    cout<< "This program sums multiple seqs\n"
        << "of numbers. Terminate each seq \n"
        << "by entering negative number. \n"
        << "To end program enter negative\n"
        << "number twice\n";
    int accum;
    //Outer for loop
    for(;;)
    {
        accum=0;
        cout<< "Enter first number in new seq\n";
        //now need another loop for new seq
        for(;;)
        {
            int nValue=0;
            cout<< "Enter first value...";
            cin>> nValue;

            //Need to see if we break loop
            if (nValue < 0)
            {
                break;
            }
            accum+=nValue;

        }
        if(accum == 0)
        {
            break;
        }
        cout<<"The value of the seq is "
            <<accum<<endl<<endl;

    }
    //Need a wait statement
    cout<<"Press 'Enter' to continue...";
    cin.ignore(10,'\n');
    cin.get();
    return 0;


}
