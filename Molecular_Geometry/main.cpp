//Toy prgram to take input file of a molecule and its
//atomic coordinates and calculate some properties
//Bond lengths
//Bond angles
//out-of-plane angles
//torsion/dihedral angles
//Center of mass translation
//Mommetns fo inertia
//Rotational constants
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include "Molecule"
using namespace std;

//Going to make a moleculae class to hold info

//Want a method to open the file
ifstream& openFile();
//want a method to grab the data
void grabData(ifstream& pFile, int zNumber[], double zCoor[], double xCoor[], double yCoor[], int nAtom);
//Want a method to display the coordinates that were just read in
void displayCoor(int zNumber[], double zCoor[], double xCoor[], double yCoor[], int nAtom);
int main()
{
    //the first thing to do is get a file opened
    ifstream& pFile =openFile();
    //Once we have that, figure out how many atoms there are
    int nAtom;
    pFile>>nAtom;
    //Now set up the coor arrays
    int zNumber[nAtom];
    double xCoor[nAtom];
    double yCoor[nAtom];
    double zCoor[nAtom];

    //and get the data
    grabData(pFile, zNumber, xCoor, yCoor, zCoor, nAtom);
    displayCoor(zNumber, xCoor, yCoor, zCoor, nAtom);
    Molecule m = Molecule(nAtom, 0, zNumber);
    m.printInfo();
    cout << "Press 'enter' to continue..." << endl;
    cin.ignore(10,'\n');
    cin.get();
    return 0;
}



ifstream& openFile()
{
    ifstream* pFile =nullptr;
    //Now a loop to get the file
    while(true)
    {
        string fName;
        cout<<"Please enter the file name: "<<endl;
        cin>>fName;
        pFile = new ifstream(fName.c_str());
        if(pFile->good())
        {
            //We got a file so read it
            pFile->seekg(0);
            cerr<<"Successfully opened file: "<<fName<<endl;
            break;
        }
        cout<<"Could not open file, please try again."<<endl;
        cout<<"Don't forget to run this program in the debug folder"<<endl;
        delete pFile;
    }
    //if we exit then the file is opened
    return *pFile;
}

void grabData(ifstream& pFile, int zNumber[], double zCoor[], double xCoor[], double yCoor[], int nAtom)
{
    //We know the file and nAtoms we can just grab the data
    for(int i=0; i < nAtom; i++)
    {
        //The file is formatted as Atomic number, x, y, z
        pFile>>zNumber[i]>>xCoor[i]>>yCoor[i]>>zCoor[i];
    }
}
void displayCoor(int zNumber[], double zCoor[], double xCoor[], double yCoor[], int nAtom)
{
    //want to display out these arrays
    cout<<"There are "<< nAtom<< " atoms"<<endl;
    cout<<"The values for: \n"<<"Atomic Number, X, Y, Z"<<endl;
    for(int i = 0; i<nAtom;i++)
    {
        cout<<zNumber[i]<<" , "<<xCoor[i]<<" , "<<yCoor[i]<<" , "<<zCoor[i]<<endl;
    }
}
