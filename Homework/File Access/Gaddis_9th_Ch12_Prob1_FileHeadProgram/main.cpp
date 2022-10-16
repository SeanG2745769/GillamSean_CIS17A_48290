/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Purpose: File Head Program - Write a program that asks the user for the name
 * of a file. The program should display the first ten lines on the screen (the
 * "head" of the file). If the file has fewer than ten lines, the entire file
 * should be displayed, with a message indicating the entire file has been
 * displayed.
 * 
 * Created on October 15, 2022, 8:55 PM
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string fileName;
    string str;
    cout<<"Input file to be opened: ";
    getline(cin,fileName);
    fstream textFile;
    textFile.open(fileName, ios::in);
    if(textFile.fail())
    {
        cout<<"That file does not exist...";
        return 0;
    }
    for(int i=0;i<10;i++)
    {
        getline(textFile,str,'\n');
        if(textFile.eof())
        {
            cout<<"END OF FILE REACHED."<<endl;
            return 0;
        }
        cout<<"Line "<<i+1<<": "<<str<<endl;
    }
    return 0;
}

