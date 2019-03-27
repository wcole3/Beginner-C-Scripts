//This will use array to perfomr the same
//Functions previously done in the NestedDemo
//Program
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//Some prototype calls
void displayArray(int inputArray[], int sizeOfArray);
int readArray(int inputArray[],int maxsizeOfArray);
int sumArray(int inputArray[], int sizeOfArray);

int main()
{
    //First display what the program does
    cout<<"\n#####################Start##################\n"
        <<"This program takes an input array and\n"
        <<"sums the elements.\n"
        <<endl;
    //Set up the array and get the values


    int valueArray[128];
    int sizeOfArray;
    sizeOfArray=readArray(valueArray, 128);

    //Now want to output the array before letting sum
    displayArray(valueArray, sizeOfArray);

    //Okay now sum and output result
    int summedArray;
    summedArray=sumArray(valueArray,sizeOfArray);
    cout<<"The summed value of the array elements \n"
        <<"is..."<< summedArray<<"\n"
        <<endl;

    //Wait for user
    cout<<"Press 'Enter' to continue...";
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}

int readArray(int inputArray[],int maxsizeOfArray)
{
    cout<<"Begin entering elements into the array\n"
        <<"Entering a negative value will leave  \n"
        <<"the loop.\n"
        <<endl;
    int sizeOfArray=0;
    for(int i=0; i<maxsizeOfArray;i++)
    {
        int input;
        cout<<"Input a value...\n";
        cin>>input;
        if(input<0)
        {
            break;
        }
        inputArray[i]=input;
        sizeOfArray+=i;
    }


    return sizeOfArray;
}

void displayArray(int inputArray[], int sizeOfArray)
{
    //This will output the elements of the array
    cout<<"The elements of the Array are...\n";
    for(int i=0; i<sizeOfArray;i++)
    {
        cout<<"Element "<<i<<": "
            <<inputArray[i]<<"\n";

    }
    cout<<"All elements displayed.\n"
        <<endl;
}
int sumArray(int inputArray[], int sizeOfArray)
{
    //Takes an input array and sums the elements
    int accum=0;
    for(int i=0; i<sizeOfArray;i++)
    {
        accum+=inputArray[i];
    }
    return accum;
}
