//toy program to play with constructors and destructors
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
class Course
{

public:
    Course()
    {
        cout<<"constructing course"<<endl;
    }
    ~Course()
    {
        cout<<"destructing course"<<endl;
    }
};
class User
{
public:

    string name;
    Course aClass;
    User()
    {
        cout<<"constructing user"<<endl;
    }
    ~User()
    {
        cout<<"destructing user"<<endl;
    }
};

class Admin
{
public:
    string name;
    User user;
    Admin()
    {
        cout<<"constructing admin"<<endl;
    }
    ~Admin()
    {
        cout<<"destructing admin"<<endl;
    }
};


void localTest()
{
    cout<<"Running Local test"<<endl;
    Admin* admin;
    admin=new Admin;
    delete admin;
    return;
}
int main()
{
    cout<<"Creating Admin object"<<endl;
    Admin nAdmin;
    cout<<"Creating User object"<<endl;
    User nUser;
    localTest();

    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
