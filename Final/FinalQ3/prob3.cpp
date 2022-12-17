/* 
 * File:   prob3.cpp
 * Author: seang
 * 
 * Created on December 16, 2022, 10:18 AM
 */

#include <fstream>
#include "prob3.h"

using namespace std;

Prob3Table::Prob3Table(char *file,int rows, int cols)
{
    ifstream read;
    
    this->rows = rows;
    this->cols = cols;
    rowSum = new int[rows];
    colSum = new int[cols];
    
    read.open(file,ios::in);
    table = new int[rows * cols];
    
    for(int i=0;i<rows*cols && !read.eof();i++)
        read>>table[i];
    
    read.close();
}

void Prob3Table::calcTable(void)
{
    grandTotal = 0;
    
    for(int i=0;i<rows;i++)
    {
        rowSum[i]=0;
        for(int j=0;j<cols;j++)
        {
            rowSum[i] += table[i * cols + j];
        }
    }
    
    for(int i=0;i<cols;i++)
    {
        colSum[i]=0;
        for(int j=0;j<rows;j++)
        {
            colSum[i] += table[j * cols + i];
        }
        grandTotal += colSum[i];
    }
}

