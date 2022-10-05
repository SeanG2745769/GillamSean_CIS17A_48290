/* 
 * File: Structure practice
 * Author: Sean Gillam
 * Created on: 2021-10-05
 * Purpose: Take is sales data and then output averages and totals.
 * Write a program that uses a structure to store the following data on a company division:
 * Division Name(such as East, West, North, or South)
 * First-Quarter Sales 
 * Second-Quarter Sales
 * Third-Quarter Sales
 * Fourth-Quarter Sales
 * Total Annual Sales
 * Average Quarterly Sale 
 * The program should use four variables of this structure. Each variable should
 * represent on of the following corporate divisions: East, West, North, and South.
 * The user should be asked for the four quarters' sales figures for each division.
 * Each division's total and average sales should be calculated and stored in the
 * appropriate member of each structure variable. These figures should then be 
 * displayed on the screen.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//Structure
struct Div
{
    float firstQ;
    float secondQ;
    float thirdQ;
    float fourthQ;
    float average;
    float total;
};
//Function Prototypes
void readIn(int divCount, float* Q1, float* Q2, float* Q3, float* Q4); //Reads in sales from user
float average(float* Q1A, float* Q2A, float* Q3A, float* Q4A); //Averages Sales from the Quarters
float total(float* Q1T, float* Q2T, float* Q3T, float* Q4T); // Totals Sales from the Quarters
void display(int divCount, float* Q1D, float* Q2D, float* Q3D, float* Q4D, float*
             aSales, float* tSales); // Displays the figures from total and average
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    struct Div north;
    struct Div east;
    struct Div south;
    struct Div west;
    //Initialize Variables
    //North Computing
    readIn(1, &north.firstQ, &north.secondQ, &north.thirdQ, &north.fourthQ);
    
    north.average = average(&north.firstQ, &north.secondQ, &north.thirdQ, &north.fourthQ);
    
    north.total = total(&north.firstQ, &north.secondQ, &north.thirdQ, &north.fourthQ);
    
    display(1, &north.firstQ, &north.secondQ, &north.thirdQ, &north.fourthQ,
            &north.average, &north.total);
    
    //West Computing
    readIn(2, &west.firstQ, &west.secondQ, &west.thirdQ, &west.fourthQ);
    
    west.average = average(&west.firstQ, &west.secondQ, &west.thirdQ, &west.fourthQ);
   
    west.total = total(&west.firstQ, &west.secondQ, &west.thirdQ, &west.fourthQ);
    
    display(2, &west.firstQ, &west.secondQ, &west.thirdQ, &west.fourthQ,
            &west.average, &west.total);
    
    //East Computing
    readIn(3, &east.firstQ, &east.secondQ, &east.thirdQ, &east.fourthQ);
    
    east.average = average(&east.firstQ, &east.secondQ, &east.thirdQ, &east.fourthQ);
    
    east.total = total(&east.firstQ, &east.secondQ, &east.thirdQ, &east.fourthQ);
    
    display(3, &east.firstQ, &east.secondQ, &east.thirdQ, &east.fourthQ,
            &east.average, &east.total);
    
    //South Computing
    readIn(4, &south.firstQ, &south.secondQ, &south.thirdQ, &south.fourthQ);
    
    south.average = average(&south.firstQ, &south.secondQ, &south.thirdQ, &south.fourthQ);
    
    south.total = total(&south.firstQ, &south.secondQ, &south.thirdQ, &south.fourthQ);
    
    display(4, &south.firstQ, &south.secondQ, &south.thirdQ, &south.fourthQ,
            &south.average, &south.total);
    
    
    //Exit stage right!
    return 0;
}

void readIn(int divCount, float* Q1, float* Q2, float* Q3, float* Q4)
{
    string divName;
    //Process or map Inputs to Outputs
    switch(divCount)
    {
        case 1:
            divName = "North";
            break;
        case 2:
            divName = "West";
            break;
        case 3:
            divName = "East";
            break;
        case 4:
            divName = "South";
    }
    cout << divName <<"\nEnter first-quarter sales:";
    cin >> *Q1;
    cin.ignore();
    cout <<"\nEnter second-quarter sales:";
    cin >> *Q2;
    cin.ignore();
    cout <<"\nEnter third-quarter sales:";
    cin >> *Q3;
    cin.ignore();
    cout <<"\nEnter fourth-quarter sales:";
    cin >> *Q4;
    cin.ignore();
    cout << endl;
}

float average(float* Q1A, float* Q2A, float* Q3A, float* Q4A)
{
    float average;
    //Oh yeah pointers suck for math stuff so we gotta DEREFERNCE OH YEAH
    float quart1 = *Q1A;
    float quart2 = *Q2A;
    float quart3 = *Q3A;
    float quart4 = *Q4A;
    average = ((quart1 + quart2 + quart3 + quart4)/4);
    return average;
}

float total(float* Q1T, float* Q2T, float* Q3T, float* Q4T)
{
    float total;
    float quart1 = *Q1T;
    float quart2 = *Q2T;
    float quart3 = *Q3T;
    float quart4 = *Q4T;
    total = quart1 + quart2 + quart3 + quart4;
    return total;
}

void display(int divCount, float* Q1D, float* Q2D, float* Q3D, float* Q4D, float* 
             aSales, float* tSales)
{
    //This switch is still here because i cant be bothered to remove it and
    // I liked how the program ran before i realized I had had to match the testcases on codeE
    string divName;
    switch(divCount)
    {
        case 1:
            divName = "North";
        case 2:
            divName = "East";
        case 3:
            divName = "West";
        case 4:
            divName = "South";
    }
    cout << "Total Annual sales:$";
    cout << fixed << setprecision(2) << *tSales <<endl;
    cout << "Average Quarterly Sales:$";
    cout << fixed << setprecision(2) << *aSales;
    //Code E is dumb so to pass the testcase we need this part:
    if(divCount < 4)
    {
        cout << endl; //Code-E really wants me to NOT put a endl after the final output so fine. Now it doesn't....
    }
} 