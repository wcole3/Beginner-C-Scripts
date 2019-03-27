//toy prgram for throwing and handling exceptions
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

//first need a custom exception object
class myExcp
{
public:
    myExcp(string imessage="", string ifuncN="", int ilineN=0, string ifileN=""): message(imessage),funcN(ifuncN),lineN(ilineN),fileN(ifileN)
    {}

    static void displayError(myExcp m, ostream& out)
    {
        out<<"Generated error: "<<m.message<<"\n"
        <<"In function "<<m.funcN<<"\n"
        <<"On Line "<<m.lineN<<"\n"
        <<"In File "<<m.fileN<<endl;
    }
protected:
    string message;
    string funcN;
    int lineN;
    string fileN;
};

//now need a factorial program
int factorial(int n)
{
    if(n<0)
    {
        string error = "The value is negative";
        throw myExcp(error, __FUNCTION__,__LINE__,__FILE__);
    }
    if(n==0)
    {
        return 1;
    }
    int nValue=1;
    while(n>0)
    {
        nValue*=n;
        n--;
    }
    return nValue;
}

int main()
{
    try
    {
        int test1= factorial (5);
        cout<<test1<<endl;
        int test2=factorial (-1);
        cout<<test2<<endl;
        int test3= factorial(0);
        cout<<test3<<endl;
    }
    catch(myExcp m)
    {
        myExcp::displayError(m,cerr);
    }


    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
