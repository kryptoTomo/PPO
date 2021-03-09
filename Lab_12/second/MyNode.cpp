#include"MyNode.h"
#include<iostream>
MyNode::MyNode(unsigned val,MyNode * next):_val(val),_next(next)
{}
void MyNode::next(MyNode * buffer)
{
    _next = buffer;
}
MyNode * MyNode::getN()const
{
    return _next;
}
void MyNode::print()const
{
    std::cout<<_val;
}
int MyNode::val()const
{
    return _val;
}