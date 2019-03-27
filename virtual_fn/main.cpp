//toy program demonstrating virtual functions
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(string sName="no name"):name(sName)
    {
        cout<<"Constructed Student "<<name<<endl;
    }
    virtual ~Student()
    {
        cout<<"Killed Student "<<name<<endl;
    }
    //when the function below is not virtual, the call in randFn always goes to the
    //someFn in Student
    virtual void someFn()
    {
        cout<<"In Student someFn"<<endl;
        return;
    }
protected:
    string name;
};

class GradStudent:public Student
{
public:
    GradStudent(string gName):Student(gName){}
    ~GradStudent()
    {
        cout<<"Killed GradStudent "<<name<<endl;
    }
    void someFn()
    {
        cout<<"In GradStudent someFn"<<endl;
        return;
    }

};

void randFn(Student* s)
{
    s->someFn();
}

int main()
{
    Student* s=new Student("Lil");
    GradStudent* g= new GradStudent("Will");
    randFn(s);
    randFn(g);
    delete s;
    delete g;
    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
