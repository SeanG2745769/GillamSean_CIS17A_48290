/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 6:26 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);           //Fill the array
int *sort(const int *,int);    //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order
void prntDat(const int *,int,bool); //Print the array (added bool for return char
                                    //                  formatting)

int main(int argc, char** argv) 
{
    bool ret;
    // Setting a starting value to be passed
    int size = 0;
    // Passing size by reference and creating in array
    int *arr = getData(size); // getData fills the array and corrects size
    int *arrS = sort(arr, size); // sort the array
    int *arrR = reverse(arrS, size); // reverse the sorted array
    
    ret = true;
    prntDat(arrS,size,ret);
    ret = false;
    prntDat(arrR,size,ret);
    
    delete [] arr;
    delete [] arrS;
    delete [] arrR;
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

int *sort(const int *arr_f,int s)
{
    int *a = new int[s];
    for(int i=0;i<s;i++)
        a[i] = arr_f[i];
    bool check;
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s-i-1; j++)
        {
            // Compare values
            if( a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
                check = true;
            }
        }
        // If no to elements are swapped then
        // array is sorted. Hence Break the loop.
        if(!check)
            break;
    }
    
    return a;
}

int *reverse(const int *arr_f2,int s)
{
    int *r = new int[s];
    for(int i=0;i<s;i++)
    {
        r[i] = arr_f2[i];
    }
    int start = 0;
    int end = s-1;
    while(start < end)
    {
        swap(r[start],r[end]);
        start++;
        end--;
    }
    return r;
}

void prntDat(const int *a,int s,bool b)
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

