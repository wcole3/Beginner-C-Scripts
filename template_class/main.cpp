//toy program to play around with templates for class
#include <cstdio>
#include <cstdlib>
#include <iostream>
//alos going to make a template vector class in h file
#include "templateVector"

using namespace std;

//now we want to make a new class to manipulate in our template
class Coffee
{
public:
    Coffee(string cupOwner="Free", int cupSize = 0, double amtOfCoffee = 0.0):owner(cupOwner),nSize(cupSize), fillVolume(amtOfCoffee){}
    void fillCup(){fillVolume=double(nSize);}
    void drink(){fillVolume = 0.0; cout<<"No more coffee :("<<endl;}
    string display(){return owner;}

    string owner;
    int nSize;
    double fillVolume;
};

//two toy functions which will use the template fns
void intFn();
void coffeeFn();

int main()
{
    Coffee c("Will", 16, 14.5);
    c.drink();
    intFn();
    coffeeFn();

    cout << "Press 'Enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}

void intFn()
{
    TemplateVector<int> intarray(100);
    //now we need to add elements to this structure
    cout<<"Please enter integer values to add into the array:\n"
        <<"(enter a negative value to stop)"<<endl;
    for(;;)
    {
        int nValue;
        cin>>nValue;
        if(nValue <0)
        {
            break;
        }
        intarray.add(nValue);
    }
    cout<<"Here are the values you entered:\n"<<endl;
    for(int i =0; i<intarray.size();i++)
    {
        cout<<"i :"<<intarray.get()<<endl;
    }
}

void coffeeFn()
{
    TemplateVector<Coffee> coffArray(5);
    cout<<"Please tell me who to get Coffee for: \n"
        <<"(Enter 'xx' to finished order)"<<endl;
    for(;;)
    {
        cout<<"Next: "<<endl;
        Coffee c;
        cin>>c.owner;
        if(c.owner == "xx"){break;}
        cout<<"What size to they want? "<<endl;
        cin>>c.nSize;
        c.fillCup();
        coffArray.add(c);
    }
    cout<<"Here are the people you got coffee for:\n"<<endl;
    for(int i =0; i<coffArray.size();i++)
    {
        Coffee order = coffArray.get();
        cout<<"i : "<<order.display()<<endl;
    }
}
