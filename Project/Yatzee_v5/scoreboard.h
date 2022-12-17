/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scoreboard.h
 * Author: seang
 *
 * Created on December 16, 2022, 11:28 PM
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>

using namespace std;

class Scoreboard {
    public:
        Scoreboard();//constructor
        ~Scoreboard(void);     //destructor
        void getScore(int);
    private:
        bool checkScore(int);
        void loadNewScore(int);
        int score;
        int *board;
        static int numItems;
        friend class Display;
    protected:
        void rewrite();
    
};

#endif /* SCOREBOARD_H */

