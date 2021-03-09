#pragma once
#include<iostream>

class MyNode
{
    public:
    static void print(MyNode * head,MyNode * tail);
    static void add(MyNode *& head,MyNode *& tail ,int &size,const int buffer);
    static void del(MyNode *& head,MyNode *& tail,int &size);
    void change(int (*function)(MyNode * node));
    const int val()const;
    MyNode *next()const;
    private:
    int _val = 0;
    MyNode * _next = nullptr;
};
