/* 
 * File:   Display.h
 * Author: seang
 *
 * Created on December 17, 2022, 12:55 AM
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

/*! Scoreboard Display Class*/

class Display 
{
    Scoreboard stuff; /*!Pulling in Scoreboard Class*/
    public:
        void printBoard(); /*!Function which prints the scoreboard held in other class*/
    private:
        void formatBoard(int); /*!Private function that holds the formating information
                                * for the scoreboard*/
};

void Display::printBoard()
{
    cout<<"Scoreboard: "<<endl;
    cout<<"# Score"<<endl;
    for(int i=0;i<stuff.numItems;i++)
    {
        formatBoard(i);
    }
}

void Display::formatBoard(int i)
{
    cout<<i<<"  "<<stuff.board[i]<<endl;
}


#endif /* DISPLAY_H */

