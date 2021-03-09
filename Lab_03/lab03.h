#pragma once 

#include<iostream>
#include<cstdlib>

int * initFibonacci(const int number);
void print(const int * series,const int number);
void deleteSequence(const int * series);
void addSequence(int * num_series, int *** series_list,int ** series_lenght,const int number);
void printAllSequences(int * const * series_list,const int * series_lenght,const int num_series);
void removeSequence(int * num_series, int *** series_list,int ** series_lenght,const int number);
void deleteSequences(int * num_series, int *** series_list,int ** series_lenght);