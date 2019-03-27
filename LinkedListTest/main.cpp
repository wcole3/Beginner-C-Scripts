//Toy prgram to play around with linked lists
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class DataSet
{
public:
    string sName;
    DataSet* pNext;
};
DataSet* pHead = nullptr;
//All the add program does is take the pNext entry of the poiner passed to it and first directs it to the head
//of the linked list.  Then it set the new head of the list as the pointer passed to add().
//This is for the backwards list
void add(DataSet* pDS)
{
    //Want to point the entry we are adding to the front of the line
    pDS->pNext=pHead;

    //Now set the head of the list to the added entry
    pHead=pDS;
}
//This is a counterpart to add() which linked the entries from first entered-.last entered
void addFwd(DataSet* pDS)
{
    //We know that since we are adding pDS to the end of the list the pNext entry should be nullptr
    pDS->pNext=nullptr;
    //If the list is empty we want the entry to be the first
    if(!pHead)
    {
        pHead=pDS;
        return;
    }
    //If the list already has elements we need to run through them until we get to the final one
    //It is important that pIter is defined outside of the while loop for reasons of scope
    DataSet* pIter=pHead;
    while(pIter->pNext)
    {
        //Run through all the list entries until we have the last one
        pIter=pIter->pNext;
    }
    //Then set that last one to the entry to be added
    pIter->pNext=pDS;
}

//Need a function to get names from the terminal
DataSet* getName()
{
    string name;
    cout<<"Please enter a name..."<<endl;
    cin>>name;
    //Need a way to exit fn
    if(name=="exit")
    {
        return nullptr;
    }
    //If we are not exiting them we need to create a new entry to be added
    DataSet* pDS = new DataSet;
    //We then need to fill the emty entry with the name and initialize the linker since it has not been added yet
    pDS->sName=name;
    pDS->pNext=nullptr;
    return pDS;
}

int main()
{
    cout << "Please begin entering the names you want on the list"<<"\n"
         << "Enter 'exit' to finish entering names"
         << endl;
    //Now we want to run getName
    DataSet* pDS;
    //As long as pDS=getName is not nullptr it pulls names
    while((pDS=getName()))
    {
        //The add function just takes the name entry and seqentially links it with the next entry
        addFwd(pDS);
    }
    //Now we want to display the names
    cout<<"The list of entered names is:"<<endl;
    //The syntax of this for loop is create a pointer object which serves as an index to loop through
    //the linked list starting at the pHead linker
    for(DataSet* pIter=pHead; pIter; pIter=pIter->pNext)
    {
        //Display name of current entry
        cout<<pIter->sName<<endl;
    }
    cout<<"Press 'Enter' to continue...";
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
