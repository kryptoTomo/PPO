#include"lab03.h"

int * initFibonacci(const int number)
{
    if(number < 0)
        return nullptr;
    int * series = new int[number + 1];
    series[0]= 0;
    if(number > 0)
    {
        series[1] = 1;
        for(int i = 2 ; i <= number; i++ )
            series[i] = series[i-1] + series[i-2];
    }
    return series;
}
void print(const int * series,const int number)
{
    if(series)
    {
        std::cout<<"(";
        for(int i = 0; i < number;i++)
            std::cout<<series[i]<<", ";
        std::cout<<series[number]<<")"<<std::endl;
    }
    else 
        std::cout << "Ciag nie istnieje"<<std::endl;
}
void deleteSequence(const int * series)
{
    if(series)
        delete []series;
}
void addSequence(int * num_series, int *** series_list,int ** series_lenght,const int number)
{
    ++*num_series;
    *series_list = (int **)realloc(*series_list,*num_series*sizeof(*series_list));
    *series_lenght = (int *)realloc(*series_lenght,*num_series*sizeof(*series_lenght));
    *(*series_lenght+*num_series-1) = abs(number);
    *(*series_list+*num_series-1) = initFibonacci(*(*series_lenght+*num_series-1));
}
void printAllSequences(int * const * series_list,const int * series_lenght,const int num_series)
{
    for(int i = 0 ; i < num_series ; i++)
    {
        std::cout<<"Ciag nr "<<i<<" ";
        print(*(series_list+i),*(series_lenght+i));
    }
}
void removeSequence(int * num_series, int *** series_list,int ** series_lenght,const int number)
{
    deleteSequence(*(*series_list+number));
    for(int i = number; i < *num_series - 1;i++)
    {
        *(*series_list+i) = *(*series_list+i+1);
        *(*series_lenght+i) = *(*series_lenght+i+1);
    }
    --(*num_series);
    *series_list = (int **)realloc(*series_list,*num_series*sizeof(*series_list));
    *series_lenght = (int *)realloc(*series_lenght,*num_series*sizeof(*series_lenght));
}
void deleteSequences(int * num_series, int *** series_list,int ** series_lenght)
{
    while((*num_series)--)
    {
        deleteSequence(*(*series_list+*num_series));
    }
    free(*series_list);
    free(*series_lenght);
}