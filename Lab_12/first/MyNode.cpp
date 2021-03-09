#include"MyNode.h"


void MyNode::print(MyNode * head,MyNode * tail)
{
    while(head!=tail)
    {
        std::cout<<head->_val<<", ";
        head = head->_next;
    }
    std::cout<<head->_val;
}
void MyNode::add(MyNode *& head,MyNode *& tail ,int &size,const int buffer)
{
    MyNode * temp = new MyNode;
    temp->_val = buffer;
    temp->_next=nullptr;
    if(head)
    {
        tail->_next=temp;
        tail=temp;
    }
    else
    {
        head = temp;
        tail = temp;
    }
    size++;
}
void MyNode::del(MyNode *& head,MyNode *& tail,int &size)
{
    for(int i = 0;i!=size;i++)
    {
        tail = head->_next;
        delete head;
        head = tail;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}
const int MyNode::val()const
{
    return _val;
}
MyNode *MyNode::next()const
{
    return _next;
}
void MyNode::change(int (*function)(MyNode * node))
{
    _val = function(this);
}
