/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 22nd, 2021, 1:30 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVec(vector<int>,int,int);
void prntVec(vector<vector<int>>,int,int);
void fillVec(int,int,int,vector<int>);
void fillVec(int,int,vector<vector<int>>);
void fillVec(vector<vector<int>>,vector<int>,int,int);
//void destroy(int **,int);
void fillVec(vector<vector<int>>,vector<int>,int,int,int);
void swap(int &,int &);
void smlLst(vector<int>,int,int);
void mrkSort(vector<int>,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector<int> avec;//    int *array;
    vector<int> bvec;//    int *brray;
    vector<int> cvec;//    int *crray;
    vector<vector<int>> table;//    int **table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillVec(rowsize,highRng,lowRng,avec);
    fillVec(rowsize,highRng/10,lowRng/10,bvec);
    fillVec(rowsize,highRng/100,lowRng/100,cvec);
    
    //Sort the array the for all positions
    mrkSort(avec,rowsize);
    mrkSort(bvec,rowsize);
    mrkSort(cvec,rowsize);
    
    //Fill the 2-D array
    fillVec(rowsize,colsize,table);
    fillVec(table,avec,rowsize,0);
    fillVec(table,bvec,rowsize,1);
    fillVec(table,cvec,rowsize,2);
    
    //Print the values in the array
    prntVec(avec,rowsize,perLine);
    prntVec(bvec,rowsize,perLine);
    prntVec(cvec,rowsize,perLine);
    prntVec(table,rowsize,colsize);
    
    //Cleanup
//    delete []array;
//    delete []brray;
//    delete []crray;
//    destroy(table,rowsize);

    //Exit
    return 0;
}

//void destroy(int **a,int rows){
//    for(int row=0;row<rows;row++){
//        delete []a[row];
//    }
//    delete []a;
//}

void fillVec(vector<vector<int>> v,vector<int> c,int rowSize,int wchCol){
    for(int row=1;row<rowSize+1;row++){
        v[row].push_back(c[row]);
    }
}

void fillVec(int n,int hr,int lr,vector<int> abc){
    n=n<2?2:n;
    vector<int> v;//int *a=new int[n];
    for(int indx=1;indx<n+1;indx++){
        v.push_back(rand()%(hr-lr+1)+lr); //v[indx]=rand()%(hr-lr+1)+lr;
    }
    abc = v;
}

void fillVec(int rows,int cols, vector<vector<int>> t){
    //Allocate Memory for 2-D Array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    vector<vector<int>> v;//int **a=new int*[rows];
//    for(int row=0;row<rows;row++){
//        a[row]=new int[cols];
//    }
    //Fill it with 0's
    for(int row=1;row<rows+1;row++){
        vector<int> temp;
        for(int col=1;col<cols+1;col++){
            temp.push_back(0);//v[row][col]=0;
        }
        v.push_back(temp);
    }
    t=v;
}

void prntVec(vector<vector<int>> v,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
    for(int row=1;row<rowsize+1;row++){
        for(int col=1;col<colsize+1;col++){
            cout<<setw(4)<<v[row][col];
        }
        cout<<endl;
    }
}

void prntVec(vector<int> v,int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=1;indx<n+1;indx++){
        cout<<v[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> v,int n){
    for(int pos=1;pos<n;pos++){
        smlLst(v,n,pos);
    }
}

void smlLst(vector<int> v,int n,int pos){
    for(int i=pos+2;i<n+1;i++){
        if(v[pos]>v[i]){
            swap(v[pos],v[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}