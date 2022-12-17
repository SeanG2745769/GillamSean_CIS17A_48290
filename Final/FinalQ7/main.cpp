/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on December 16, 2022, 2:44 PM
 */

#include <iostream>
#include <fstream>
#include "prob1.h"
#include "prob2.h"
#include "prob3.h"
#include "prob4.h"
#include "prob5.h"

using namespace std;

void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;} //Couldn't Get this one to work so its all commented out
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<endl;
}

void prblm1()
{
    char n=5;
    char rndseq[]={19,34,57,79,126};
    
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    
    
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
    cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void prblm2()
{
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    
    Prob2Sort<char> rc;
    
    bool ascending=true;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    
    int column;
    cin>>column;
    
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
        {
            cout<<zc[i*16+j];
        }
    }
    
    delete []zc;
    
    cout<<endl;
}

void prblm3()
{
    cout<<"I couldn't make this one work. Code is commented out to allow other\n"
            " questions to function correctly.";
//    cout<<"Entering problem number 3"<<endl;
//    
//    int rows=5;
//    int cols=6;
//    
//    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
//    
//    const int *naugT=tab.getTable();
//    
//    for(int i=0;i<rows;i++)
//    {
//        for(int j=0;j<cols;j++)
//        {
//            cout<<naugT[i*cols+j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    
//    const int *augT=tab.getAugTable();
//    
//    for(int i=0;i<=rows;i++)
//    {
//        for(int j=0;j<=cols;j++)
//        {
//            cout<<augT[i*(cols+1)+j]<<" ";
//        }
//        cout<<endl;
//    }
}

void prblm4()
{
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    cout<<endl;
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total(0.10,7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive(0.10,7)
        <<" Recursive Calculation "<<endl;
}

void prblm5()
{
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
}

void prblm6()
{
    cout<<"Please see PDF file for calculations.\n";
    cout<<"Question 1:"<<endl;
    cout<<" -A: 5.75(10)=101.11(2)=5.6(8)=5.C(16)"<<endl;
    cout<<" -B: 0.9(10)=0.11100(2)=0.7631(8)=E6(16)"<<endl;
    cout<<" -C: 99.7(10)=1100011.10110(2)=143.54631(8)=63.B3(16)"<<endl;
    cout<<"Question 2:"<<endl;
    cout<<" -A: 5C000003"<<endl;
    cout<<" -B: 73333300"<<endl;
    cout<<" -C: 63B33307"<<endl;
    cout<<"Question 3:"<<endl;
    cout<<" -A: 0.1011100"<<endl;
    cout<<" -B: 0.111001100110011"<<endl;
    cout<<" -C: 0.110001110110011001100110"<<endl;
    cout<<"Question 4:"<<endl;
    cout<<" -I didn't understand what this was asking."<<endl;
    cout<<"Question 5:"<<endl;
    cout<<" -A: 40B80000"<<endl;
    cout<<" -B: 3F666666"<<endl;
    cout<<" -C: 42C76666"<<endl;
}