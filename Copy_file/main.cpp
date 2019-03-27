//Toy program to copy a file given
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
//pass the file names to copy to the program upon call
int main( int nNumberofArgs, char* pzsArg[])
{
    //Need to open the passed arg
    for(int i=1;i<nNumberofArgs;i++)
    {
        string scrName(pzsArg[i]);
        string tgtName = "Backup_of_"+scrName;
        //open the sourcefile
        ifstream input(scrName.c_str(),ios_base::in|ios_base::binary);
        //the second arguement above is teling teh file to open in
        //'in' mode or in 'binary' mode
        ofstream output(tgtName.c_str(), ios_base::out|ios_base::trunc|ios_base::binary);
        //Now that we have a file object we can read from it
        if(input.good() && output.good())
        {
            cout<<"Backing up "<<scrName<<endl;
            while(!input.eof())
            {
               //so long as we arent at the end of the file read in 4096 bit chucnks
               char buff[4096];
               input.read(buff,4096);
               //and put in output
               output.write(buff, input.gcount());

            }
            cout<<"Finished"<<endl;
        }
        else
        {
            cerr<<"Counldn't copy "<<scrName<<endl;
        }
    }

    cout << "Press 'Enter' to continue" << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
