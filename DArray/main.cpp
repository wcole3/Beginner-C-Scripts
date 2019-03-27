//toy program used to demonstrate overriding the assignment operator
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//The class that will do everything
class dArray
{
public:
    dArray(int numberOfEl=0) :aLeng(numberOfEl), pArray(nullptr)
    {
        cout<<"Creating new dArray object of length = "
        << numberOfEl <<endl;
        if(numberOfEl > 0)
        {
           pArray = new int[numberOfEl];
        }
    }
    //need copy function
    dArray(dArray& da)
    {
        cout<<"Copying dArray of size = "<< da.aLeng<<endl;
        //Have a custom fn for this
        copyDA(da);
    }
    //Also want a move operator to play with
    dArray(dArray&& source)
    {
        moveDA(*this, source);
    }
    ~dArray()
    {
        //Another custom fn
        deleteDA();
    }
    //now we need a override for the assignment operator
    dArray& operator=(const dArray& d)
    {
        cout<<"Assigning Array of length = "<<d.aLeng
        <<" to Array of size = "<< this->aLeng <<endl;
        deleteDA();
        copyDA(d);
        return *this;
    }
    //Need two of these if using move
    dArray& operator=(dArray&& d)
    {
        delete pArray;
        moveDA(*this,d);
        return *this;
    }
    //Also want to create an indexing opertion
    int& operator[](int index)
    {
        return pArray[index];
    }
    //want a get size function
    int size(){return aLeng;}
    //Also want a way to display a given array
    void display(ostream& out)
    {
        if(aLeng > 0)
        {
            out<<pArray[0];
            for(int i=1; i<aLeng;i++)
            {
                out<< " , "<<pArray[i];
            }
        }
    }

protected:
    static void moveDA(dArray& target, dArray& source)
    {
        cout<<"Moving array of size = "<<source.aLeng<<endl;
        target.aLeng=source.aLeng;
        if(source.aLeng >0)
        {
           target.pArray= new int[source.aLeng];
           for(int i =0; i<source.aLeng;i++)
            {
                target.pArray[i]=source.pArray[i];
            }
        }
        source.aLeng=0;
        source.pArray=nullptr;
    }
    void copyDA(const dArray& d);
    void deleteDA();
    int aLeng;
    int* pArray;
};

//Now to define those custom functions
void dArray::copyDA(const dArray& source)
{
    //Need to get the important bits from source
    aLeng=source.aLeng;
    pArray=nullptr;
    if(aLeng > 0)
    {
        pArray = new int[aLeng];
        for(int i=0; i< aLeng;i++)
        {
            pArray[i]=source.pArray[i];
        }
    }
}
 void dArray::deleteDA()
 {
     aLeng=0;
     delete pArray;
     pArray=nullptr;
 }
dArray fn(int number)
{
    dArray temp(number);
    for(int i =0;i<number;i++)
        temp[i]=i;
    return temp;
}

int main(int numberOfArgs, char* pszArg[])
{
    //generate a new object
    dArray test1(5);
    for(int i=0; i<test1.size(); i++)
    {
        test1[i]=i;
    }
    //Display the array at this point
    cout<<"test1 = "; test1.display(cout); cout<<endl;
    //now lets play with our new copyDA fn
    dArray test2(test1);
    //change a value so we know its a copy
    test2[3] = 42;
    cout<<"test2 = "; test2.display(cout); cout<<endl;
    //Now use the assignment operator to change back
    test2=test1;
    cout<<"Now test2 = ";test2.display(cout);cout<<endl;
    //now lets see if we can get a use out of the move fn
    dArray test3(6);
    test3 = fn(6);
    test3.display(cout);cout<<endl;
    cout << "Press 'Enter' to continue" << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}
