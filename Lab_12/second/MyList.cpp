#include"MyList.h"
#include<iostream>

MyList::MyList():_head(nullptr),_tail(nullptr),_size(0)
{
    std::cout<<"KONST: Domyslny"<<std::endl;
}
MyList::MyList(unsigned size):MyList()
{
    std::cout<<"KONST: Jednoargumentowy"<<std::endl;
    while(_size!=size)
        add(_size);
       
}
MyList::MyList(std::initializer_list<int> init):_head(nullptr),_tail(nullptr),_size(0)
{
    std::cout<<"KONST: std::initializer_list"<<std::endl;
    for(auto i = init.begin();i!=init.end();i++)
        add(*i);
}
MyList::MyList(const MyList & head):MyList()
{
    std::cout<<"KONST: kopiujacy"<<std::endl;
    MyNode *help = head._head;
    while(help)
    {
        add(help->val());
        help = help->getN();
    }
}
MyList::MyList(MyList && head)
{
    std::cout<<"KONST: przenoszacy"<<std::endl;
    _head = std::__exchange(head._head,nullptr);
    _tail = std::__exchange(head._tail,nullptr);
    _size = std::__exchange(head._size,0);
}
MyList::MyList(int (*function)(MyNode * node),unsigned size): _head(nullptr),_tail(nullptr),_size(0)
{
    add(function(_head));
    MyNode * help = _head;
    while(_size!=size)
    {
        add(function(help));
        help = help->getN();
    }
}
MyList::~MyList()
{
    std::cout<<"DESTRUKTOR (rozmiar = "<<_size<<")"<<std::endl;
    clear();
}
bool MyList::empty()const
{
    if(_size)
        return false;
    return true;
}
unsigned MyList::size()const
{
    return _size;
}
//[]
void MyList::print()const
{
    std::cout<<'[';
    if(_head)
    {
        MyNode * help = _head;
        while(help!=_tail)
        {
            help->print();
            std::cout<<", ";  
            help = help->getN();      
        }
        help->print();
        }
    std::cout<<']'<<std::endl;
}
void MyList::add(int val)
{
    MyNode * temp = new MyNode(val,nullptr);
    if(_head)
        _tail->next(temp);
    else
        _head = temp;
        
    _tail = temp;
    _size++;
}
void MyList::clear()
{
    while(_head)
    {
        _tail = _head->getN();
        delete _head;
        _head =_tail;
        _size--;
    }
    _head = nullptr;
    _tail = nullptr;
}