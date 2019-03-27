//Toy program to see if I can actually code a linked list
//and have it read fwd or backward
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
//Need a class with linker to run through both forward and backward
class DataSet
{
public:
    string sName;
    DataSet* pNextBck;
    DataSet* pNextFwd;
};
DataSet* pHeadBck = nullptr;
DataSet* pHeadFwd = nullptr;

//This need to modify both the bck and fwd linkers
void add(DataSet* pDS)
{
    //first the bck linker
    //point entry to front of the line
    pDS->pNextBck=pHeadBck;
    //Set the entry as the new head
    pHeadBck=pDS;

    //now for the fwd version
    //We know that the entry will be the last entry so
    pDS->pNextFwd=nullptr;
    //Now we need to add to the list
    if(!pHeadFwd)
    {
        pHeadFwd=pDS;
        return;
    }
    //If there is already entries we need to loop through to get to the end
    DataSet* pIter=pHeadFwd;
    while(pIter->pNextFwd)
    {
        pIter=pIter->pNextFwd;
    }
    //once we know the last entry we want to set that linker to the entry
    pIter->pNextFwd=pDS;
}
//Need something to get in data
DataSet* getName()
{
    string name;
    cout<<"Please enter a name..."<<endl;
    cin>>name;
    //Need a way to get out of the fn
    if(name=="exit")
    {
        return nullptr;
    }
    //if we need to enter the name to the list we need to initialize the entry
    //Create a pointer to a new DataSet object
    DataSet* pDS=new DataSet;
    pDS->sName=name;
    //initialize the pointers
    pDS->pNextBck=nullptr;
    pDS->pNextFwd=nullptr;
    return pDS;
}

int main()
{
    cout<<"Please enter names you wish to add to a list"<<"\n"
        <<"Enter 'exit' to finish entering names"<<endl;

    //now we need to start getting names
    DataSet* pDS;
    while((pDS=getName()))
    {
        //Now that we have generated a entry, we need to adjust its linkers
        add(pDS);
    }
    //After all the fun we need to display the lists: both fwd and bck
    cout<<"The (BCK) list you entered is:"<<endl;
    for(DataSet* pIterBck=pHeadBck;pIterBck;pIterBck=pIterBck->pNextBck)
    {
        cout<<pIterBck->sName<<endl;
    }
    cout<<"The (FWD) list you entered is:"<<endl;
    for(DataSet* pIterFwd=pHeadFwd;pIterFwd;pIterFwd=pIterFwd->pNextFwd)
    {
        cout<<pIterFwd->sName<<endl;
    }
    cout << "Please press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
