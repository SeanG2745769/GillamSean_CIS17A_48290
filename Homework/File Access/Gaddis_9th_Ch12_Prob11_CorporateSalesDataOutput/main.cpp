/* 
 * File: Structure practice
 * Author: Sean Gillam
 * 
 * Created on: 2022-10-15
 * 
 * Purpose: Take is sales data and then output averages and totals.
 * Write a program that uses a structure to store the following data on a 
 * company division:
 * - Division Name (such as East, West, North, or South)
 * - Quarter(1,2,3,4)
 * - Quarterly Sales
 * The user should be asked for the four quarters' sales figures for the East,
 * West, North, and South divisions. The data for each quarter for each division
 * should be written to a file.
 * 
 * Input Validation: Do not accept negative numbers for any sales figure
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int SIZE = 4;
const int NAME_SIZE = 50;

struct Info
{
    char   name[NAME_SIZE];
    float  sales[SIZE];
    int    quarter[SIZE];
};

int main(int argc, char** argv) {
    struct Info division[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
            division[i].quarter[j]=j+1;
    }
    strcpy(division[0].name,"North");
    strcpy(division[1].name,"East");
    strcpy(division[2].name,"South");
    strcpy(division[3].name,"West");
    
    for(int i=0;i<SIZE;i++)
    {
        cout<<division[i].name<<endl;
        for(int j=0;j<SIZE;j++)
        {
            cout<<"Enter Quarter "<<division[i].quarter[j]<<" sales:";
            cin >> division[i].sales[j];
            if(division[i].sales[j]<0)
                throw invalid_argument("Received negative value for sales.");
        }
        cout<<endl;
    }
    fstream data("data.bin",ios::out|ios::binary);
    data.write(reinterpret_cast<char *>(&division),sizeof(division));
    data.close();
    
    return 0;
}