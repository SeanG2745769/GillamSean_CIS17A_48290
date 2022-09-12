/* 
 * File:   main.cpp
 * Author: Sean Gillam
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char** argv)
{
    const float YEN_PER_DOLLAR = 142.50;
    const float EUROS_PER_DOLLAR = 0.98;
    
    float dollar;
    float yen;
    float euro;
    
    cout<<"Enter amount in US Dollars (float): ";
    cin>>dollar;
    
    yen = YEN_PER_DOLLAR * dollar;
    euro = EUROS_PER_DOLLAR * dollar;
    
    cout<<fixed;
    cout<<"Yen: "<<setprecision(2)<<yen<<endl;
    cout<<"Euros: "<<setprecision(2)<<euro;
    
    return 0;
}

