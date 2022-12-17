/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 11:27 AM
 */

#include <iostream>
#include <string>

using namespace std;

struct data
{
    string company;
    string address;
    string firstName;
    string lastName;
    int hours;
    int rate;
    int pay;
    string payEng;
};

int main(int argc, char** argv)
{
    int numEmployees;
    const string companyName = "Business Inc.";
    const string companyAddress = "123 Business Dr";
    const string signature = "Sean Gillam";
    
    int thousands;
    int hundreds;
    int tens;
    int ones;
    
    bool hoursCheck=true;
    bool rateCheck=true;
    
    cout<<"How many employees?: ";
    cin>>numEmployees;
    
    
    data *employee = new data[numEmployees];
    
    for(int i=0;i<numEmployees;i++)
    {
        employee[i].company = companyName;
        employee[i].address = companyAddress;
        cout<<"\n\nFor employee number "<<i+1<<":\n";
        cout<<"First Name?: ";
        cin>>employee[i].firstName;
        cout<<"Last Name?: ";
        cin>>employee[i].lastName;
        hoursCheck=true;
        while(hoursCheck)
        {
            hoursCheck=true;
            cout<<"Hours worked?: ";
            cin>>employee[i].hours;
            
            if(employee[i].hours<0)
                cout<<"Invalid!\n";
            else
                hoursCheck=false;
        }
        rateCheck=true;
        while(rateCheck)
        {
            rateCheck=true;
            cout<<"Pay rate?: ";
            cin>>employee[i].rate;
            
            if(employee[i].rate<0)
                cout<<"Invalid!\n";
            else
                rateCheck=false;
        }
        
        if(employee[i].hours>40)
            employee[i].pay = (20*employee[i].rate) + (20*employee[i].rate*2) + 
                    ((employee[i].hours - 40)*employee[i].rate*3);
        else if(employee[i].hours>20)
            employee[i].pay = (20*employee[i].rate) + 
                    ((employee[i].hours - 20)*employee[i].rate*2);
        else
            employee[i].pay = (employee[i].hours*employee[i].rate);
        
        thousands = employee[i].pay/1000;
        hundreds  = (employee[i].pay/100)%10;
        tens      = (employee[i].pay/10)%10;
        ones      = employee[i].pay%10;
        
        switch(thousands)
        {
            //This could be scaled even larger but it is not necessary for a
            //proof of concept
            case 20 : employee[i].payEng+="Twenty Thousand ";break;
            case 19 : employee[i].payEng+="Nineteen Thousand ";break;
            case 18 : employee[i].payEng+="Eighteen Thousand ";break;
            case 17 : employee[i].payEng+="Seventeen Thousand ";break;
            case 16 : employee[i].payEng+="Sixteen Thousand ";break;
            case 15 : employee[i].payEng+="Fifteen Thousand ";break;
            case 14 : employee[i].payEng+="Fourteen Thousand ";break;
            case 13 : employee[i].payEng+="Thirteen Thousand ";break;
            case 12 : employee[i].payEng+="Twelve Thousand ";break;
            case 11 : employee[i].payEng+="Eleven Thousand ";break;
            case 10 : employee[i].payEng+="Ten Thousand ";break;
            case 9  : employee[i].payEng+="Nine Thousand ";break;
            case 8  : employee[i].payEng+="Eight Thousand ";break;
            case 7  : employee[i].payEng+="Seven Thousand ";break;
            case 6  : employee[i].payEng+="Six Thousand ";break;
            case 5  : employee[i].payEng+="Five Thousand ";break;
            case 4  : employee[i].payEng+="Four Thousand ";break;
            case 3  : employee[i].payEng+="Three Thousand ";break;
            case 2  : employee[i].payEng+="Two Thousand ";break;
            case 1  : employee[i].payEng+="One Thousand ";break;
            case 0  : break;
            default : cout<<"ERROR"<<endl;
        }
        
        switch(hundreds)
        {
            case 9 : employee[i].payEng+="Nine Hundred ";break;
            case 8 : employee[i].payEng+="Eight Hundred ";break;
            case 7 : employee[i].payEng+="Seven Hundred ";break;
            case 6 : employee[i].payEng+="Six Hundred ";break;
            case 5 : employee[i].payEng+="Five Hundred ";break;
            case 4 : employee[i].payEng+="Four Hundred ";break;
            case 3 : employee[i].payEng+="Three Hundred ";break;
            case 2 : employee[i].payEng+="Two Hundred ";break;
            case 1 : employee[i].payEng+="One Hundred ";break;
            case 0 : break;
            default: cout<<"ERROR"<<endl;
        }
        
        switch(tens)
        {
            case 9 : employee[i].payEng+="Ninety ";break;
            case 8 : employee[i].payEng+="Eighty ";break;
            case 7 : employee[i].payEng+="Seventy ";break;
            case 6 : employee[i].payEng+="Sixty ";break;
            case 5 : employee[i].payEng+="Fifty ";break;
            case 4 : employee[i].payEng+="Forty ";break;
            case 3 : employee[i].payEng+="Thirty ";break;
            case 2 : employee[i].payEng+="Twenty ";break;
            case 1 : break;
            case 0 : break;
            default: cout<<"ERROR"<<endl;
        }
        
        if(tens==1)
        {
            switch(ones)
            {
                case 9 : employee[i].payEng+="Nineteen ";break;
                case 8 : employee[i].payEng+="Eighteen ";break;
                case 7 : employee[i].payEng+="Seventeen ";break;
                case 6 : employee[i].payEng+="Sixteen ";break;
                case 5 : employee[i].payEng+="Fifteen ";break;
                case 4 : employee[i].payEng+="Fourteen ";break;
                case 3 : employee[i].payEng+="Thirteen ";break;
                case 2 : employee[i].payEng+="Twelve ";break;
                case 1 : employee[i].payEng+="Eleven ";break;
                case 0 : break;
                default: cout<<"ERROR"<<endl;
            }
        }
        else if(tens!=1)
        {
            switch(ones)
            {
                case 9 : employee[i].payEng+="Nine ";break;
                case 8 : employee[i].payEng+="Eight ";break;
                case 7 : employee[i].payEng+="Seven ";break;
                case 6 : employee[i].payEng+="Six ";break;
                case 5 : employee[i].payEng+="Five ";break;
                case 4 : employee[i].payEng+="Four ";break;
                case 3 : employee[i].payEng+="Three ";break;
                case 2 : employee[i].payEng+="Two ";break;
                case 1 : employee[i].payEng+="one ";break;
                case 0 : break;
                default: cout<<"ERROR"<<endl;
            }
        }
        
        cout<<endl<<endl;
        cout<<employee[i].company<<endl;
        cout<<employee[i].address<<endl;
        cout<<"Pay to: "<<employee[i].firstName<<" "<<employee[i].lastName
                <<"    The Amount of: $"<<employee[i].pay<<".00"<<endl;
        cout<<employee[i].payEng<<" Dollars"<<endl;
        cout<<"Signed: "<<signature;
    }
    
    delete[] employee;
    
    return 0;
}

