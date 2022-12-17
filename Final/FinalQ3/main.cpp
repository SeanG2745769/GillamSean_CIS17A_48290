/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on December 16, 2022, 10:17 AM
 */

#include <iostream>
#include "prob3.h"

using namespace std;

int main(int argc, char** argv) 
{
    cout<<"Entering problem number 3"<<endl;
    
    int rows=5;
    int cols=6;
    
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    
    const int *naugT=tab.getTable();
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
    
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

