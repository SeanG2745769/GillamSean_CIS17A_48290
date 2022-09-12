/* 
 * File:   main.cpp
 * Author: Sean Gillam
 */

#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
    int month, year, remainder, remainder2;
    
    while((month < 1) || (month > 12))
    {
        cout<<"Enter a month (1-12): ";
        cin>>month;
        if((month < 1) || (month > 12))
        {
            cout<<"Invalid month!\n";
        }
    }
    cout<<"Enter a year: ";
    cin>>year;
    
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 ||
            month==12)
    {
        cout<<"31 Days";
    }
    if(month==4 || month==6 || month==9 || month==11)
    {
        cout<<"30 Days";
    }
    if(month == 2)
    {
        remainder = year % 100;
        remainder2 = year % 4;
        if(remainder==0)
        {
            remainder = year % 400;
            if(remainder==0)
            {
                cout<<"29 Days";
            }
            else
            {
                cout<<"28 Days";
            }
        }
        else if(remainder2 == 0)
        {
            cout<<"29 Days";
        }
        else
        {
            cout<<"28 Days";
        }
    }
    
    return 0;
}

