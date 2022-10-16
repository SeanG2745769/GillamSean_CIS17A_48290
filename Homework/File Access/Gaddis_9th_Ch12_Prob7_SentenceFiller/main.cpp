/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Source: Gaddis 9th Chapter 12 Problem 7 - Sentence Filler
 * 
 * Purpose: Write a program that asks the user for two file names. The first 
 * file will be opened for input, and the second file will be opened for output.
 * (It will be assumed the first file contains sentences that end with a
 * period). The program will read the contents of the first file and change all
 * the letters to lowercase except the first letter of each sentence, which
 * should be made upper case. The revised contents should be stored in the
 * second file.
 * 
 * Created on October 15, 2022, 12:03 PM
 */

#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    int     length;
    string  inFileName, outFileName;
    string  fileContents;
    fstream inputFile;
    fstream outputFile;
    
    cout<<"Please enter input file name: ";
    getline(cin, inFileName);
    cout<<"Please enter output file name: ";
    getline(cin, outFileName);
    
    inputFile.open(inFileName,ios::in);
    
    if(inputFile)
    {
        getline(inputFile, fileContents);
        length = fileContents.size();
        
        for(int i=0;i<length;i++)
        {
            if(i==0)
                fileContents[i]=toupper(fileContents[i]);
            else if(((fileContents[i-1]==' ')&&fileContents[i-2]=='.')||
                    (fileContents[i-1]=='.'))
                fileContents[i]=toupper(fileContents[i]);
            else
                fileContents[i]=tolower(fileContents[i]);
        }
        inputFile.close();
    }
    else
        cout<<"ERROR: Cannot open file.\n";

    outputFile.open(outFileName,ios::out);
    outputFile<<fileContents.c_str();
    outputFile.close();
            
    return 0;
}