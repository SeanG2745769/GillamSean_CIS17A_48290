/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 11:09 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    cout<<"Base 10: 49.1875\n";
    cout<<"Base 2 : 110001.0011\n";
    cout<<"Base 8 : 60.14\n";
    cout<<"Base 16: 30.3\n";
    cout<<"NASA FLOAT: 62600006\n";
    cout<<endl;
    
    cout<<"Base 10: 3.07421875\n";
    cout<<"Base 2 : 11.0010011\n";
    cout<<"Base 8 : 3.046\n";
    cout<<"Base 16: 3.13\n";
    cout<<"NASA FLOAT: 62600002\n";
    cout<<endl;
    
    cout<<"Base 10: 0.2\n";
    cout<<"Base 2 : 0.0011 Repeating\n";
    cout<<"Base 8 : 0.1463 Repeating\n";
    cout<<"Base 16: 0.3    Repeating\n";
    cout<<"NASA FLOAT: 666666FE\n";
    cout<<endl;
    
    cout<<"Base 10: -49.1875\n";
    cout<<"NASA FLOAT Base 2 : 10011101 10100000 00000000 00000110\n";
    cout<<"NASA FLOAT Base 8 : 23550000006\n";
    cout<<"NASA FLOAT Base 16: 9DA00006\n";
    cout<<endl;
    
    cout<<"Base 10: -3.07421875\n";
    cout<<"NASA FLOAT Base 2 : 10011101 10100000 00000000 00000010\n";
    cout<<"NASA FLOAT Base 8 : 23550000002\n";
    cout<<"NASA FLOAT Base 16: 9DA00002\n";
    cout<<endl;
    
    cout<<"Base 10: -0.2\n";
    cout<<"NASA FLOAT Base 2 : 10011001 10011001 10011010 1111110\n";
    cout<<"NASA FLOAT Base 8 : 23146315376\n";
    cout<<"NASA FLOAT Base 16: 99999AFE\n";
    cout<<endl;
    
    cout<<"Base 16: 69999902\n";
    cout<<"Decimal: 3.29999714\n";
    cout<<endl;
    
    cout<<"Base 16: 69999903\n";
    cout<<"Decimal: 6.59999942\n";
    cout<<endl;
    
    cout<<"Base 16: 966667FF\n";
    cout<<"Decimal: 0.41249996\n";
    cout<<endl;
    return 0;
}

