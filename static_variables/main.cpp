//toy prgram for static variables
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "person_class"

using namespace std;

//need person class


int main()
{
    Person t("Jim", "male");
    cout<<t.getName()<<endl;
    Person* p;
    p=new Person("Sarah");
    cout<<p->getName()<<endl;
    cout<<"Current population is "<<t.Population()<<endl;
    delete p;

    cout<<"New population "<<t.Population()<<endl;
    cout << "Press 'Enter' to continue..." << endl;
    cin.get();
    cin.ignore(10,'\n');

    return 0;

}
