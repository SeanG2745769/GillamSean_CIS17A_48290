/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 5:10 PM
 */

#include <iostream>

using namespace std;

const int INDEX = 10000;

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

Primes *factor(int);
void prntPrm(Primes*);

int main(int argc, char** argv) 
{
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
    
    return 0;
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