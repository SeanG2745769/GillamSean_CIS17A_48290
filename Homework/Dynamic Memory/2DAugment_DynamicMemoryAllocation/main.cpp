/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on September 24, 2022, 10:46 PM
 */

#include <iostream>

using namespace std;

int **getData(int &,int &);                //Get matrix data
int **augment(const int * const *,int,int);//Augment the original array
void prntDat(const int* const *,int,int);  //Print matrix
void destroy(int **,int,int);              //Destroy matrix

int main(int argc, char** argv) 
{
    int row = 0;
    int col = 0;
    
    int **arr = getData(row,col);
    int **arrA = augment(arr,row,col);
    
    prntDat(arr,row,col);
    cout<<endl;
    prntDat(arrA,row+1,col+1);
    
    destroy(arr,row,col);
    destroy(arrA,row+1,col+1);
    
    return 0;
}

int **getData(int &r,int &c)
{
    cin>>r>>c;
    int **a = new int*[r];
    for(int i=0; i<r;i++)
    {
        a[i] = new int[c];
        for(int j=0;j<c;j++)
        {
            cin>> a[i][j];
        }
    }
    
    return a;
}

int **augment(const int * const *original,int r,int c)
{
    int **a = new int*[r+1];
    for(int i=0; i<r+1;i++)
    {
        a[i] = new int[c+1];
    }
    
    for(int j=0;j<c+1;j++)
        a[0][j] = 0;
    for(int i=0;i<r+1;i++)
        a[i][0] = 0;
    for(int i=1;i<r+1;i++)
    {
        for(int j=1;j<c+1;j++)
            a[i][j] = original[i-1][j-1];
    }
    
    return a;
}

void prntDat(const int* const *a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j];
            if(j<c-1)
                cout<<" ";
        }
        if(i<r-1)
            cout<<endl;
    }
}

void destroy(int **a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        delete [] a[i];
    }
    delete a;
}