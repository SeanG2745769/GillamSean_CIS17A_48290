/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include <limits>

using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

const int INDEX = 10000;

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

struct Prime
{
    unsigned short prime;
    unsigned char power;
};

struct Primes
{
    unsigned char nPrimes;
    Prime *prime;
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

void encrypt();
void decrypt();

Primes *factor(int);
void prntPrm(Primes*);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;} //not sure why but after problem 1 it quits
            case '2':{prblm2();break;}//does not do this for the rest nor does it
            case '3':{prblm3();break;}// this in main question code.
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}


void menu(){
    //Display menu
    cout<<endl<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
    cout<<endl;
}

void prblm1(){
    cout<<"Problem 1"<<endl;
    int size;
    cout<<"How many customers?: ";
    cin>>size;
    cin.ignore();
    Customer *customer = new Customer[size];
   
    
    bool next = true;
    bool numCheck = true;
    int custCounter=0;
    int deposit;
    int checks;
    float overdrawFee = 35.00;
    
    while(next)
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
            next=false;
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
}

void prblm2(){
    cout<<"Problem 2"<<endl;
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
}

void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"This Program is somewhere else."<<endl;
}

void prblm4(){
    cout<<"problem 4"<<endl;
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
}

void prblm5()
{
    cout<<"Problem 5"<<endl;
    char          sByte, nsByte;
    short int     sSInt, nsSInt;
    int           sInt, nsInt;
    long int      sLInt, nsLInt;
    long long int sLLInt, nsLLInt;
    float         sFloat, nsFloat;
    double        sDouble, nsDouble;
    long double   sLDouble, nsLDouble;
    
    unsigned char          uByte, huByte, nuByte;
    unsigned short int     uSInt, huSInt, nuSInt;
    unsigned int           uInt, huInt, nuInt;
    unsigned long int      uLInt, huLInt, nuLInt;
    unsigned long long int uLLInt, huLLInt, nuLLInt;
    
    nsByte = 1;
    sByte  = 1;
    do
    {
        sByte=sByte*nsByte;
        nsByte++;
    }while(sByte>0);
    nsByte--;
    
    huByte = 0;
    nuByte = 1;
    uByte  = 1;
    do
    {
        if(nuByte!=1)
            huByte=uByte;
        uByte=uByte*nuByte;
        nuByte++;
    }while(uByte>huByte);
    nuByte--;
    
    //Short Int
    nsSInt = 1;
    sSInt  = 1;
    do
    {
        sSInt=sSInt*nsSInt;
        nsSInt++;
    }while(sSInt>0);
    nsSInt--;
    
    //unsigned short int
    huSInt = 0;
    nuSInt = 1;
    uSInt  = 1;
    do
    {
        if(nuSInt!=1)
            huSInt=uSInt;
        uSInt=uSInt*nuSInt;
        nuSInt++;
    }while(uSInt>huSInt);
    nuSInt--;
    
    //int
    nsInt = 1;
    sInt  = 1;
    do
    {
        sInt=sInt*nsInt;
        nsInt++;
    }while(sInt>0);
    nsInt--;
    
    //unsigned int
    huInt = 0;
    nuInt = 1;
    uInt  = 1;
    do
    {
        if(nuInt!=1)
            huInt=uInt;
        uInt=uInt*nuInt;
        nuInt++;
    }while(uInt>huInt);
    nuInt--;
    
    //long int
    nsLInt = 1;
    sLInt  = 1;
    do
    {
        sLInt=sLInt*nsLInt;
        nsLInt++;
    }while(sLInt>0);
    nsLInt--;
    
    //unsigned long int
    huLInt = 0;
    nuLInt = 1;
    uLInt  = 1;
    do
    {
        if(nuLInt!=1)
            huLInt=uLInt;
        uLInt=uLInt*nuLInt;
        nuLInt++;
    }while(uLInt>huLInt);
    nuLInt--;
    
    //long long int
    nsLLInt = 1;
    sLLInt  = 1;
    do
    {
        sLLInt=sLLInt*nsLLInt;
        nsLLInt++;
    }while(sLLInt>0);
    nsLLInt--;
    
    //unsigned long long int
    huLLInt = 0;
    nuLLInt = 1;
    uLLInt  = 1;
    do
    {
        if(nuLLInt!=1)
            huLLInt=uLLInt;
        uLLInt=uLLInt*nuLLInt;
        nuLLInt++;
    }while(uLLInt>huLLInt);
    nuLLInt--;
    
    //float
    nsFloat = 1;
    sFloat  = 1;
    do
    {
        sFloat=sFloat*nsFloat;
        nsFloat++;
    }while(sFloat<(numeric_limits<float>::infinity()));
    nsFloat--;
    
    //double
    nsDouble = 1;
    sDouble  = 1;
    do
    {
        sDouble=sDouble*nsDouble;
        nsDouble++;
    }while(sDouble<(numeric_limits<double>::infinity()));
    nsDouble--;
    
    //long double
    nsLDouble = 1;
    sLDouble  = 1;
    do
    {
        sLDouble=sLDouble*nsLDouble;
        nsLDouble++;
    }while(sLDouble<(numeric_limits<long double>::infinity()));
    nsLDouble--;
    
    cout<<"Factorial for byte(char):             "<<+nsByte<<endl;
    cout<<"Factorial for unsigned byte(char)     "<<+nuByte<<endl;
    cout<<"Factorial for short int:              "<<nsSInt<<endl;
    cout<<"Factorial for unsigned short int:     "<<nuSInt<<endl;
    cout<<"Factorial for int:                    "<<nsInt<<endl;
    cout<<"Factorial for unsigned int:           "<<nuInt<<endl;
    cout<<"Factorial for long int:               "<<nsLInt<<endl;
    cout<<"Factorial for unsigned long int:      "<<nuLInt<<endl;
    cout<<"Factorial for long long int:          "<<nsLLInt<<endl;
    cout<<"Factorial for unsigned long long int: "<<nuLLInt<<endl;
    cout<<"Factorial for float:                  "<<nsFloat<<endl;
    cout<<"Factorial for double:                 "<<nsDouble<<endl;
    cout<<"Factorial for long double:            "<<nsLDouble<<endl;
}

void prblm6(){
    cout<<"Problem 6"<<endl;
    cout<<"Base 10: 49.1875\n";
    cout<<"Base 2 : 110001.0011\n";
    cout<<"Base 8 : 60.14\n";
    cout<<"Base 16: 30.3\n";
    cout<<"NASA FLOAT: 62600006\n";
    cout<<endl;
    
    cout<<"Base 10: 3.07421875\n";
    cout<<"Base 2 : 11.0010011\n";
    cout<<"Base 8 : 3.046\n";
    cout<<"Base 16: 3.13\n";
    cout<<"NASA FLOAT: 62600002\n";
    cout<<endl;
    
    cout<<"Base 10: 0.2\n";
    cout<<"Base 2 : 0.0011 Repeating\n";
    cout<<"Base 8 : 0.1463 Repeating\n";
    cout<<"Base 16: 0.3    Repeating\n";
    cout<<"NASA FLOAT: 666666FE\n";
    cout<<endl;
    
    cout<<"Base 10: -49.1875\n";
    cout<<"NASA FLOAT Base 2 : 10011101 10100000 00000000 00000110\n";
    cout<<"NASA FLOAT Base 8 : 23550000006\n";
    cout<<"NASA FLOAT Base 16: 9DA00006\n";
    cout<<endl;
    
    cout<<"Base 10: -3.07421875\n";
    cout<<"NASA FLOAT Base 2 : 10011101 10100000 00000000 00000010\n";
    cout<<"NASA FLOAT Base 8 : 23550000002\n";
    cout<<"NASA FLOAT Base 16: 9DA00002\n";
    cout<<endl;
    
    cout<<"Base 10: -0.2\n";
    cout<<"NASA FLOAT Base 2 : 10011001 10011001 10011010 1111110\n";
    cout<<"NASA FLOAT Base 8 : 23146315376\n";
    cout<<"NASA FLOAT Base 16: 99999AFE\n";
    cout<<endl;
    
    cout<<"Base 16: 69999902\n";
    cout<<"Decimal: 3.29999714\n";
    cout<<endl;
    
    cout<<"Base 16: 69999903\n";
    cout<<"Decimal: 6.59999942\n";
    cout<<endl;
    
    cout<<"Base 16: 966667FF\n";
    cout<<"Decimal: 0.41249996\n";
    cout<<endl;
}

void prblm7()
{
    cout<<"Problem 7"<<endl;
    int num;
    do
    {
        cout<<"Choose an integer between 2 and 65000: ";
        cin>>num;
        if(num<2||num>65000)
            cout<<"Invalid input\n";
    }while(num<2||num>65000);
    
    Primes *prm = factor(num);
    
    cout<<"For Original Number: "<<num<<endl;
    
    prntPrm(prm);
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

Primes *factor(int num_f)
{
    Primes *a = new Primes;
    int i, j, primeNum;
    int temp[INDEX]={0};
    
    primeNum = 2; //first prime number
    while(1<num_f)
    {
        if(num_f%primeNum==0)//num divided by prime;
        {
            temp[primeNum]++;//array at specific prime number is increased
            num_f=num_f/primeNum; //reduce input number to search for next divisible prime
        }
        else if(num_f%primeNum!=0)
            primeNum++;//This will iterate through primeNum 1 by 1 but n%primeNum only executes
                //when primeNum is a small prime because otherwise it would have 
                //executed earlier
    }
    i=0;//reset index;
    int totalPrimeNum=0;
    while(i<INDEX)
    {
        if(temp[i]!=0)//checking for where prime factors were counted
            totalPrimeNum++;//incrementing the total number of prime numbers counted
        i++;
    }
    a->nPrimes=totalPrimeNum;
    a->prime = new Prime[totalPrimeNum];
    i=0;//reset index
    primeNum=0;
    while(i<INDEX)
    {
        if(temp[i]!=0)
        {
            a->prime[primeNum].prime=i;//index is the prime number
            //pull out how many times it was incremented
            //because it is the number of that needed
            a->prime[primeNum].power=temp[i]+'0';
            primeNum++;
        }
        i++; //increment counter
    }
    return a;
}

void prntPrm(Primes* prm_f)
{
    for(int i=0;i<prm_f->nPrimes;i++)
    {
        cout<<"Prime: "<<prm_f->prime[i].prime<<" to the Power of: "<<
                prm_f->prime[i].power<<endl;
    }
}