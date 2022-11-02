/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 1:49 PM
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void encrypt();
void decrypt();

int main(int argc, char** argv)
{
    int choice;
    bool flag = true;
    while(flag)
    {
        flag = true;
        cout<<"Please choose an option below: \n";
        cout<<"1: Encrypt\n";
        cout<<"2: Decrypt\n";
        cout<<"->";
        cin>>choice;
        if(choice<1||choice>2)
            cout<<"INVALID\n";
        else
            flag=false;
    }
    switch(choice)
    {
        case 1 : encrypt();break;
        case 2 : decrypt();break;
    }
    
    return 0;
}

void encrypt()
{
    string str;
    int num;
    int  arr[4];
    bool countError;
    bool boundsError;
    
    do
    {
        boundsError=true;
        do
        {
            countError=true;
            cout<<"To be encrypted: ";
            cin>>str;
            
            if(str.size()!=4)
                cout<<"Error: Wrong number of digits!\n";
            else
            {
                countError=false;
            }
        }while(countError);
        stringstream container(str);
        container >> num;
        if(num<1)
            for(int i=0;i<4;i++)
                arr[i]=0;
        else if(num<10)
        {
            for(int i=0;i<3;i++)
                arr[i]=0;
            arr[3]=num%10;
        }
        else if(num<100)
        {
            for(int i=0;i<2;i++)
                arr[i]=0;
            arr[2]=num%10;
            num/=10;
            arr[3]=num%10;
        }
        else if(num<1000)
        {
            arr[0]=0;
            for(int i=1;i<4;i++)
            {
                arr[i]=num%10;
                num/=10;
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                arr[i]=num%10;
                num/=10;
            }
        }
        for(int i=0;i<4;i++)
        {
            if(arr[i]<0||arr[i]>7)
                cout<<"Error: outside range 1-7!\n";
            else
                boundsError=false;
        }
    }while(boundsError);
    
    for(int i=0;i<4;i++)
        arr[i] = (arr[i] + 6)%8;
    swap(arr[0],arr[2]);
    swap(arr[1],arr[3]);
    
    for(int i=0;i<4;i++)
        if(arr[i]==8||arr[i]==9)
            cout<<"8/9 Error Occured.\n";
    cout<<"Encrypted: ";
    for(int i=0;i<4;i++)
        cout<<arr[i];
    cout<<endl;
}

void decrypt()
{
    string str;
    int num;
    int  arr[4];
    bool countError;
    bool boundsError;
    
    do
    {
        boundsError=true;
        do
        {
            countError=true;
            cout<<"To be encrypted: ";
            cin>>str;
            
            if(str.size()!=4)
                cout<<"Error: Wrong number of digits!\n";
            else
            {
                countError=false;
            }
        }while(countError);
        stringstream container(str);
        container >> num;
        if(num<1)
            for(int i=0;i<4;i++)
                arr[i]=0;
        else if(num<10)
        {
            for(int i=0;i<3;i++)
                arr[i]=0;
            arr[3]=num%10;
        }
        else if(num<100)
        {
            for(int i=0;i<2;i++)
                arr[i]=0;
            arr[2]=num%10;
            num/=10;
            arr[3]=num%10;
        }
        else if(num<1000)
        {
            arr[0]=0;
            for(int i=1;i<4;i++)
            {
                arr[i]=num%10;
                num/=10;
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                arr[i]=num%10;
                num/=10;
            }
        }
        for(int i=0;i<4;i++)
        {
            if(arr[i]<0||arr[i]>7)
                cout<<"Error: outside range 1-7!\n";
            else
                boundsError=false;
        }
    }while(boundsError);
    
    swap(arr[1],arr[3]);
    swap(arr[0],arr[2]);
    
    for(int i=0;i<4;i++)
    {
        if(arr[i]==0)arr[i]=2;
        else if(arr[i]==1)arr[i]=3;
        else if(arr[i]==2)arr[i]=4;
        else if(arr[i]==3)arr[i]=5;
        else if(arr[i]==4)arr[i]=6;
        else if(arr[i]==5)arr[i]=7;
        else if(arr[i]==6)arr[i]=0;
        else arr[i]=1;
    }
    
    for(int i=0;i<4;i++)
        if(arr[i]==8||arr[i]==9)
            cout<<"8/9 Error Occured.\n";
    cout<<"Encrypted: ";
    for(int i=0;i<4;i++)
        cout<<arr[i];
    cout<<endl;
}