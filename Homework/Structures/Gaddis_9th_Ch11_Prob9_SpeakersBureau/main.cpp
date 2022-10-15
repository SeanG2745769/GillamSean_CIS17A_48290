/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Purpose: Track Speakers for a Bureau.
 * 
 * Created on October 5, 2022, 8:51 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

struct Data
{
    string name;
    string topic;
    string phone;
    float  fee;
};

int  addS(struct Data [], int);
void display(struct Data [], int);
void modify(struct Data [], int);

int main(int argc, char** argv)
{
    const int   SIZE = 10;
    struct Data speaker[SIZE];
    
    int  choice;
    int  count = 0;
    bool menu  = true;
    
    while(menu == true)
    {
        cout<<"Choose and option: \n"
            <<"1: Add a speaker\n"
            <<"2: Display list\n"
            <<"3: Modify a Speaker\n"
            <<"4: Quit\n"
            <<"->";
        cin>>choice;
        cin.ignore();
        if(choice==1)
        {
            if(count>9)
            {
                cout<<"Sorry maximum number of speakers reached!\n";
                choice=5;
            }
        }
        switch(choice)
        {
            case 1: count = addS(speaker, count);break;
            case 2: display(speaker, count);break;
            case 3: modify(speaker, count);break;
            case 4: menu = false;break;
            default: cout<<"Invalid try again!\n";
        }
    }
    
    return 0;
}

addS(struct Data speak[], int num)
{
    bool flag = true;
    int  choice_f;
    bool add = true;
    while(add==true)
    {
        cout<<"\nName: ";
        getline(cin,speak[num].name);
        cout<<"Phone Number: ";
        cin>>speak[num].phone;
        cin.ignore();
        cout<<"Speaking Topic: ";
        getline(cin,speak[num].topic);
        do
        {
            cout<<"Fee: ";
            cin>>speak[num].fee;
            
            if(speak[num].fee<0)
                cout<<"Invalid try again!\n";
        }while(speak[num].fee<0);
        do
        {
            cout<<"Add another?(yes = 1 | no = 0): ";
            cin>>choice_f;
            cin.ignore();
            if(choice_f==1)
                add=true;
            else if(choice_f==0)
                add=false;
            else
                flag=false;
        }while(flag==false);
        num++;
    }
    cout<<endl;
    return num;
}

void display(struct Data speak[], int num)
{
    cout<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<"Speaker #: "<<i+1<<endl;
        cout<<"Name:  "<<speak[i].name<<endl;
        cout<<"Phone: "<<speak[i].phone<<endl;
        cout<<"Topic: "<<speak[i].topic<<endl;
        cout<<fixed<<setprecision(2)<<"Fee:   "<<speak[i].fee<<endl;
    }
    cout<<"End of list.\n\n";
}

void modify(struct Data speak[], int num)
{
    bool flagC = true;
    bool flagS = true;
    bool flagE = true;
    bool mod   = true;
    int  numMod, choice_f;
    while(mod==true)
    {
        while(flagC==true)
        {
            cout<<"\nNumber of Speaker to modify: ";
            cin>>numMod;
            cin.ignore();
            if((numMod>num)||(numMod<0))
            {
                cout<<"Invalid try again!\n";
                flagC=true;
            }
            else
                flagC=false;
        }
        while(flagS==true)
        {
            flagS=false;
            cout<<"Please choose which to modify:\n"
                <<"1: Name\n"
                <<"2: Phone Number\n"
                <<"3: Speaking Topic\n"
                <<"4: Fee Required\n"
                <<"->";
            cin>>choice_f;
            cin.ignore();
            switch(choice_f)
            {
                case 1: cout<<"Name: ";getline(cin,speak[numMod-1].name);break;
                case 2: cout<<"Number: ";cin>>speak[numMod-1].phone;break;
                case 3: cout<<"Topic: ";getline(cin,speak[numMod-1].topic);break;
                case 4: cout<<"Fee: ";cin>>speak[numMod-1].fee;break;
                default: cout<<"Invalid try again!\n";flagS=true;
            }
        }
        do
        {
            cout<<"Modify another?(yes = 1 | no = 0): ";
            cin>>choice_f;
            cin.ignore();
            if(choice_f==1)
            {
                mod=true;
                flagC=true;
                flagS=true;
            }
            else if(choice_f==0)
                mod=false;
            else
                flagE=false;
        }while(flagE==false);
    }
    cout<<endl;
}