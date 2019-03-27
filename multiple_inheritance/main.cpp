//Just a toy program to demonstrate multiple inheritance
#include <cstdio>
#include <cstdlib>
#include <iostream>

//We are going to have four total classes with a inheritance tree of
//1->2->1 or furniture-> Sofa, Bed-> Sofasleeper
using namespace std;

class furniture
{
public:
    furniture(int nWeight =0):weight(nWeight){}
    int weight;
};

//the virtual keyword tells to class to generate a furniture object unless one
//already exits associated with the current object
class sofa: virtual furniture
{
public:
    sofa(int nWeight=0):weight(nWeight){}
    void watchTV()
    {
        cout<<"You can watch TV here"<<endl;
    }
    int weight;
};

class bed: virtual furniture
{
public:
    bed(int nWeight=0):weight(nWeight){}
    void sleep()
    {
        cout<<"You can sleep here"<<endl;
    }
    int weight;
};

class sleeperSofa: public sofa, public bed
{
public:
    sleeperSofa(int nWeight=0):weight(nWeight){}
    void convert()
    {
        cout<<"Convert from sofa to bed"<<endl;
    }
    int weight;
};

int main()
{
    sleeperSofa ss(100);
    sleeperSofa* pSS =&ss;
    ss.watchTV();
    ss.convert();
    ss.sleep();
    cout<<"Now using pointers...\n"<<endl;
    pSS->watchTV();
    pSS->convert();
    pSS->sleep();
    cout<<"And the weight of the furniture is "<<pSS->weight<<endl;

    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}
