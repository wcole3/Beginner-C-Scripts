//toy program demonstrating inheritance
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(string sName="No Name", int sHours = 0, float sGpa=0.0):name(sName), hours(sHours), gpa(sGpa)
    {
        numCourses = 0;
        courses = new string[numCourses];
        cout<<"Constructed student "<<sName<<endl;
    }
    ~Student()
    {
        delete [] courses;
        cout<<"Killed Student "<<name<<endl;
    }
    void addCourse(string nameOfCourse, int cHours, float cGrade)
    {
        string *temp = courses;
        numCourses++;
        courses = new string[numCourses];
        for(int i = 0; i < numCourses-1; i++)
        {
            courses[i] = temp[i];
        }
        courses[numCourses-1] = nameOfCourse;

        delete [] temp;

        float pGpa = (gpa*hours);
        hours+=cHours;
        gpa=(pGpa+(cGrade*cHours))/hours;

    }
    void printStudentInfo()
    {
        cout << "Name of the student: " << name << endl;
        cout << "Student taking " << hours << " hours." << endl;
        cout << "GPA: " << gpa << endl;
        cout << "They are taking the following courses: ";
        for(int i = 0; i < numCourses; i++ )
        {
            cout << courses[i] << " ";
        }
        cout << endl;
    }
    string getName(){return name;}
    int getHours(){return hours;}
    float getGpa(){return gpa;}

protected:
    string name;
    int hours;
    float gpa;
    string *courses;
    int numCourses;
};

class GradStudent: public Student
{
public:
    GradStudent(string gName, string gField = "Undecided"):Student(gName), field(gField)
    {
        cout<<"Constructed Grad Student "<<gName<<endl;
    }
    ~GradStudent()
    {
        cout<<"Killed Grad Student "<<name<<endl;
    }
    string getField(){return field;}

protected:
    string field;
};

int main()
{
    Student s("jill");
    s.addCourse("chem101", 2,3.5);
    s.printStudentInfo();
    //cout<<"Student gpa is "<<s.getGpa()<<endl;
    GradStudent* g=new GradStudent("will","Chemistry");
    g->addCourse("csce145", 3,2.75);
    g->printStudentInfo();
    //cout<<"Grad Student studies "<<g->getField()<<endl;
    //cout<<"Grad Student gpa is "<<g->getGpa()<<endl;
    //cout << "Please press 'Enter' to continue..." << endl;
    delete g;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
