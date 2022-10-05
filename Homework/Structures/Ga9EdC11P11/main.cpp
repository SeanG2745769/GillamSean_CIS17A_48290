/* 
 * File: HW_CodeE10-06Prob3
 * Author: Sean Gillam
 * Created on: 2021-10-05
 * Purpose:  A student has established the following monthly budget:
 * Housing              $500.00
 * Utilities            $150.00
 * Household Expenses   $65.00
 * Transportation       $50.00
 * Food                 $250.00
 * Medical              $30.00
 * Insurance            $100.00
 * Entertainment        $150.00
 * Clothing             $75.00
 * Miscellaneous      $50.00
 * 
 * Write a program that has a MonthlyBudget structure designed to hold each of 
 * these expense categories. The program should pass the structure to a function
 * that asks the user to enter the amounts spent in each budget category during
 * a month. The program should then pass the structure to a function that
 * displays a report indicating the amount over or under in each category, as 
 * well as the amount over or under for the entire monthly budget.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Structures
struct monthBudget
{
    float house;
    float utilities;
    float houseExpense;
    float transport;
    float food;
    float medical;
    float insurance;
    float entertain;
    float clothes;
    float misc;
};

//Function Prototypes
void readIn(struct monthBudget *u);
void overUnder(struct monthBudget *u2, struct monthBudget *m);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    struct monthBudget user;
    struct monthBudget max;
    
    max.house = 500;
    max.utilities = 150;
    max.houseExpense = 65;
    max.transport = 50;
    max.food = 250;
    max.medical = 30;
    max.insurance = 100;
    max.entertain = 150;
    max.clothes = 75;
    max.misc = 50;
    
    //Process or map Inputs to Outputs
    readIn(&user);
    
    //Display Outputs
    overUnder(&user, &max);
    
    //Exit stage right!
    return 0;
}
//Functions Down Here
//Read In Function
void readIn(struct monthBudget *u)
{
    cout << "Enter housing cost for the month:$";
    cin >> u->house;
    cin.ignore();
    cout << "\nEnter utilities cost for the month:$";
    cin >> u->utilities;
    cin.ignore();
    cout << "\nEnter household expenses cost for the month:$";
    cin >> u->houseExpense;
    cin.ignore();
    cout << "\nEnter transportation cost for the month:$";
    cin >> u->transport;
    cin.ignore();
    cout << "\nEnter food cost for the month:$";
    cin >> u->food;
    cin.ignore();
    cout << "\nEnter medical cost for the month:$";
    cin >> u->medical;
    cin.ignore();
    cout << "\nEnter insurance cost for the month:$";
    cin >> u->insurance;
    cin.ignore();
    cout << "\nEnter entertainment cost for the month:$";
    cin >> u->entertain;
    cin.ignore();
    cout << "\nEnter clothing cost for the month:$";
    cin >> u->clothes;
    cin.ignore();
    cout << "\nEnter miscellaneous cost for the month:$";
    cin >> u->misc;
    cin.ignore();
    cout << endl;
}

void overUnder(struct monthBudget *u2, struct monthBudget *m)
{
    struct monthBudget userCopy2;
    struct monthBudget maxCopy;
    userCopy2 = *u2;
    maxCopy = *m;
    
    //Housing              $500.00
    if(userCopy2.house > maxCopy.house)
    {
        cout << "Housing Over\n";
    }
    else if (userCopy2.house < maxCopy.house)
    {
        cout << "Housing Under\n";
    }
    else
    {
        cout << "Housing Even\n";
    }
    
    //Utilities            $150.00
    if(userCopy2.utilities > maxCopy.utilities)
    {
        cout << "Utilities Over\n";
    }
    else if (userCopy2.utilities < maxCopy.utilities)
    {
        cout << "Utilities Under\n";
    }
    else
    {
        cout << "Utilities Even\n";
    }
    
    //Household Expenses   $65.00
    if(userCopy2.houseExpense > maxCopy.houseExpense)
    {
        cout << "Household Expenses Over\n";
    }
    else if (userCopy2.houseExpense < maxCopy.houseExpense)
    {
        cout << "Household Expenses Under\n";
    }
    else
    {
        cout << "Household Expenses Even\n";
    }
    
    //Transportation       $50.00
    if(userCopy2.transport > maxCopy.transport)
    {
        cout << "Transportation Over\n";
    }
    else if (userCopy2.transport < maxCopy.transport)
    {
        cout << "Transportation Under\n";
    }
    else
    {
        cout << "Transportation Even\n";
    }
    
    //Food                 $250.00
    if(userCopy2.food > maxCopy.food)
    {
        cout << "Food Over\n";
    }
    else if (userCopy2.food < maxCopy.food)
    {
        cout << "Food Under\n";
    }
    else
    {
        cout << "Food Even\n";
    }
    
    //Medical              $30.00
    if(userCopy2.medical > maxCopy.medical)
    {
        cout << "Medical Over\n";
    }
    else if (userCopy2.medical < maxCopy.medical)
    {
        cout << "Medical Under\n";
    }
    else
    {
        cout << "Medical Even\n";
    }
    
    //Insurance            $100.00
    if(userCopy2.insurance > maxCopy.insurance)
    {
        cout << "Insurance Over\n";
    }
    else if (userCopy2.insurance < maxCopy.insurance)
    {
        cout << "Insurance Under\n";
    }
    else
    {
        cout << "Insurance Even\n";
    }
    
    //Entertainment        $150.00
    if(userCopy2.entertain > maxCopy.entertain)
    {
        cout << "Entertainment Over\n";
    }
    else if (userCopy2.entertain < maxCopy.entertain)
    {
        cout << "Entertainment Under\n";
    }
    else
    {
        cout << "Entertainment Even\n";
    }
    
    //Clothing             $75.00
    if(userCopy2.clothes > maxCopy.clothes)
    {
        cout << "Clothing Over\n";
    }
    else if (userCopy2.clothes < maxCopy.clothes)
    {
        cout << "Clothing Under\n";
    }
    else
    {
        cout << "Clothing Even\n";
    }
    
    //Miscellaneous       $50.00
    if(userCopy2.misc > maxCopy.misc)
    {
        cout << "Miscellaneous Over\n";
    }
    else if (userCopy2.misc < maxCopy.misc)
    {
        cout << "Miscellaneous Under\n";
    }
    else
    {
        cout << "Miscellaneous Even\n";
    }
    
    //Calculations for total
    float total = ((userCopy2.clothes + userCopy2.entertain + userCopy2.food + 
    userCopy2.house + userCopy2.houseExpense + userCopy2.insurance + userCopy2.
    medical + userCopy2.misc + userCopy2.transport + userCopy2.utilities) - (
    maxCopy.clothes + maxCopy.entertain + maxCopy.food + maxCopy.house + maxCopy
    .houseExpense + maxCopy.insurance + maxCopy.medical + maxCopy.misc + maxCopy
    .transport + maxCopy.utilities));
    
    float maxMoney = (maxCopy.clothes + maxCopy.entertain + maxCopy.food + 
    maxCopy.house + maxCopy.houseExpense + maxCopy.insurance + maxCopy.medical
    + maxCopy.misc + maxCopy.transport + maxCopy.utilities);
    
    //Output for over under total
    if (total > 0) 
    {
        cout << fixed << setprecision(2) << "You were $" << total << " over "
                "budget";
    }
    else if(total < 0)
    {
        //gotta make that number positive
        float hold = total * total;
        total = sqrt(hold);
        //output
        cout << fixed << setprecision(2) << "You were $" << total << " under "
                "budget";
    }
    else
    {
        cout << "You were even";
    }
}
