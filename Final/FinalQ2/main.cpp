/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on December 16, 2022, 10:07 AM
 */

#include <iostream>
#include <fstream>
#include "prob2.h"

using namespace std;

int main(int argc, char** argv) 
{
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    
    Prob2Sort<char> rc;
    
    bool ascending=true;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    
    int column;
    cin>>column;
    
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
        {
            cout<<zc[i*16+j];
        }
    }
    
    delete []zc;
    
    cout<<endl;
    
    return 0;
}

