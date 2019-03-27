//Toy program to play with passing by value or reference as applied
//to objects
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Student
{
public:
    double gpa;
};

//Pass by reference
//This is slower than the pointer option
void testfn(Student &s)
{
    s.gpa=3;
}

void testptrfn(Student* s)
{
    s->gpa=2;
}

int main()
{
    Student s;
    s.gpa=0;

    cout << "The student gpa is "<<s.gpa << endl;
    testfn(s);
    cout<<"New gpa is (by ref)..."<<s.gpa<<endl;

    Student x;
    x.gpa=0;
    Student* prx=&x;
    cout << "The student gpa is "<<x.gpa << endl;
    testptrfn(prx);
    cout<<"New gpa is (by ptr)..."<<x.gpa<<endl;

    cout<<"Press enter to continue..."<<endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
