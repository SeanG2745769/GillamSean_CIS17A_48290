/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 5:13 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *, int);     //Print the median Array

int main(int argc, char** argv) 
{
    // Seting a starting value to be passed
    int size = 0;
    // Passing size by reference and creating in array
    int *arrInt = getData(size); // getData fills the array and corrects size
    
    float *arrFlo = median(arrInt, size);
    
    prntDat(arrInt,size);
    prntMed(arrFlo,size);
    
    delete [] arrInt;
    delete [] arrFlo;
    return 0;
}

int *getData(int &size_f)
{
    int sizeIn;
    cin>>sizeIn; //Reading in input size
    int *arr_f = new int[sizeIn]; //Creating a dynamic array to be loaded
    for(int i=0;i<sizeIn;i++)
    {
        cin>>arr_f[i]; //in integers
    }
    size_f = sizeIn;// returning size
    
    return arr_f;//returning array address
}

void prntDat(int *a,int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        if(i<s-1)
            cout<<" ";
    }
    cout<<endl;
}

float *median(int *arr_f2,int size_f2)
{
    float *arr_f3 = new float[size_f2+2];
    for(int i=2;i<size_f2+2;i++)
    {
        arr_f3[i] = arr_f2[i-2]*1.0;
    }
    float *arr_f4 = new float[size_f2];
    for(int i=0;i<size_f2;i++)
    {
        arr_f4[i] = arr_f2[i]*1.0;
    }
    bool check;
    for(int i = 0; i < size_f2; i++)
    {
        for(int j = 0; j < size_f2-i-1; j++)
        {
            // Compare values
            if( arr_f4[j] > arr_f4[j+1])
            {
                swap(arr_f4[j],arr_f4[j+1]);
                check = true;
            }
        }
        // If no to elements are swapped then
        // array is sorted. Hence Break the loop.
        if(!check)
            break;
    }
    arr_f3[0] = size_f2+2;
    if((size_f2%2)!=0)//if odd
    {
        int temp = size_f2/2;
        float median = arr_f4[temp];
        arr_f3[1] = median;
    }
    else //if even
    {
        int ind1 = (size_f2/2) - 1;
        int ind2 = size_f2/2;
        float median = (arr_f4[ind1] + arr_f4[ind2])/2.0;
        arr_f3[1] = median;
    }
    
    return arr_f3;
}

void prntMed(float *a,int s)
{
    cout<<a[0]<<" ";
    for(int i=1;i<s+2;i++)
    {
        cout<<fixed<<setprecision(2)<<a[i];
        if(i<s+1)
            cout<<" ";
    }
}

