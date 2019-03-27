#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void displayInstruc(void)
{
    //Want this to output the user instructions
    cout<<"This program takes a series of\n"
        <<"numbers and squares them and  \n"
        <<"then takes the sum. To end a  \n"
        <<"series, enter a negative number\n"
        <<"To end the program, enter two \n"
        <<"negative numbers in a row\n"
        <<endl;
}

double square(double value)
{
    //This should square a number
    double square;
    square=(value*value);
    return square;
}

double innerLoop(void)
{
    //This is the inner loop which should sum the sqaures
    double accum= 0.0;
    for (;;)
    {
        //Need to get a number from the useer
        double nValue;
        cout<<"Please enter a number...\n";
        cin>>nValue;

        if(nValue<0)
        {
            break;
        }
        else
        {
            double sqValue;
            sqValue=square(nValue);
            accum+=sqValue;
        }

    }
    return accum;

}

int main()
{
    displayInstruc();

    //Now need the outer loop
    for(;;)
    {
        cout<<"Starting new series...\n";
        double output;
        output=innerLoop();
        if(output==0.0)
        {
            break;
        }
        else
        {
            cout<<"Sum of series' squares is \n"
                <<output<<"\n"
                <<endl;
        }
    }
    cout<<"Press 'Enter' to continue..."<<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
