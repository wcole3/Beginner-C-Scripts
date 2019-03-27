//Demo for move and copy class functions

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(string pName="no name", string hColor="bald"):name(pName),color(hColor)
    {
        cout<<"Constructed Person "<<pName<<endl;
    }
    Person (Person& p)
    {
        cout<<"Constructed Copy of "<<p.name<<endl;
        p.name="Copy of "+p.name;
    }
    ~Person()
    {
        cout<<"Destructed Person "<<name<<endl;
    }

    string name;
    string color;
};

void fn(string nName, string hColor)
{
    cout<<"Entering fn"<<endl;
    Person(nName, hColor);
    return;

}

void fun(Person p)
{
    cout<<"Entering fun"<<endl;


}

int main()
{
    Person* t;
    t= new Person("Jim");
    Person p("Tim","red");

    fn("will", "blond");
    cout<<"Original person is "<<t->name<<endl;
    fun(p);
    cout<<"Out of fun"<<endl;



    cout << "Press 'Enter' to continue" << endl;
    cin.get();
    cin.ignore(10,'\n');
    return 0;
}
