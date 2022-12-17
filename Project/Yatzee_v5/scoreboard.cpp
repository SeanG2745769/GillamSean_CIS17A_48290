/* 
 * File:   scoreboard.cpp
 * Author: seang
 * 
 * Created on December 16, 2022, 11:28 PM
 */

#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include "scoreboard.h"

using namespace std;

int Scoreboard::numItems = 10;

Scoreboard::Scoreboard()
{
    board = new int[numItems];
    
    fstream read;
    
    read.open("scores.dat",ios::in);
    
    for(int i=0;i<numItems;i++)
    {
        read >> board[i];
    }
    
    read.close();
}

Scoreboard::~Scoreboard(void)
{
    delete []board;
}

void Scoreboard::getScore(int score)
{
    if(checkScore(score))
    {
        loadNewScore(score);
    }
    else
        cout<<"Score too low to update scoreboard!\n";
}

void Scoreboard::loadNewScore(int score)
{
    bool check = false;
    for(int i=0;i<numItems;i++)
    {
        if(score>board[i] && !check)
        {
            for(int j=i;j<numItems-1;j++)
            {
                board[j+1]=board[j];
            }
            board[i]=score;
            check=true;
        }
    }
    rewrite();
    
}

void Scoreboard::rewrite()
{
    fstream write;
    
    write.open("scores.dat",ios::out|ios::trunc);
    
    for(int i=0;i<numItems;i++)
    {
        write << board[i] << endl;
    }
    
    write.close();
}

bool Scoreboard::checkScore(int score)
{
    bool newHigh = false;
    
    for(int i=0;i<numItems;i++)
    {
        if(score>board[i])
            newHigh = true;
    }
    return newHigh;
}