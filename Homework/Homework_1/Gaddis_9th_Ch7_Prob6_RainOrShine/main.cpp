/* 
 * File:   main.cpp
 * Author: seang
 */

#include <fstream>
#include <iostream>

using namespace std;
int main(int argc, char** argv) 
{
    const int ROW = 3;
    const int COL = 30;
    
    char ros[ROW][COL];
    
    int rain1, rain2, rain3, rainT;
    rain1 = rain2 = rain3 = 0;
    int cloud1, cloud2, cloud3, cloudT;
    cloud1 = cloud2 = cloud3 = cloudT = 0;
    int sun1, sun2, sun3, sunT;
    sun1 = sun2 = sun3 = sunT = 0;
    
    ifstream inputfile("RainOrShine.dat");
    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            inputfile >> ros[i][j];
        }
    }
    
    for(int i=0, j=0;j<COL; j++)
    {
        if(ros[i][j]=='R')
        {
            rain1++;
        }
        if(ros[i][j]=='S')
        {
            sun1++;
        }
        if(ros[i][j]=='C')
        {
            cloud1++;
        }
    }
    for(int i=1, j=0;j<COL; j++)
    {
        if(ros[i][j]=='R')
        {
            rain2++;
        }
        if(ros[i][j]=='S')
        {
            sun2++;
        }
        if(ros[i][j]=='C')
        {
            cloud2++;
        }
    }
    for(int i=2, j=0;j<COL; j++)
    {
        if(ros[i][j]=='R')
        {
            rain3++;
        }
        if(ros[i][j]=='S')
        {
            sun3++;
        }
        if(ros[i][j]=='C')
        {
            cloud3++;
        }
    }
    
    cloudT = cloud1 + cloud2 + cloud3;
    rainT = rain1 + rain2 + rain3;
    sunT = sun1 + sun2 + sun3;
    
    for(int i=0; i<ROW; i++)
    {
        if(i == 0)
        {
            cout<<"Jun: ";
        }
        else if(i == 1)
        {
            cout<<"Jul: ";
        }
        else if(i == 2)
        {
            cout<<"Aug: ";
        }
        for(int j=0; j<COL; j++)
        {
            cout << ros[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<"\nJun Rain:  "<<rain1;
    cout<<"\nJul Rain:  "<<rain2;
    cout<<"\nAug Rain:  "<<rain3;
    cout<<"\nJun Cloud: "<<cloud1;
    cout<<"\nJul Cloud: "<<cloud2;
    cout<<"\nAug Cloud: "<<cloud3;
    cout<<"\nJun Sun:   "<<sun1;
    cout<<"\nJul Sun:   "<<sun2;
    cout<<"\nAug Sun:   "<<sun3;
    cout<<"\n\nTotal Rain:  "<<rainT;
    cout<<"\nTotal Cloud: "<<cloudT;
    cout<<"\nTotal Sun:   "<<sunT<<endl<<endl;
    if(rain1>rain2 && rain1>rain3)
    {
        cout<<"Jun had the most rain.";
    }
    else if(rain2>rain1 && rain2>rain3)
    {
        cout<<"Jul had the most rain.";
    }
    else
    {
        cout<<"Aug had the most rain.";
    }
    
    
    return 0;
}

