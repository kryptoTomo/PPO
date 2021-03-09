#pragma once
#include<iostream>

class Arr2D
{
    public:
    friend void operator<<=(std::string buffer,const Arr2D & array);
    Arr2D();
    Arr2D(const int rows,const int columns);
    Arr2D(const Arr2D & array);
    void operator=(const Arr2D &array);
    ~Arr2D();
    static Arr2D  adopt(const int * buffer,const int rows,const int columns);
    int * operator[](const int &num);
    const int * operator[](const int & num)const;
    private:
    void del();
    void alloc(int rows,int columns);
    void enter(const Arr2D & array);
    int ** _array = nullptr;
    int _rows=0,_columns=0;
};