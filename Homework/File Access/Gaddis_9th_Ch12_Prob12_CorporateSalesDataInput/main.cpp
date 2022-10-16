/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 15, 2022, 6:59 PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

const int SIZE = 4;
const int NAME_SIZE = 50;

struct Info
{
    char   name[NAME_SIZE];
    float  sales[SIZE];
    int    quarter[SIZE];
};

int main(int argc, char** argv)
{
    Info division[SIZE];
    Info corp;
    fstream data;
    
    data.open("data.bin",ios::in|ios::binary);
    if(!data)
    {
        cout<<"Error reading file!\n";
        return 0;
    }
    data.read(reinterpret_cast<char *>(&division),sizeof(division));
    
    //Total Per Quarter
    for(int i=0;i<SIZE;i++)
        corp.sales[i]=0;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
            corp.sales[i] = corp.sales[i] + division[j].sales[i];
    }
    //Divisional Totals
    float divTotal[SIZE];
    for(int i=0;i<SIZE;i++)
        divTotal[i]=0;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
            divTotal[i]=divTotal[i]+division[i].sales[j];
    }
    //Total Per year
    float corpTotal;
    corpTotal = 0;
    for(int i=0;i<SIZE;i++)
        corpTotal = corpTotal + corp.sales[i];
    //Average quarterly sales for divisions
    float divAverage[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        divAverage[i]=divTotal[i]/4;
    }
    //High Low Checks
    int highI, lowI;
    float high = 0;
    float low  = 99999999999;
    for(int i=0;i<SIZE;i++)
    {   
        if(corp.sales[i]<low)
        {
            low  = corp.sales[i];
            lowI = i;
        }
        if(corp.sales[i]>high)
        {
            high = corp.sales[i];
            highI = i;
        }
    }
    
    //Display
    cout<<fixed<<setprecision(2);
    cout<<"Total Corporate sales for each quarter:"<<endl;
    cout<<"Quarter 1: "<<corp.sales[0]<<endl;
    cout<<"Quarter 2: "<<corp.sales[1]<<endl;
    cout<<"Quarter 3: "<<corp.sales[2]<<endl;
    cout<<"Quarter 4: "<<corp.sales[3]<<endl;
    cout<<"Total yearly sales for each division:"<<endl;
    cout<<"North: "<<divTotal[0]<<endl;
    cout<<"East:  "<<divTotal[1]<<endl;
    cout<<"South: "<<divTotal[2]<<endl;
    cout<<"West:  "<<divTotal[3]<<endl;
    cout<<"Total yearly corporate sales: "<<corpTotal<<endl;
    cout<<"Average quarterly sales for the divisions:"<<endl;
    cout<<"North: "<<divAverage[0]<<endl;
    cout<<"East:  "<<divAverage[1]<<endl;
    cout<<"South: "<<divAverage[2]<<endl;
    cout<<"West:  "<<divAverage[3]<<endl;
    cout<<"Highest Quarter for the corporation: Quarter "<<highI+1<<endl;
    cout<<"High Sales: "<<corp.sales[highI]<<endl;
    cout<<"Lowest Quarter for the corporation: Quarter "<<lowI+1<<endl;
    cout<<"Lowest Sales: "<<corp.sales[lowI];
    
    return 0;
}

