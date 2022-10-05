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

//Global Constant


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
    int i = 0;
    //Read In some stuff
    for(i = 0; i < MAX_LENGTH; i++)
    {
        cin >> month[i].name;
        cin >> month[i].totalRain;
        cin >> month[i].lowTemp;
        cin >> month[i].highTemp;
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
    for(int i2 = 0; i2 < MAX_LENGTH; i2++)
    {
        hold2 = hold2 + month[i2].totalRain;
    }
    aRain = (hold2 / (12.0));
    
    for(int i3 = 0; i3 < MAX_LENGTH; i3++)
    {
        if(lowTemp > month[i3].lowTemp)
        {
            lowTemp = month[i3].lowTemp;
            arrayCount = i3;
        }
    }
    
    for(int i4 = 0; i4 < MAX_LENGTH; i4++)
    {
        if(highTemp < month[i4].highTemp)
        {
            highTemp = month[i4].highTemp;
            arrayCount2 = i4;
        }
    }
    
    float hold = 0;
    for(int i5 = 0; i5 < MAX_LENGTH; i5++)
    {
        hold = hold + month[i5].avgTemp;
    }
    aTemp = (hold /(12));
    
    //Display
    cout <<fixed << setprecision(1)<< "Average Rainfall " << aRain << " inches/month\n";
    cout <<fixed << setprecision(0)<< "Lowest  Temperature " << month[arrayCount].name << "  " << lowTemp
            << " Degrees Fahrenheit\n";
    cout << "Highest Temperature " << month[arrayCount2].name << "  " << highTemp
            << " Degrees Fahrenheit\n";
    cout << "Average Temperature for the year " << aTemp << " Degrees "
            "Fahrenheit\n";
    
    return 0;
}