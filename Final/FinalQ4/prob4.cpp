/* 
 * File:   prob4.cpp
 * Author: seang
 * 
 * Created on December 16, 2022, 10:47 AM
 */

#include <cstdlib>
#include <iostream>
#include "prob4.h"

using namespace std;

SavingsAccount::SavingsAccount(float b)
{
    if(b>0)
        Balance=b;
    else
        Balance=0;
    FreqDeposit=0;
    FreqWithDraw=0;
}

void SavingsAccount::Transaction(float amount)
{
    if(amount>0)
        Deposit(amount);
    else
        Withdraw(amount);
}

float SavingsAccount::Deposit(float d)
{
    Balance = Balance + d;
    FreqDeposit++;
    
    return Balance;
}

float SavingsAccount::Withdraw(float w)
{
    float hold = Balance;
    hold = hold + w;

    if(hold<0)
    {
        cout<<"WithDraw not Allowed"<<endl;
        return Balance;
    }
    else
    {
        Balance = Balance + w;
        FreqWithDraw++;

        return Balance;
    }
    

}

void SavingsAccount::toString()
{
    cout<<"Balance="<<Balance<<endl;
    cout<<"WithDraws="<<FreqWithDraw<<endl;
    cout<<"Deposits="<<FreqDeposit<<endl;
}

float SavingsAccount::Total(float rate, int year)
{
    float total=Balance;
    for(int i=0;i<year;i++)
    {
        total=total+(Balance*rate);
    }
    return total;
}

float SavingsAccount::TotalRecursive(float rate, int year)
{
    Balance=Balance+(Balance*rate);
    year--;
    if(year<1)
        return Balance;
    else
        TotalRecursive(rate, year);
}