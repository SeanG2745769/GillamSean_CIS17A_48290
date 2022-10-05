#include <iostream>
#include <string>

using namespace std;

struct machine
{
    string name;
    float cost;
    int numDrink;
};

int main(){
    int NUM_OF_DRINKS = 5; //Do 1 less since the system starts at 0
    struct machine drink[NUM_OF_DRINKS];
    
    int moneyMade = 0;
    
    drink[0].name = "Cola";
    drink[1].name = "Root Beer";
    drink[2].name = "Lemon-Lime";
    drink[3].name = "Grape Soda";
    drink[4].name = "Cream Soda";
    
    drink[0].cost = 75;
    drink[1].cost = 75;
    drink[2].cost = 75;
    drink[3].cost = 80;
    drink[4].cost = 80;
    
    drink[0].numDrink = 20;
    drink[1].numDrink = 20;
    drink[2].numDrink = 20;
    drink[3].numDrink = 20;
    drink[4].numDrink = 20;
    
    int exit = 1;
    while(exit > 0)
    {
        int i;
        for(i = 0; i < 5; i++)
        {
            string hold = drink[i].name;
            int length = hold.length();
            int actLength = 11 - length;
            cout << drink[i].name;
            for(int startLength = 0; actLength > startLength; actLength--)
            {
                cout << " "; //Makes the spacing correct
            }
            cout << drink[i].cost <<"  " << drink[i].numDrink << endl;
        }
        cout << "Quit\n";
        
        string choiceValue;
        int choiceNum;
        int choiceCheck = 0;
        while(choiceCheck == 0)
        {
            getline(cin, choiceValue);
            if(choiceValue == drink[0].name)
            {
                if(drink[0].numDrink != 0)
                {
                    choiceNum = 0;
                    choiceCheck = 1;
                    drink[0].numDrink--;
                }
                else
                {
                    cout <<"SOLD OUT\n";
                }
                
            }
            else if(choiceValue == drink[1].name)
            {
                if(drink[0].numDrink != 0)
                {
                    choiceNum = 1;
                    choiceCheck = 1;
                    drink[1].numDrink--;
                }
                else
                {
                    cout <<"SOLD OUT\n";
                }
            }
            else if(choiceValue == drink[2].name)
            {
                
                if(drink[0].numDrink != 0)
                {
                    choiceNum = 2;
                    choiceCheck = 1;
                    drink[2].numDrink--;
                }
                else
                {
                    cout <<"SOLD OUT\n";
                }
                
            }
            else if(choiceValue == drink[3].name)
            {
                
                if(drink[0].numDrink != 0)
                {
                    choiceNum = 3;
                    choiceCheck = 1;
                    drink[3].numDrink--;
                }
                else
                {
                    cout <<"SOLD OUT\n";
                }
            }
            else if(choiceValue == drink[4].name)
            {
                
                if(drink[0].numDrink != 0)
                {
                    choiceNum = 4;
                    choiceCheck = 1;
                    drink[4].numDrink--;
                }
                else
                {
                    cout <<"SOLD OUT\n";
                }
            }
            else if(choiceValue == "Quit")
            {
                cout << moneyMade << endl;
                return 0;
            }
            else
            {
                cout <<"Try again\n";
                choiceCheck = 0;
            }
        }
        
        float money;
        float change;
        int noMoney = 0;

        while(noMoney == 0)
        {
            cin >> money;
            cin.ignore();
            if ((money < 0) or (money > 100))
            {
                cout << "Try Again :(";
            }
            else
            {
                noMoney = 1;
            }
        }

        switch(choiceNum)
        {
            case 0:
                change = money - drink[0].cost;
                break;
            case 1:
                change = money - drink[1].cost;
                break;
            case 2:
                change = money - drink[2].cost;
                break;
            case 3:
                change = money - drink[3].cost;
                break;
            case 4:
                change = money - drink[4].cost;
        }
        cout << change << endl;
        moneyMade = moneyMade + (money-change);
    }
    


    return 0;
}
