//Toy program to parse a fed buffer and sort info
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//here define parse function
//Input will be in format Name, account balance
//retrun true if parse works
bool parseBuff(const char* buff, char* pName, int aSize, long& acctNum, double& bal)
{
    //first want the buffer to be treated as a istrstream object
    istringstream inp(buff);
    //parse the name
    inp.getline(pName, aSize,',');
    //now get the account num
    inp>>acctNum;
    //and the balance
    inp>>bal;
    //if everything goes well return true
    return !inp.fail();
}


int main()
{
    //first need to get the filename
    char scrFilename[128];
    cout<<"Please enter a filename..."<<endl;
    cin.getline(scrFilename,128);
    //now load the file
    ifstream* pFilename = new ifstream(scrFilename);
    if(!pFilename->good())
    {
        //if the file is bad tell someone
        cerr<<"Cannot load "<<scrFilename<<endl;
    }
    //if the file is good them start reading
    for(int nLine=1;;nLine++)
    {
        char buff[256];
        pFilename->getline(buff,256);
        //if the read is good do things
        if(pFilename->fail())
        {
            break;
        }
        //else parse and send out
        cout<<"Line "<<nLine<<": "<<buff<<endl;
        //initialize the things to parse out
        char name[80];
        long acctNum;
        double balance;
        bool parse=parseBuff(buff, name, 80, acctNum, balance);
        if(parse==false)
        {
            cout<<"Could not parse line "<<nLine<<"\n"<<endl;
            continue;
        }
        //if its here then we have parsed something
        cout<<"Read the following:\n"<<endl;
        cout<<"Name = "<<name<<"\n"
            <<"Account number = "<<acctNum<<"\n"
            <<"Balance = "<<balance<<endl;
        //now reassemble results in differnt order for fun
        stringstream out;
        out<< name<<", "
            << balance<<" "
            <<acctNum<<ends;
        string oString = out.str();
        cout<<"Reordered string is: "<<oString<<endl;
    }

    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
