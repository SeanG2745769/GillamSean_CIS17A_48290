/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Source: Gaddis 9th Chapter 12 Problem 8 - Array/File Function
 * 
 * Purpose: 
 *      Write a function named arrayToFile. The function should accept three
 * arguments: the name of a file, a pointer to an int array, and the size of the
 * array. The function should open the specified file in binary mode, write the 
 * contents of the array to the file, and then close the file.
 *      Write another function named fileToArray. This function should accept
 * three arguments: the name of a file, a pointer to an int array, and the size
 * of the array. The function should open the specified file in binary mode,
 * read its contents into the array, and then close the file.
 *      Write a complete program that demonstrates these functions by using the 
 * arrayToFile function to write an array to a file, then using the fileToArray
 * function to read the data from the same file. After the data are read from
 * the file into the array, display the array's contents on the screen.
 * 
 * Created on October 15, 2022, 2:08 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

void arrayToFile(string,int*,int);
void fileToArray(string,int*,int);

int main(int argc, char** argv) 
{
    const int SIZE = 10;
    int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int newArr[SIZE];
    string fileName = "arr.bin";
    
    arrayToFile(fileName,arr,SIZE);
    fileToArray(fileName,newArr,SIZE);
    
    for(int i=0;i<SIZE;i++)
        cout<<newArr[i]<<" ";
    cout<<endl;
    
    return 0;
}

void arrayToFile(string fileName_f,int* arr_f,int size_f)
{
    int holdArr[size_f];
    for(int i=0;i<size_f;i++)
        holdArr[i]=arr_f[i];
    fstream file;
    file.open(fileName_f,ios::out|ios::binary);
    file.write(reinterpret_cast<char *>(holdArr),sizeof(holdArr));
    file.close();
}

void fileToArray(string fileName_f,int* newArr_f,int size_f)
{
    int holdArr[size_f];
    for(int i=0;i<size_f;i++)
        holdArr[i]=newArr_f[i];
    fstream file;
    file.open(fileName_f,ios::in|ios::binary);
    file.read(reinterpret_cast<char *>(holdArr),sizeof(holdArr));
    for(int i=0;i<size_f;i++)
        newArr_f[i]=holdArr[i];
    file.close();
}