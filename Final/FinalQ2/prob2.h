/* 
 * File:   prob2.h
 * Author: seang
 *
 * Created on December 16, 2022, 10:08 AM
 */

#ifndef PROB2_H
#define PROB2_H

#include<cstdlib>

using namespace std;

template<class T>
class Prob2Sort{
    private:
        int *index; //Index that is utilized
                    //in the sort
    public:
        Prob2Sort(){index=NULL;}; //Constructor
        ~Prob2Sort(){delete []index;}; //Destructor
        T * sortArray(const T*,int,bool); //Sorts a single column array
        T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array
                                                 //represented as a 1 dim array
};

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int s, bool b)
{
    return sortArray(arr,s,1,1,b);
}

template<class T>
T * Prob2Sort<T>::sortArray(const T* arr, int row, int col, int sortC, bool b)
{
    
    int HiLow;

    if(index)
    {
        delete [] index;
    }
    index = new int[row];

    for(int i = 0; i < row; i++)
        index[i] = i;

    for(int i = 0; i < row; i++)
    {
        HiLow = i;
        for(int j = i+1; j < row; j++)
        {
            if(b)
            {
                if(arr[index[j] * col + sortC - 1] < arr[index[HiLow] * col + sortC - 1])
                HiLow = j;
            }
            else
            {
                if(arr[index[j] * col + sortC - 1] > arr[index[HiLow] * col + sortC - 1])
                HiLow = j;
            }
        }
        swap(index[i],index[HiLow]);
    }

    T* sorted = new T[row * col];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            sorted[i * col + j] = arr[index[i] * col + j];
        }
    }
    return sorted;
}

#endif /* PROB2_H */

