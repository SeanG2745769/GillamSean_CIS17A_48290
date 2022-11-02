/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 24, 2022, 3:12 PM
 */

#include <iostream>
#include <cstdint>
#include <limits>

using namespace std;

int main(int argc, char** argv) 
{
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
    
    return 0;
}

