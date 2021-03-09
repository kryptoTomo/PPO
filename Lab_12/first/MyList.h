#pragma once
#include<initializer_list>
#include"MyNode.h"



class MyList
{
    public:
    MyList();
    MyList(const int size);
    MyList(std::initializer_list<int> buffer);
    MyList(const MyList & temp);
    MyList(MyList && temp);
    MyList(int (*function)(MyNode * node),const int size);
    ~MyList();
    bool empty()const;
    const int size()const;
    void print()const;
    void clear();
    void add(const int buffer);
    private:
    MyNode * _head =nullptr;
    MyNode * _tail=nullptr;
    int _size=0; 
};
