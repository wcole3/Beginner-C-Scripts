//toy program to test protected class elements and friend functions
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
//want two class admin and user

class User;
class Admin
{
public:
    friend Admin* initializeAdmin(string aName, int aID);
    string message;
    void chgMess(string nMessage)
    {
        message=nMessage;
        return;
    }
    void setUserHours(User* pUser);

protected:
    string name;
    int id;

};

class User
{
    friend User* initializeUser(string aName);
    friend class Admin;
public:
    string nickname;
protected:
    string name;
    double hours;

};
//let admins set the hours of a user
void Admin::setUserHours(User* pUser)
{
    double newHours;
    cout<<"Current user hours: "<<pUser->hours<<endl;
    cout<<"How many hours were worked?"<<endl;
    cin>>newHours;

    pUser->hours=newHours;
    cout<<"New user hours: "<<pUser->hours<<endl;
    return;
}
//setup new admin
Admin* initializeAdmin(string aName, int aID)
{
    Admin* pAdmin=new Admin;
    pAdmin->name=aName;
    pAdmin->id=aID;
    return pAdmin;
}
//set up new user
User* initializeUser(string aName)
{
    User* pUser=new User;
    pUser->name=aName;
    pUser->hours=0.0;
    return pUser;
}

int main()
{
    cout << "Welcome, lets get some users and admins set up" << endl;
    cout<<"Please enter Admin name..."<<endl;
    string aName;
    cin>>aName;
    cout<<"Please enter your id #..."<<endl;
    int aID;
    cin>>aID;
    //now we need to set up the admin
    Admin nAdmin;
    Admin* pAdmin=&nAdmin;
    pAdmin=initializeAdmin(aName, aID);
    //now get users set up
    cout<<"Please enter User name..."<<endl;
    string aUName;
    cin>>aUName;
    User* pUser=new User;
    pUser=initializeUser(aUName);
    //okay now just see if we can set the user hours

    nAdmin.setUserHours(pUser);
    //This works!!
    //could build on this...

    cout<<"Press 'enter' to continue..."<<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
