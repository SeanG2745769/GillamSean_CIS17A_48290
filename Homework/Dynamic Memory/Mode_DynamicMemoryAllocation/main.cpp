/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2019, 7:45 PM
 */

//The mode is simply the number which appears most often in a set/array.
//
//It must have a frequency of 2 or greater and there can be multiple modes.
//
//Here are examples!
//
//Find the mode of a set.
//
//Set = {1,2,3}
//
//Number of modes = 0, Frequency = 1, Mode set ={null}
//
//Set = {1,2,3,1}
//
//Number of modes = 1, Frequency = 2, Mode set = {1}
//
//Set = {1,2,3,1,2,3,1,2,3}
//
//Number of modes = 3, Frequency = 3, Mode set = {1,2,3}
//
//This requires you to analyze the array and create a dynamic array which is 
//sized according to how many elements are in the mode set.
//
//You will size the mode array to the exact number required, no larger.
//
//Here is how you will fill the mode array.
//
//modeAry[0] = Number of modes
//
//modeAry[1] = Frequency of the modes
//
//modeAry[>=2] = All the modes you found
//
//The size of the modeAry is 2 larger than the number of modes.
//
//The point of this exercise is that you cannot know beforehand how many modes 
//there are.  Therefore, there is no way to know the size of the array to place 
//the modes in till after you have take a count of the elements in the array.  
//It requires dynamic memory allocation of the mode array.
//
//So, how do you approach the problem. 
//
//     1) Copy the array so you don't modify the original contents.
//
//     2) Sort the array.
//
//     3) Step through the array and compare like elements.  Count like elements 
//        until it changes.  The maximum count identifies the mode.  All those 
//        with the maximum count must be one of the modes.  So now that you know
//        the max frequency, go back and count how many had the max frequency.  
//        Once you know this, then you can size the mode array and cycle back to
//        fill it.  Literally requires you to traverse the sorted array 3 times.
//
//This problem illustrates when dynamic memory allocation is required.
//
//I have supplied everything including a stub for the mode function which you
//must complete to get credit for the problem.

//Sample Input/Outputs
//IN:
//35·10
//OUT:
//The·program·finds·the·mode·of·a·set↵
//Input·the·size·of·the·array·and·quantity·of·unique·numbers↵
//The·Array·before·shuffling↵
//0·1·2·3·4·5·6·7·8·9·↵
//0·1·2·3·4·5·6·7·8·9·↵
//0·1·2·3·4·5·6·7·8·9·↵
//0·1·2·3·4·↵
//The·Array·after·shuffling↵
//7·2·2·4·4·9·0·9·8·3·↵
//6·4·0·5·3·4·1·8·3·3·↵
//1·0·9·7·5·0·6·2·1·6·↵
//8·5·7·2·1·↵
//The·Modal·Information↵
//The·number·of·modes·=·5↵
//The·max·Frequency·=·4↵
//The·mode·set·=·{0,1,2,3,4}↵

//IN:
//11·10
//OUT:
//The·program·finds·the·mode·of·a·set↵
//Input·the·size·of·the·array·and·quantity·of·unique·numbers↵
//The·Array·before·shuffling↵
//0·1·2·3·4·5·6·7·8·9·↵
//0·↵
//The·Array·after·shuffling↵
//7·4·2·5·9·0·1·6·0·8·↵
//3·↵
//The·Modal·Information↵
//The·number·of·modes·=·1↵
//The·max·Frequency·=·2↵
//The·mode·set·=·{0}↵

//IN:
//10·10
//OUT:
//The·program·finds·the·mode·of·a·set↵
//Input·the·size·of·the·array·and·quantity·of·unique·numbers↵
//The·Array·before·shuffling↵
//0·1·2·3·4·5·6·7·8·9·↵
//↵
//The·Array·after·shuffling↵
//0·4·7·8·5·3·1·9·2·6·↵
//↵
//The·Modal·Information↵
//The·number·of·modes·=·0↵
//The·max·Frequency·=·1↵
//The·mode·set·=·{null}↵

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
    mrkSort(ary,arySize);
    //Find the max Frequency
    
    //Find the number of modes
    
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=0;
    int *modeAry=new int[nmodes+2];
    modeAry[0]=0;//Stub returns no modes
    modeAry[1]=1;//Stub returns Frequency 1
    
    
    //Fill the mode array

    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}