/* 
 * File:   main.cpp
 * Author: Sean Gillam
 *
 */

#include <iostream>

using namespace std;

float celcius(float);

int main(int argc, char** argv) 
{
    float tempC;
    float tempF;

    cout<<"F   C\n";
    for(int i = 0; i < 20; i++)
    {
        tempF = i;
        tempC = celcius(tempF);
        cout<<tempF<<"   "<<tempC<<endl;
    }
    
    return 0;
}

float celcius(float f)
{
    float c;
    c=(5*(f-32))/9;
    return c;
}
