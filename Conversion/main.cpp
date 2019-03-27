//
//Conversion program for celsius to fahreheit
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    //Put in celsuis
    int celsius;
    cout << "Enter the Temperature in Celsius:";
    cin >> celsius;

    //Conversion factor
    int factor;
    factor = 212-32;

    //Use conversion factor
    int fahrenheit;
    fahrenheit=factor * celsius/100 +32;

    //output
    cout << "Temperature in fahrenheit is:";
    cout << fahrenheit << endl;

    //wait until written down
    cout << "Press enter to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}

