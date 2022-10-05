/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 10:28 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);
int *augment(const int *,int);
void prntAry(const int *,int);

int main(int argc, char** argv) 
{
    int size = 0;
    int *arr = getData(size);
    int *arrA = augment(arr, size);
    
    prntAry(arr,size);
    cout<<endl;
    prntAry(arrA,size+1);
    
    delete [] arr;
    delete [] arrA;
    return 0;
}

int *getData(int &size_f)
{
    cin>>size_f;
    int *arr_f = new int[size_f];
    for(int i=0;i<size_f;i++)
        cin>>arr_f[i];
    
    return arr_f;
}

int *augment(const int *arr_f,int size_f)
{
    int *arr_f2 = new int[size_f+1];
    for(int i=0;i<size_f;i++)
    {
        arr_f2[i+1] = arr_f[i];
    }
    arr_f2[0]=0;
    
    return arr_f2; 
}

void prntAry(const int *arr_f,int size_f)
{
    for(int i=0;i<size_f;i++)
    {
        cout<<arr_f[i];
        if(i<size_f-1)
            cout<<" ";
    }
}