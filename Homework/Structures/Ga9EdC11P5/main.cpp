/*
It never rains when it pours.

Weather Statistics

Write a program that uses a structure to store the following weather data for a particular

month:

Month

Total Rainfall - Inches

High Temperature - Degrees Fahrenheit

Low Temperature -Degrees Fahrenheit

Average Temperature - Degrees Fahrenheit

The program should have an array of 12 structures to hold weather data for an

entire year. When the program runs, it should ask the user to enter data for each

month. (The average temperature should be calculated.) Once the data are entered

for all the months, the program should calculate and display the average monthly

rainfall, the total rainfall for the year, the highest and lowest temperatures for the

year (and the months they occurred in), and the average of all the monthly average

temperatures.

Input Validation: Only accept temperatures within the range between –100 and +140

degrees Fahrenheit.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Enumerated Data Types
enum mon
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
    LAST
};
//Structure Declaration
struct weather
{
    string name;
    float totalRain;
    float highTemp;
    float lowTemp;
    float avgTemp;
};

//Main
int main(){
    //constant declaration
    const int NUM_OF_MONTHS = 12;
    const float MAX_TEMP = 141;
    const float LOW_TEMP = -100;
    const int MAX_LENGTH = 12;
    
    //structure declaration
    struct weather month[NUM_OF_MONTHS];
    
    //Variable declaration
    float lowTemp = 140;
    float highTemp = -100;
    float aTemp = 0;
    float aRain = 0;
    int input = 0;
    int arrayCount;
    int arrayCount2;
    int i;
    
    //Read In some stuff
    for(auto mon : {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE})
    {
        i = mon;
        cout<<"Enter the total rainfall for the month:"<<endl;
        cin >> month[i].totalRain;
        cout<<"Enter the high temp:"<<endl;
        cin >> month[i].highTemp;
        cout<<"Enter the low temp:"<<endl;
        cin >> month[i].lowTemp;
        
        month[i].avgTemp = ((month[i].lowTemp + month[i].highTemp)/2);
        //input Validation
        if((month[i].lowTemp < -100) or (month[i].highTemp < -100))
        {
            cout <<"invalid input\n";
            return 0;
        }
        if((month[i].lowTemp > 140) or (month[i].highTemp > 140))
        {
            cout <<"invalid input\n";
            return 0;
        }
    }

    //calculations
    float hold2 = 0;
    for(auto mon : {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE})
    {
        i = mon;
        hold2 = hold2 + month[i].totalRain;
    }
    aRain = (hold2 / (6.0));
    
    for(auto mon : {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE})
    {
        i = mon;
        if(lowTemp > month[i].lowTemp)
        {
            lowTemp = month[i].lowTemp;
            arrayCount = i;
        }
    }
    
    for(auto mon : {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE})
    {
        i = mon;
        if(highTemp < month[i].highTemp)
        {
            highTemp = month[i].highTemp;
            arrayCount2 = i;
        }
    }
    
    float hold = 0;
    for(auto mon : {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE})
    {
        i = mon;
        hold = hold + month[i].avgTemp;
    }
    aTemp = (hold /(6.0));
    
    //Display
    cout <<fixed<<setprecision(2)<<"Average monthly rainfall:"<<aRain<<endl;
    cout <<fixed<<setprecision(0)<<"High Temp:"<<highTemp<<endl;
    cout <<fixed<<setprecision(0)<<"Low Temp:"<<lowTemp<<endl;
    cout <<fixed<<setprecision(1)<<"Average Temp:"<<aTemp;
    
    return 0;
}