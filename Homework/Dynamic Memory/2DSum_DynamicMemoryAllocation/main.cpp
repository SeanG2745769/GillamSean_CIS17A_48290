/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 7:55 PM
 */

#include <iostream>

using namespace std;

int **getData(int &,int &);              //Return the 2-D array and its size.
int sum(const int * const *, int,int);   //Return the Sum
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);            //Deallocate memory

int main(int argc, char** argv) 
{
    // Setting a starting value to be passed
    int row = 0;
    int col = 0;
    // Passing size by reference and creating in array
    int **arr = getData(row,col); // getData fills the array and corrects size
    int arrS = sum(arr,row,col); // sum the array
    prntDat(arr,row,col);
    cout<<arrS;
    
    destroy(arr,row,col);
    
    return 0;
}

int **getData(int &r,int &c)
{
    cin>>r>>c; //Reading in input row, col
    int **arr_f = new int*[r];//Creating a dynamic array to be loaded
    for(int i=0; i<r;i++)
    {
        arr_f[i] = new int[c];
        for(int j=0;j<c;j++)
        {
            cin>> arr_f[i][j];
        }
    }
//    for(int i=0;i<colIn;i++)
//        arr_f[i] = new int[colIn];
//    for(int i=0;i<rowIn;i++)
//    {
//        for(int j=0;j<colIn;j++)
//        {
//            cin>>arr_f[i][j]; //in integers
//        }
//    }
    return arr_f;//returning array address
}

int sum(const int * const *a2,int r,int c)
{
    int s = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            s = s + a2[i][j];
        }
    }
    return s;
}

void prntDat(const int* const *arr,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j];
            if(j<c-1)
                cout<<" ";
        }
        cout<<endl;
    }
}

void destroy(int **arr2,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        delete [] arr2[i];
    }
    delete arr2;
}