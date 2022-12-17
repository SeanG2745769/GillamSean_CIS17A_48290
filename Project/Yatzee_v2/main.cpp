/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 28, 2022, 6:23 PM
 */

#include <iostream> //For user in/output
#include <ctime>    //For random dice rolls
#include <cstdlib>  //Standard Library
#include <cstring>  //For Players Initials
#include <string>   //For Players Name
#include <fstream>  //For save games

using namespace std;

//Global Constants
const int NUM_DICE = 5; // Number of dice in a game
const int NUM_INITIALS = 3; // Number of letters for initials to store
const int CHANCES = 3; // Number of re-rolls allowed

//For menu choices
enum menuChoices
{
    playgame,
    contGame,
    scoreboard,
    settings
};

//For settings choices
enum settingsChoices
{
    playerCount
};

//Player data for file storage
struct Player 
{
    //Player Details
    string name;
    char initials[NUM_INITIALS];
    //Overall trackers
    int totalScore;
    int dice[NUM_DICE];
    int rollCount;
    //Score trackers
    int  ones;
    int  twos;
    int  threes;
    int  fours;
    int  fives;
    int  sixes;
    int  threeKind;
    int  fourKind;
    bool fullHouse;
    bool smallSrt;
    bool largeSrt;
    bool yahtzee;
    int  chance;
    //Boolean flags so scores cant be double counted
    bool onesFlg;
    bool twosFlg;
    bool threesFlg;
    bool foursFlg;
    bool fivesFlg;
    bool sixesFlg;
    bool threeKindFlg;
    bool fourKindFlg;
    bool fullHouseFlg;
    bool smallStrtFlg;
    bool largeStrtFlg;
    bool yahtzeeFlg;
    bool chanceFlg;
};

//Menu Option Prototypes
void menu();
void game(int,bool);
void score();
void setting(fstream&);

//Supporting function prototypes
void rollDice(Player *,int,bool,bool,bool,bool,bool);
void roll(Player *,int,int);
char getInitials(Player *,int,int);
void dispDice(Player *,int);

int main(int argc, char** argv)
{
    //Setting random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //numPlayer declarations
    fstream numPlayersFile;
    int numPlayers;
    
    //Menu Do While Loop
    int choice;
    do
    {
        //Read in numPlayers data (Important for save game)
        numPlayersFile.open("numPlayers.dat", ios::in);
        if(!numPlayersFile)
            cout<<"ERROR: Reading Player Count";
        else
            numPlayersFile>>numPlayers;
        numPlayersFile.close();
        
        //begin menu
        menu();
        cin>>choice;
        cin.ignore();
        
        switch(choice)
        {
            case playgame   : {game(numPlayers,false);break;}
            case contGame   : {game(numPlayers,true);break;}
            case scoreboard : {score();break;}
            case settings   : {setting(numPlayersFile);break;}
            default: cout<<endl<<endl<<"Exiting menu. Good Bye!";
        }
    }while(choice>=0&&choice<=3);
    
    //Exit Stage Right
    return 0;
}

void menu()
{
    cout<<endl<<endl;
    cout<<"Main Menu:"<<endl;
    cout<<"Type 0 for new game."<<endl;
    cout<<"Type 1 to continue game."<<endl;
    cout<<"Type 2 for scoreboard."<<endl;
    cout<<"Type 3 for settings."<<endl;
    cout<<"Type any other number to quit game."<<endl;
}

void game(int numPlayers, bool cgame)
{
    int gameCount=0;
    
    //Reset Player number to save game size if cgame flag is true
    if(cgame)
    {
        
    }
    
    Player *player = new Player[numPlayers];
    
    //If not new game then set all starting conditions
    if(!cgame)
    {
        //Getting Players names and initials
        cout<<"\n\nStarting new game...\n\n";
        for(int i=0;i<numPlayers;i++)
        {
            cout<<"Hello player #"<<i+1<<endl;
            cout<<"Please enter name: ";
            getline(cin,player[i].name);
            for(int j=0;j<NUM_INITIALS;j++)
                player[i].initials[j]=getInitials(player,i,j);
            cout<<"Hello "<<player[i].name<<" your initials for the scoreboard"
                    " will be: "<<player[i].initials<<endl;
        }
        
        //Settings initial values for all players
        for(int i=0;i<numPlayers;i++)
        {
            player[i].totalScore=0;
            player[i].ones=0;
            player[i].twos=0;
            player[i].threes=0;
            player[i].fours=0;
            player[i].fives=0;
            player[i].sixes=0;
            player[i].threeKind=0;
            player[i].fourKind=0;
            player[i].fullHouse=0;
            player[i].smallSrt=0;
            player[i].largeSrt=0;
            player[i].yahtzee=0;
            player[i].chance=0;
            player[i].onesFlg=0;
            player[i].twosFlg=0;
            player[i].threesFlg=0;
            player[i].foursFlg=0;
            player[i].fivesFlg=0;
            player[i].sixesFlg=0;
            player[i].threeKindFlg=0;
            player[i].fourKindFlg=0;
            player[i].fullHouseFlg=0;
            player[i].smallStrtFlg=0;
            player[i].largeStrtFlg=0;
            player[i].yahtzeeFlg=0;
            player[i].chanceFlg=0;
        }
    }
    
    bool exit;
    int reroll;
    int diceNum;
    do
    {
        exit=false;
        cout<<"Player "<<player[gameCount].initials<<"'s Turn!"<<endl;
        rollDice(player,gameCount,1,1,1,1,1);
        for(int i=0;i<CHANCES;i++)
        {
            cout<<"Roll "<<i+1<<":"<<endl;
            if(i<CHANCES-1)
            {
                do
                {
                    dispDice(player,gameCount);
                    cout<<"How Many dice would you like to reroll(0-5)?: ";
                    cin>>reroll;
                    cin.ignore();
                    if(reroll<0||reroll>5)
                        cout<<"Invalid number of dice!"<<endl;
                }while(reroll<0||reroll>5);
                if(reroll==0)
                    i=CHANCES-1; //Set to big number to escape
                else
                {
                    cout<<"Which Dice would you like to reroll?"<<endl;
                    for(int i=0;i<reroll;i++)
                    {
                        do
                        {
                            cout<<"Dice #?: ";
                            cin>>diceNum;
                            cin.ignore();
                            if(diceNum<1||diceNum>5)
                                cout<<"Invalid!"<<endl;
                        }while(diceNum<1||diceNum>5);
                        roll(player,gameCount,diceNum);
                    }
                }
            }
            else
                dispDice(player,gameCount);
        }
        //temp!
        exit=true;
        
    }while(!exit);
}

void score()
{
    cout<<"Test score\n";
}

void setting(fstream& f)
{
    int choice;
    int num;
    
    f.open("numPlayers.dat",ios::in);
    if(!f)
        cout<<"ERROR: Reading Player Count";
    else
        f>>num;
    f.close();
    
    cout<<endl<<endl;
    do
    {
        cout<<"Settings:"<<endl;
        cout<<"Type 0 to change number of players"<<endl;
        cout<<"Type any other number to return to main menu"<<endl;
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case playerCount :
                cout<<"Current Setting: "<<num<<endl;
                cout<<"Enter number of players: ";
                cin>>num;
                cout<<"New Setting: "<<num<<endl<<endl;
                break;
            default : cout<<"Returning to main menu...";
        }
    }while(choice==0);
    
    f.open("numPlayers.dat",ios::out);
    if(!f)
        cout<<"ERROR: Writing Player Count";
    else
        f<<num;
    f.close();
    
    cout<<endl;
}

void rollDice(Player * pR,int num,bool d1,bool d2,bool d3,bool d4,bool d5)
{
    if(d1)
        pR[num].dice[0]=1+(rand()%6);
    if(d2)
        pR[num].dice[1]=1+(rand()%6);
    if(d3)
        pR[num].dice[2]=1+(rand()%6);
    if(d4)
        pR[num].dice[3]=1+(rand()%6);
    if(d5)
        pR[num].dice[4]=1+(rand()%6);
}

void roll(Player * rr,int num,int d)
{
    rr[num].dice[d-1]=1+(rand()%6);
}

void dispDice(Player * pD,int num)
{
    for(int i=0;i<NUM_DICE;i++)
        cout<<"   Dice "<<i+1<<": "<<pD[num].dice[i]<<endl;
}

char getInitials(Player * pI,int i,int j)
{
    return toupper((*(pI+i)).name[j]);
}