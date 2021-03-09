#pragma once

class MyNode
{   
    public:
    MyNode(unsigned val,MyNode * next);
    void next(MyNode * buffer);
    MyNode * getN()const;
    int val()const;
    void print()const;
    private:
    int _val;
    MyNode * _next;
};