/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    int nModes=0;
    //if(nModes!=0)stats->mode->data=new int[nModes]; MOVED TOO BELOW
    stats->modFreq=0;
    stats->median=0;
    //end code write by professor
    
    //begin code written by me
//    int freq=1;
//    //find the mode
//    //find mode occurences
//    for(int i=0;i<array->size-1;i++)
//    {
//        for(int j=i+1;j<array->size;j++)
//            if(array->data[i]==array->data[j])
//                freq++;
//        if(freq>stats->modFreq)
//            stats->modFreq=freq;
//        freq=1;
//    }
//    //if number of occurrences is greater than 1 check for other occurences
//    //greater than one
//    int freq2=1;
//    if(stats->modFreq>1)
//    {
//        for(int i=0;i<array->size-1;i++)
//        {
//            for(int j=i+1;j<array->data[j];j++)
//                if(array->data[i]==array->data[j])
//                    freq2++;
//            if(freq2==stats->modFreq)
//               nModes++;
//            freq2=1;
//        }
//    }
//    
//    //put modes into mode data array
//    freq2=1;
//    int k=0;
//    stats->mode->size=nModes;
//    if(nModes!=0)stats->mode->data=new int[nModes]; //MOVED CODE FROM ABOVE
//    if(stats->modFreq>1)
//    {
//        for(int i=0;i<array->size;i++)
//        {
//            for(int j=i+1;j<array->size;j++)
//                if(array->data[i]==array->data[j])
//                    freq2++;
//            if(freq2==stats->modFreq)
//            {
//                stats->mode->data[k]=array->data[i];
//                k++;
//            }
//            freq2=1;
//        }
//    }
    int most=1;
    int freq;
    for(int i=0;i<array->size;i++)
    {
        freq=0;
        for(int j=i;j<array->size;j++)
        {
            if(array->data[i]==array->data[j])
                freq++;
        }
        if(freq>=most && freq!=1)
        {
            most=freq;
            stats->mode->data[i] = nModes;
            nModes++;
        }
    }
    
    if(nModes!=0)stats->mode->data=new int[nModes];
    
    //Fill the mode array
    if(most == 1) {
        stats->mode->size = 0;
    }
    else {
        stats->mode->size = nModes;
    }
    //Mode frequency
    stats->modFreq = most;
    
    //Find Median
    //Place holder for position
    int medPlace;
    
    //Find the Median
    if(array->size%2 != 0) {
        medPlace = array->size/2;
        stats->median = array->data[medPlace];
    }
    else if(array->size%2 == 0) {
        medPlace = array->size/2;
        stats->median = (array->data[medPlace] + array->data[medPlace - 1]) / 2.0;
    }
    /*
    int count;
    int index = 0;
    for(int i=0;i<array->size-1;i++)
    {
        count=stats->modFreq;
        for(int j=i+1;j<array->size;i++)
        {
            if((array->data[i]==array->data[j])&&(i!=j)&&nModes!=0)
            {
                count--;
                if(count==0)
                {
                    stats->mode->data[index]=array->data[i];
                    nModes--;
                    index++;
                }
                    
            }
        }
    }
    */
    int half;
    //find the median
    if((array->size%2)!=0)//if odd
    {
        half = (array->size+1) / 2;
        stats->median = array->data[half-1];
    }
    else
    {
        int compOne = (array->size/2)-1;
        int compTwo = (array->size/2);
        stats->median = (array->data[compOne]+array->data[compTwo]/2.0);
    }
    
    //find the mean
    float sum = 0;
    for(int i=0;i<array->size;i++)
    {
        sum = sum + array->data[i];
    }
    stats->avg = sum/array->size;
    
    return stats;
}