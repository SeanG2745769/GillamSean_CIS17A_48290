/* 
 * File:   main.cpp
 * Author: seang
 *
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    float population=-1, percent=-1, days=0;
    
    while(population<2)
    {
        cout<<"Starting population (>2): ";
        cin>>population;
        if(population<2)
            cout<<"Invalid population!\n";
    }
    while(percent<0)
    {
        cout<<"Daily population increase % (>0): ";
        cin>>percent;
        if(percent<0)
            cout<<"Percent >0!\n";
    }
    while(days<1)
    {
        cout<<"Number of days (>1): ";
        cin>>days;
        if(days<1)
            cout<<"Days can not be less than 1!\n";
    }
    
    int i;
    for(i = days; i > 0; i--)
    {
        population = population + (population*(percent/100));
    }
    
    cout<<"New Population: "<<population;
    
    return 0;
}

