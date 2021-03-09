#pragma once

#include"MyNode.h"
#include <initializer_list>

class MyList
{
    public:
    MyList();
    MyList(unsigned size);
    MyList(std::initializer_list<int> init);
    MyList(const MyList & head);
    MyList(MyList && head);
    MyList(int (*function)(MyNode * node),unsigned size);
    ~MyList();
    bool empty()const;
    unsigned size()const;
    void print()const;
    void clear();
    void add(int val);
    private:
    MyNode * _head;
    MyNode * _tail;
    unsigned _size;
};