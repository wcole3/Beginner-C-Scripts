//toy program for using constructors and destructors in a useful way==
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "teacher"
using namespace std;
//want a student id class
int nextStudid=0;
class StudentId
{
public:
    StudentId(int value=0)
    {
        if(value!=0)
        {
            id=value;
        }
        else
        {
            id=++nextStudid;
        }
        cout<<"Assigning student id "<<id<<endl;
    }
protected:
    int id;
};

//now a student class
class Student
{
public:
    Student(string nName ="no name", int newId=0, float xTgpa =0.0, int xThours=0, string tName="no name",string tCourse="no course"):id(newId),t(tName,tCourse)
    {
        name=nName;
        gpa=xTgpa;
        hours=xThours;
        cout<<"Constructing student object"<<endl;
    }
protected:
    //all the things that define a student
    string name;
    StudentId id;
    float gpa;
    int hours;
    Teacher t;
};

int main()
{
    Student s;
    Student newStudent("Jim",134, 3.5, 45, "Dr. Smith","Math");
    Student nS;
    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
