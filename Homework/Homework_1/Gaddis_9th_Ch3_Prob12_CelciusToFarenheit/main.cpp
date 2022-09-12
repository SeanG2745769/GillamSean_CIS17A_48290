/* 
 * File:   main.cpp
 * Author: Sean Gillam
 *
 */

#include <iostream>

using namespace std;
int main(int argc, char** argv) 
{
    float tempC;
    float tempF;
    
    cout<<"Enter degrees Celsius (float): ";
    cin>>tempC;
    tempF=((9*tempC)/5)+32;
    cout<<"Degrees in Fahrenheit: ";
    cout<<tempF;
    
    return 0;
}

