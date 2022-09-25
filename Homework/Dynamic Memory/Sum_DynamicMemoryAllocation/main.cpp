/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 7:19 PM
 */

#include <iostream>

using namespace std;

int *getData(int &);           //Fill the array
int *sumAry(const int *,int);  //Return the array with successive sums
void prntAry(const int *,int,bool); //Print the array

int main(int argc, char** argv) 
{
    bool ret;
    // Setting a starting value to be passed
    int size = 0;
    // Passing size by reference and creating in array
    int *arr = getData(size); // getData fills the array and corrects size
    int *arrS = sumAry(arr, size); // sort the array
    
    ret = true;
    prntAry(arr,size,ret);
    ret = false;
    prntAry(arrS,size,ret);
    
    delete [] arr;
    delete [] arrS;
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

int *sumAry(const int *a,int s)
{
    int *arr_f2 = new int[s];
    arr_f2[0] = 0;
    for(int i=0;i<s;i++)
    {
        arr_f2[i] = a[i] + arr_f2[i-1];
    }
    return arr_f2;
}

void prntAry(const int *a,int s,bool b)
{
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        if(i<s-1)
            cout<<" ";
    }
    if(b == true)
        cout<<endl;
}
