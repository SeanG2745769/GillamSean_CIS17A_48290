/* 
 * File:   prob1.cpp
 * Author: seang
 * 
 * Created on December 16, 2022, 9:57 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include "prob1.h"

Prob1Random::Prob1Random(const char n,const char *a) //Constructor
{
    nset = n;
    set = new char[n];
    freq = new int[n];
    int i;
    for(i = 0; i < n; i++)
    {
        set[i] = a[i];
        freq[i] = 0;
    }
    numRand = 0;
    
    srand(time(NULL));
}

Prob1Random::~Prob1Random(void) //Destructor
{
    delete []set;
    delete []freq;
}

char Prob1Random::randFromSet(void) //Returns a random number from the set
{
    char i = rand()%nset;
    freq[i]++; numRand++;
    return set[i];
}

int * Prob1Random::getFreq(void) const //Returns the frequency histogram
{
    return freq;
}

char * Prob1Random::getSet(void) const //Returns the set used
{
    return set;
}

int Prob1Random::getNumRand(void) const //Gets the number of times randFromSet has
{
    return numRand;
}