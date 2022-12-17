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
const int SCORES = 13; //Number of scoring options

//For menu choices
enum menuChoices
{
    playgame,
    contGame,
    settings
};

//For settings choices
enum settingsChoices
{
    playerCount
};

//Structure for checking full house condition
struct Data
{
    int fullOne;
    int fullTwo;
    int fullThree;
    int fullFour;
    int fullFive;
    int fullSix;
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
    //Score trackers
    int ones;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int threeKind;
    int fourKind;
    int fullHouse;
    int smallSrt;
    int largeSrt;
    int yahtzee;
    int chance;
    //Boolean flags so scores cant be double counted
    bool flag[SCORES];
    //Nested structure
    Data full;
};



//Menu Option Prototypes
void menu();
void game(int,bool);
void setting(fstream&);

//Supporting function prototypes
Player* rollDice(Player *,int,bool,bool,bool,bool,bool);
void roll(Player *,int,int);
char getInitials(Player *,int,int);
void dispDice(Player *,int);
bool searchNum(Player *,int,int);

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
            case settings   : {setting(numPlayersFile);break;}
            default: cout<<endl<<endl<<"Exiting menu. Good Bye!";
        }
    }while(choice>=0&&choice<=2);
    
    //Exit Stage Right
    return 0;
}

void menu()
{
    cout<<endl<<endl;
    cout<<"Main Menu:"<<endl;
    cout<<"Type 0 for new game."<<endl;
    cout<<"Type 1 to continue game."<<endl;
    cout<<"Type 2 for settings."<<endl;
    cout<<"Type any other number to quit game."<<endl;
}

void game(int numPlayers, bool cgame)
{
    
    
    int playerCount=0;
    bool exit;
    int reroll;
    int diceNum;
    int gameChoice;
    bool exitChoice;
    int iterationCounter;
    int kindCounter;
    int kindIt;
    
    fstream numSavePlayersFile, gameFile, iterationFile, playerCountFile,
                numPlayersFile;
        
    //Reset Player number to save game size if cgame flag is true
    if(cgame)
    {
        numSavePlayersFile.open("numSavePlayers.dat", ios::in);
        numPlayersFile.open("numPlayers.dat", ios::out);
        numSavePlayersFile>>numPlayers;
        int temp = numPlayers;
        numPlayersFile << temp;
        
        iterationFile.open("iteration.dat", ios::in);
        iterationFile>>iterationCounter;
        
        playerCountFile.open("playerCount.dat", ios::in);
        playerCountFile>>playerCount;
        
        numSavePlayersFile.close();
        numPlayersFile.close();
        iterationFile.close();
        playerCountFile.close();
    }
    
    Player *player = new Player[numPlayers];
            
    //Resetting structure from file if continue game
    if(cgame)
    {   
        gameFile.open("game.bin",ios::in|ios::binary);
        for(int i=0;i<numPlayers;i++)
            gameFile.read(reinterpret_cast<char *>(&player[i]),sizeof(Player));
        gameFile.close();
    }
    
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
            player[i].full.fullOne=0;
            player[i].full.fullTwo=0;
            player[i].full.fullThree=0;
            player[i].full.fullFour=0;
            player[i].full.fullFive=0;
            player[i].full.fullSix=0;
            for(int j=0;j<SCORES;j++)
                player[i].flag[j]=false;
        }
        
        //Setting for new game how many times we will loop
        iterationCounter = numPlayers*13;
    }
    
    
    
    do
    {
        exit=false;
        
        //Starting Dice rolling part of game loop
        cout<<"Player "<<player[playerCount].initials<<"'s Turn!"<<endl;
        player = rollDice(player,playerCount,1,1,1,1,1);
        for(int i=0;i<CHANCES;i++)
        {
            cout<<"Roll "<<i+1<<":"<<endl;
            if(i<CHANCES-1)
            {
                do
                {
                    dispDice(player,playerCount);
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
                    for(int j=0;j<reroll;j++)
                    {
                        do
                        {
                            cout<<"Dice #?: ";
                            cin>>diceNum;
                            cin.ignore();
                            if(diceNum<1||diceNum>5)
                                cout<<"Invalid!"<<endl;
                        }while(diceNum<1||diceNum>5);
                        roll(player,playerCount,diceNum);
                    }
                }
            }
            else
                dispDice(player,playerCount);
        }
        
        //Outputing current player 
        cout<<player[playerCount].initials<<"'s Score Card:"<<endl;
        if(player[playerCount].flag[0])
            cout<<"1: Ones: "<<player[playerCount].ones<<endl;
        else
            cout<<"1: Ones: "<<endl;
        if(player[playerCount].flag[1])
            cout<<"2: Twos: "<<player[playerCount].twos<<endl;
        else
            cout<<"2: Twos: "<<endl;
        if(player[playerCount].flag[2])
            cout<<"3: Threes: "<<player[playerCount].threes<<endl;
        else
            cout<<"3: Threes: "<<endl;
        if(player[playerCount].flag[3])
            cout<<"4: Fours: "<<player[playerCount].fours<<endl;
        else
            cout<<"4: Fours: "<<endl;
        if(player[playerCount].flag[4])
            cout<<"5: Fives: "<<player[playerCount].fives<<endl;
        else
            cout<<"5: Fives: "<<endl;
        if(player[playerCount].flag[5])
            cout<<"6: Sixes: "<<player[playerCount].sixes<<endl;
        else
            cout<<"6: Sixes: "<<endl;
        if(player[playerCount].flag[6])
            cout<<"7: Three of a Kind: "<<player[playerCount].threeKind<<endl;
        else
            cout<<"7: Three of a Kind: "<<endl;
        if(player[playerCount].flag[7])
            cout<<"8: Four of a Kind: "<<player[playerCount].fourKind<<endl;
        else
            cout<<"8: Four of a Kind: "<<endl;
        if(player[playerCount].flag[8])
            cout<<"9: Full House: "<<player[playerCount].fullHouse<<endl;
        else
            cout<<"9: Full House: "<<endl;
        if(player[playerCount].flag[9])
            cout<<"10: Small Straight: "<<player[playerCount].smallSrt<<endl;
        else
            cout<<"10: Small Straight: "<<endl;
        if(player[playerCount].flag[10])
            cout<<"11: Large Straight: "<<player[playerCount].largeSrt<<endl;
        else
            cout<<"11: Large Straight: "<<endl;
        if(player[playerCount].flag[11])
            cout<<"12: Yahtzee: "<<player[playerCount].yahtzee<<endl;
        else
            cout<<"12: Yahtzee: "<<endl;
        if(player[playerCount].flag[12])
            cout<<"13: Chance: "<<player[playerCount].chance<<endl;
        else
            cout<<"13: Chance: "<<endl;
        
        //Ask for player input
        do
        {
            cout<<"Please select an option too score your dice(1-13): ";
            cin>>gameChoice;
            cin.ignore();
            if(gameChoice<1||gameChoice>13)
                cout<<"Invalid!"<<endl;
            else if(player[playerCount].flag[gameChoice-1])
            {
                cout<<"Already Scored!"<<endl;
                gameChoice=-1;
            }
        }while(gameChoice<1||gameChoice>13);
        
        //Switch statement handling scoring by player choice.
        switch(gameChoice)
        {
            case 1 : 
                player[playerCount].flag[0]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==1)
                        player[playerCount].ones++;
                break;
            case 2 :
                player[playerCount].flag[1]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==2)
                        player[playerCount].twos++;
                player[playerCount].twos=player[playerCount].twos*2;
                break;
            case 3 :
                player[playerCount].flag[2]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==3)
                        player[playerCount].threes++;
                player[playerCount].threes=player[playerCount].threes*3;
                break;
            case 4 :
                player[playerCount].flag[3]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==4)
                        player[playerCount].fours++;
                player[playerCount].fours=player[playerCount].fours*4;
                break;
            case 5 :
                player[playerCount].flag[4]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==5)
                        player[playerCount].fives++;
                player[playerCount].fives=player[playerCount].fives*5;
                break;
            case 6 :
                player[playerCount].flag[5]=true;
                for(int i=0;i<NUM_DICE;i++)
                    if(player[playerCount].dice[i]==6)
                        player[playerCount].sixes++;
                player[playerCount].sixes=player[playerCount].sixes*6;
                break;
            case 7 :
                player[playerCount].flag[6]=true;
                kindIt=0;
                do
                {
                    kindCounter=0;
                    kindIt++;
                    for(int i=0;i<NUM_DICE;i++)
                        if(player[playerCount].dice[i]==kindIt)
                            kindCounter++;
                }while(kindCounter<3&&kindIt<7);
                if(kindCounter>2)
                    for(int i=0;i<NUM_DICE;i++)
                        player[playerCount].threeKind=
                                player[playerCount].threeKind+
                                player[playerCount].dice[i];
                break;
            case 8 :
                player[playerCount].flag[7]=true;
                kindIt=0;
                do
                {
                    kindCounter=0;
                    kindIt++;
                    for(int i=0;i<NUM_DICE;i++)
                        if(player[playerCount].dice[i]==kindIt)
                            kindCounter++;
                }while(kindCounter<4&&kindIt<7);
                if(kindCounter>2)
                    for(int i=0;i<NUM_DICE;i++)
                        player[playerCount].fourKind=
                                player[playerCount].fourKind+
                                player[playerCount].dice[i];
                break;
            case 9 :
                player[playerCount].flag[8]=true;
                for(int i=0;i<NUM_DICE;i++)
                {
                    if(player[playerCount].dice[i]==1)
                        player[playerCount].full.fullOne++;
                    else if(player[playerCount].dice[i]==2)
                        player[playerCount].full.fullTwo++;
                    else if(player[playerCount].dice[i]==3)
                        player[playerCount].full.fullThree++;
                    else if(player[playerCount].dice[i]==4)
                        player[playerCount].full.fullFour++;
                    else if(player[playerCount].dice[i]==5)
                        player[playerCount].full.fullFive++;
                    else if(player[playerCount].dice[i]==6)
                        player[playerCount].full.fullSix++;
                }
                if((player[playerCount].full.fullOne<2)&&(
                        (player[playerCount].full.fullTwo>1)||
                        (player[playerCount].full.fullThree>1)||
                        (player[playerCount].full.fullFour>1)||
                        (player[playerCount].full.fullFive>1)||
                        (player[playerCount].full.fullSix>1)))
                    player[playerCount].fullHouse=25;
                else if((player[playerCount].full.fullTwo<2)&&(
                        (player[playerCount].full.fullOne>1)||
                        (player[playerCount].full.fullThree>1)||
                        (player[playerCount].full.fullFour>1)||
                        (player[playerCount].full.fullFive>1)||
                        (player[playerCount].full.fullSix>1)))
                    player[playerCount].fullHouse=25;
                else if((player[playerCount].full.fullThree<2)&&(
                        (player[playerCount].full.fullOne>1)||
                        (player[playerCount].full.fullTwo>1)||
                        (player[playerCount].full.fullFour>1)||
                        (player[playerCount].full.fullFive>1)||
                        (player[playerCount].full.fullSix>1)))
                    player[playerCount].fullHouse=25;
                else if((player[playerCount].full.fullFour<2)&&(
                        (player[playerCount].full.fullOne>1)||
                        (player[playerCount].full.fullTwo>1)||
                        (player[playerCount].full.fullThree>1)||
                        (player[playerCount].full.fullFive>1)||
                        (player[playerCount].full.fullSix>1)))
                    player[playerCount].fullHouse=25;
                else if((player[playerCount].full.fullFive<2)&&(
                        (player[playerCount].full.fullOne>1)||
                        (player[playerCount].full.fullTwo>1)||
                        (player[playerCount].full.fullThree>1)||
                        (player[playerCount].full.fullFour>1)||
                        (player[playerCount].full.fullSix>1)))
                    player[playerCount].fullHouse=25;
                else if((player[playerCount].full.fullSix<2)&&(
                        (player[playerCount].full.fullOne>1)||
                        (player[playerCount].full.fullTwo>1)||
                        (player[playerCount].full.fullThree>1)||
                        (player[playerCount].full.fullFour>1)||
                        (player[playerCount].full.fullFive>1)))
                    player[playerCount].fullHouse=25;
                break;
            case 10 :
                player[playerCount].flag[9]=true;
                if(searchNum(player,playerCount,1))
                {
                    if(searchNum(player,playerCount,2))
                        if(searchNum(player,playerCount,3))
                            if(searchNum(player,playerCount,4))
                                player[playerCount].smallSrt=30;
                }
                if(searchNum(player,playerCount,2))
                {
                    if(searchNum(player,playerCount,3))
                        if(searchNum(player,playerCount,4))
                            if(searchNum(player,playerCount,5))
                                player[playerCount].smallSrt=30;
                }
                if(searchNum(player,playerCount,3))
                {
                    if(searchNum(player,playerCount,4))
                        if(searchNum(player,playerCount,5))
                            if(searchNum(player,playerCount,6))
                                player[playerCount].smallSrt=30;
                }
                break;
            case 11 :
                player[playerCount].flag[10]=true;
                if(searchNum(player,playerCount,1))
                {
                    if(searchNum(player,playerCount,2))
                        if(searchNum(player,playerCount,3))
                            if(searchNum(player,playerCount,4))
                                if(searchNum(player,playerCount,5))
                                    player[playerCount].largeSrt=40;
                }
                if(searchNum(player,playerCount,2))
                {
                    if(searchNum(player,playerCount,3))
                        if(searchNum(player,playerCount,4))
                            if(searchNum(player,playerCount,5))
                                if(searchNum(player,playerCount,6))
                                    player[playerCount].largeSrt=40;
                }
                break;
            case 12 :
                player[playerCount].flag[11]=true;
                if(player[playerCount].dice[0]==player[playerCount].dice[1])
                    if(player[playerCount].dice[0]==player[playerCount].dice[2])
                        if(player[playerCount].dice[0]==player[playerCount].dice[3])
                            if(player[playerCount].dice[0]==player[playerCount].dice[4])
                                player[playerCount].yahtzee=50;
                break;
            case 13 :
                player[playerCount].flag[12]=true;
                for(int i=0;i<NUM_DICE;i++)
                    player[playerCount].chance=player[playerCount].chance+
                            player[playerCount].dice[i];
        }
        
        //iterate to next players turn
        playerCount++;
        if(playerCount>numPlayers-1)
            playerCount=0;
        
        //Exit Game condition when over
        iterationCounter--;
        if(iterationCounter==0)
        {
            for(int i=0;i<numPlayers;i++)
            {
                player[i].totalScore=player[i].ones+player[i].twos+
                        player[i].threes+player[i].fours+player[i].fives+
                        player[i].sixes+player[i].threeKind+player[i].fourKind+
                        player[i].fullHouse+player[i].smallSrt+
                        player[i].largeSrt+player[i].yahtzee+player[i].chance;
            }
            cout<<"Final Totals!"<<endl;
            for(int i=0;i<numPlayers;i++)
            {
                cout<<player[i].initials<<"'s total points = "
                        <<player[i].totalScore<<endl;
            }
            cout<<"Thanks for playing!"<<endl<<endl;
            exit=true;
        }
        else
        {
            do
            {
                cout<<"Would you like to exit and save the game(yes=1,no=0)?: ";
                cin>>exitChoice;
                if(exitChoice<0||exitChoice>1)
                    cout<<"Invalid!"<<endl;
            }while(exitChoice<0||exitChoice>1);
            if(exitChoice)
            {
                exit=true;
                exitChoice=false;
                
                numSavePlayersFile.open("numSavePlayers.dat", ios::out);
                numSavePlayersFile<<numPlayers;
                numSavePlayersFile.close();
                
                iterationFile.open("iteration.dat", ios::out);
                iterationFile<<iterationCounter;
                iterationFile.close();
                
                playerCountFile.open("playerCount.dat", ios::out);
                playerCountFile<<playerCount;
                playerCountFile.close();
                
                gameFile.open("game.bin",ios::out|ios::binary);
                for(int i=0;i<numPlayers;i++)
                    gameFile.write(reinterpret_cast<char *>(&player[i]),sizeof(Player));
                gameFile.close();
            }
            else
                cout<<"Continuing Game..."<<endl;
        }
    }while(!exit);
    
    //delete pointer
    delete [] player;
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

Player* rollDice(Player * pR,int num,bool d1,bool d2,bool d3,bool d4,bool d5)
{
    Player *p = new Player[num];
    p = pR;
    if(d1)
        p[num].dice[0]=1+(rand()%6);
    if(d2)
        p[num].dice[1]=1+(rand()%6);
    if(d3)
        p[num].dice[2]=1+(rand()%6);
    if(d4)
        p[num].dice[3]=1+(rand()%6);
    if(d5)
        p[num].dice[4]=1+(rand()%6);
    return p;
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

bool searchNum(Player * sN,int num,int j)
{
    for(int i=0;i<NUM_DICE;i++)
        if(sN[num].dice[i]==j)
            return true;
    return false;
}