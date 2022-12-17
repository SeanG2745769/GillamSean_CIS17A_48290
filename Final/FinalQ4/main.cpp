/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on December 16, 2022, 10:47 AM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "prob4.h"

using namespace std;

int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    cout<<endl;
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total(0.10,7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive(0.10,7)
        <<" Recursive Calculation "<<endl;
    
    return 0;
}

