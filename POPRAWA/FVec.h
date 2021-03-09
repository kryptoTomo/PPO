#pragma once
#include<iostream>

class FVec
{
    public:
    friend std::ostream& operator<<(std::ostream& os,const FVec &vect);
    FVec(const int floor,const int ceil); 
    FVec(const FVec & vect);
    FVec(FVec && vect);
    FVec(int (*function)(const int n),const int size);
    ~FVec();
    static FVec create(const int buffer);
    FVec & set(const int num,const int val);  
    int & operator[](const int num);
    const int & operator[](const int num)const;
    void operator=(const FVec & vect);
    const int begin()const;
    const int end()const;
    private:
    int * _vect = nullptr;
    int _floor=0,_ceil=0;
};
std::ostream& operator<<(std::ostream& os,const FVec &vect);