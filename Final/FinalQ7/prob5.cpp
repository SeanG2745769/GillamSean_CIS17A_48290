/* 
 * File:   Prob5.cpp
 * Author: seang
 * 
 * Created on December 16, 2022, 12:04 PM
 */

#include <iostream>
#include <string>
#include <cstring>
#include "prob5.h"

using namespace std;

Employee::Employee(char s1[],char s2[],float num)
{
    strcpy(MyName,s1);
    strcpy(JobTitle,s2);
    
    if((num>200) or (num<0))
        HourlyRate = 0;
    else
        HourlyRate = num;
    
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::CalculatePay(float rate,int hours)
{
    return getNetPay(getGrossPay(setHourlyRate(rate),setHoursWorked(hours)));
}

float Employee::getGrossPay(float hourRate, int hourWork)
{

    if(hourWork <= 40)
        GrossPay = hourRate * hourWork;
    else if(hourWork > 40 && hourWork <=50)
        GrossPay = ((40*hourRate) + ((hourWork - 40)*hourRate*1.5));
    else
        GrossPay = ((40*hourRate) + (10*hourRate*1.5)) +
                ((hourWork - 50)*hourRate*2);
    return GrossPay;
}

float Employee::getNetPay(float gross)
{
    NetPay = gross - Tax(gross);
    return NetPay;
}

void Employee::toString()
{
    cout <<"\n Name = "<<MyName<<" Job Title = "<<JobTitle 
            <<"\n Hourly Rate = "<<HourlyRate<<" Hours Worked = " 
            <<HoursWorked<<" Gross Pay = "<<GrossPay<<" Net Pay = " 
            <<NetPay<<endl;
}

int Employee::setHoursWorked(int hours)
{
    if(hours < 0 || hours > 84)
    {
        cout<<"Unacceptable Hours Worked"<<endl;
        HoursWorked=0;
    }
    else
        HoursWorked = hours;
    return HoursWorked;
}

float Employee::setHourlyRate(float rate)
{
    if(rate<0 || rate>200)
    {
        cout<<"Unacceptable Hourly Rate"<<endl;
        HourlyRate=0;
    }
    else
        HourlyRate=rate;
    return HourlyRate;
}

double Employee::Tax(float pay)
{
    double tax; //I know you don't like doubles but I was just matching the
                //provided code.
    if(pay<500)
        tax = pay * .1;
    else if(pay>=500 && pay < 1000)
        tax = 50 + ((pay - 500)*.2);
    else
        tax = 50 + 100 + ((pay - 1000)*.3);
    return tax;
}