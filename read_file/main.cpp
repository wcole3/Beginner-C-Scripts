//Toy prgram to open a file from wd
//NOTE: To find the file it is much easier to change the md in mac
//than to type to whole file path in
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

//Need some to open a file
ifstream& openFile()
{
    ifstream* pFilestream =0;
    for(;;)
    {
        //want this inside a for loop looping forever
        string sFilename;
        cout<<"Please enter a valid file name: "<<endl;
        cin>> sFilename;
        //create the file object
        pFilestream = new ifstream(sFilename.c_str());
        //check to make sure it is a valid name
        if(pFilestream->good())
        {
            //set pointer to beginning of file
            pFilestream->seekg(0);
            cerr<< "Successfully opened "
            <<sFilename<<endl;
            //now we can leave
            break;
        }
    //if the read was back we want to tell use that
    cout<<"Could not open file "<<sFilename<<endl;
    //Delete the heap to reduce memory leakage
    delete pFilestream;
    }
    return *pFilestream;
}

int main()
{
    //get a file from wd
    ifstream& oFile= openFile();
    //from the way openfile is set up we will get a valid filename
    while(!oFile.eof())
    {
        //so long as we are not at the end of the file do things
        int nValue=0;
        //read from file
        oFile>> nValue;
        //if something bad happens we want to stop
        if(oFile.fail())
        {
            cerr<<"Error reading from file"<<endl;
            break;
        }
        //else just output the value we had
        cout<<nValue<<endl;
    }

    cout << "Press 'Enter' to continue" << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}
