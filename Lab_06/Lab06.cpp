#include"Lab06.h"
#include<iostream>
#include<cmath>
void equal_size(Bits * bin,const Bits * temp)
{
    while(bin->size() < temp->size())
        bin->insert(bin->begin(),0);
}
void del_null(Bits * bin)
{
    while (!(*bin)[0])
    bin->erase(bin->begin());
}
void set(Bits * bin,int * buffer,int size)
{
    for(int  i = 0; i < size; i++)
        bin->push_back(buffer[i]);
}
void print(const Bits * bin)
{
    for(const auto& x :*bin)
        std::cout<<x;
    std::cout<<std::endl;
}
Bits add_up(const Bits *vect_first,const Bits * vect_second)
{
    Bits bin(*vect_first);
    equal_size(&bin,vect_second);
    unsigned mem = 0 , i ;
    for(i = 0; i != vect_second->size() ;i++)
    {
        switch(bin[bin.size()-i-1]+(*vect_second)[vect_second->size()-i-1]+mem)
        {
            case 0:
            case 1:
                bin[bin.size()- i -1] += (*vect_second)[vect_second->size()-i-1]+mem;
                mem = 0;
                break;
            case 2:
            case 3:
                bin[bin.size()  - i -1] += -2+(*vect_second)[vect_second->size()-i-1]+mem;
                mem = 1;
        }
    }
    if(mem)
    {
        while(bin.size() != i)
        {
            if(bin[bin.size()  - i -1])
                bin[bin.size()  - i -1] = 0;
            else
            {
                bin[bin.size()  - i -1] = 1;
                mem = 0;
                break;
            }
            i++;
        }
        if(mem) bin.insert(bin.begin(),1);
    }
    return bin;
}
void bit_and(Bits* bin,const Bits* mask)
{
    for(unsigned i = 0; i != bin->size();i++)
        (*bin)[i] &= (*mask)[i];
}
void bit_xor(Bits* bin,const Bits* mask)
{
    for(unsigned i = 0; i != bin->size();i++)
        (*bin)[i] ^= (*mask)[i];
}
void doOperation(const function f,Bits* bin,const Bits* mask)
{
    equal_size(bin,mask);
    f(bin,mask);
    del_null(bin);
}
int to_decimal(const Bits * bin)
{
    int sum = 0;
    for(unsigned i = 0; i != bin->size() ;i++)
        sum += (*bin)[bin->size()-1-i] * pow(2,i);
    return sum;
}