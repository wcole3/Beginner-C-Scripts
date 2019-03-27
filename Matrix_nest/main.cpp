//This is a program to pull in a matrix from the user
//And then report the trace

#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;

//proto-calls
void displayMat(int inputMat[128][128], int sizeOfRow);
int readMat(int inputMat[128][128], int maxSizeOfRow);
int readTrace(int inputMat[128][128], int sizeOfRow);


int main()
{
    cout<<"\n#################START#############\n"
        <<"This program reads an input  sq. matrix \n"
        <<"and outputs the matrix and its trace\n"
        <<endl;

    int inputMat[128][128];
    int sizeOfRow;
    //This will give us the size of the matrix
    //and the actual matrix itself
    sizeOfRow=readMat(inputMat,128);
    //Now display the matrix
    displayMat(inputMat,sizeOfRow);

    int trace;

    trace=readTrace(inputMat, sizeOfRow);
    cout<<"The trace of the matrix is "
        <<trace<<endl;

    //Now the std wait for user interface
    cout<<"Please press 'Enter' to continue...\n"
        <<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;

}
int readMat(int inputMat[128][128], int maxSizeOfRow)
{
    cout<<"Please enter the elements startin at \n"
        <<"(0,0). You can end the first row by entering a\n"
        <<" negative number.  You must enter all elements\n"
        <<"The size of the rows\n"
        <<" will be set to the size of columns. \n"
        <<"Enter two cons. negative number to end.\n"
        <<endl;
    int sizeOfRow=0;

    for(int i=0; i<maxSizeOfRow; i++)
    {
        int input;
        cout<<"Input element "<<i<<","<<0<<"\n";
        cin>>input;

        if(input<0)
        {
            break;
        }
        inputMat[i][0] = input;
        sizeOfRow++;
    }
    for(int j=1;j<sizeOfRow;j++)
    {
        for(int m=0;m<sizeOfRow;m++)
        {
            int input;
            cout<<"Input element "<<m<<","<<j<<"\n";
            cin>>input;
            if(input<0)
            {
                break;
            }
            inputMat[m][j]=input;
        }
    }
    return sizeOfRow;
}



void displayMat(int inputMat[128][128], int sizeOfRow)
{
    cout<<"The matrix you entered is...\n"
        <<endl;

    for(int j=0;j<sizeOfRow;j++ )
    {
        for(int i=0;i<sizeOfRow;i++)
        {
            cout<<inputMat[i][j]<<"\t";

        }
        cout<<endl;
    }
    cout<<"All elements displayed\n"
        <<endl;
}

int readTrace(int inputMat[128][128],int sizeOfRow)
{
    int traceValue=0;
    for(int j=0;j<=sizeOfRow;j++)
    {
        for(int i=0; i<=sizeOfRow;i++)
        {
            if(i==j)
            {
                traceValue=traceValue+inputMat[i][j];
            }
        }
    }
    return traceValue;

}
