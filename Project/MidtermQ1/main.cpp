/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 10:35 AM
 */

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct Customer
{
    int account;
    string name;
    string address;
    float startBal;
    float *outBal;
    float *inBal;
    float finalBal;
};

int main(int argc, char** argv)
{
    int size;
    cout<<"How many customers?: ";
    cin>>size;
    cin.ignore();
    Customer *customer = new Customer[size];
   
    
    bool cont = true;
    bool numCheck = true;
    int custCounter=0;
    int deposit;
    int checks;
    float overdrawFee = 35.00;
    
    while(cont)
    {
        while (numCheck)
        {
            numCheck=true;
            cout<<"Account Number: ";
            cin>>customer[custCounter].account;
            cin.ignore();
            if((customer[custCounter].account<10000)||
                    (customer[custCounter].account>99999))
            {
                cout<<"Invalid account number\n";
            }
            else
                numCheck=false;
        }
        cout<<"Name: ";
        getline(cin,customer[custCounter].name);
        cout<<"Address: ";
        getline(cin,customer[custCounter].address);
        cout<<"Start Balance: ";
        cin>>customer[custCounter].startBal;
        customer[custCounter].finalBal=customer[custCounter].startBal;
        cout<<"How many checks: ";
        cin>>checks;
        cin.ignore();
        customer[custCounter].outBal = new float[checks];
        for(int i=0;i<checks;i++)
        {
            cout<<"Enter amount for check #"<<i+1<<": ";
            cin>>customer[custCounter].outBal[i];
            cin.ignore();
            customer[custCounter].finalBal = customer[custCounter].finalBal - 
                    customer[custCounter].outBal[i];
        }
        cout<<"How many deposits: ";
        cin>>deposit;
        cin.ignore();
        customer[custCounter].inBal = new float[deposit];
        for(int i=0;i<deposit;i++)
        {
            cout<<"Enter amount for deposit #"<<i+1<<": ";
            cin>>customer[custCounter].inBal[i];
            cin.ignore();
            customer[custCounter].finalBal = customer[custCounter].finalBal +
                    customer[custCounter].inBal[i];
        }
        
        if(customer[custCounter].finalBal<0)
        {
            customer[custCounter].finalBal = customer[custCounter].finalBal -
                    overdrawFee;
            cout<<"ACCOUNT OVERDRAWN $35 FEE ADDED!\n";
        }
        
        cout<<endl;
        cout<<"Account Number: "<<customer[custCounter].account<<endl;
        cout<<"Name: "<<customer[custCounter].name<<endl;
        cout<<"Address: "<<customer[custCounter].address<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"Start Balance: $"<<customer[custCounter].startBal<<endl;
        cout<<"Final Balance: $"<<customer[custCounter].finalBal<<endl<<endl;
        
        custCounter++;
        if(custCounter=size)
            cont=false;
    }
    
    
    for(int i=0;i<custCounter;i++)
    {
        delete[] customer[custCounter].outBal;
    }
    for(int i=0;i<custCounter;i++)
    {
        delete[] customer[custCounter].inBal;
    }
    delete[] customer;
    
    return 0;
}

