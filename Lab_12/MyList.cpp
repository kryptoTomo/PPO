#include"MyList.h"
#include<iostream>


MyList::MyList()
{
    std::cout<<"KONST: Domyslny"<<std::endl;
}
MyList::MyList(const int size) : MyList()
{
    
    std::cout<<"KONST: Jednoargumentowy"<<std::endl;
    for(auto i = 0 ; i!=size;i++)
        add(i);
}
MyList::MyList(std::initializer_list<int> buffer)
{
    std::cout<<"KONST: std::initializer_list"<<std::endl;
    for(auto i = buffer.begin(); i!=buffer.end();i++)
        add(*i);
}
MyList::MyList(const MyList & temp) : MyList()
{
    std::cout<<"KONST: kopiujacy"<<std::endl;
    MyNode * help = temp._head;
    while(help)
    {
        add(help->val());
        help = help->next();
    }
}
MyList::MyList(MyList && temp)
{
    std::cout<<"KONST: przenoszacy"<<std::endl;
    _size = std::__exchange(temp._size, 0);
    _head = std::__exchange(temp._head, nullptr);
    _tail = std::__exchange(temp._tail, nullptr);

}
MyList::MyList(int (*function)(MyNode * node),const int size)
{
    std::cout<<"KONST: funkcja generujaca"<<std::endl;
    if(size>0)
    {
        add(function(_head));
        MyNode * previous = _head;
        for(int i = 1;i!=size;i++)
        {
            add(function(previous));
            previous = previous->next();
        }
    }
}
MyList::~MyList()
{
    std::cout<<"DESTRUKTOR (rozmiar = "<<_size<<")"<<std::endl;
    if(_size)
        clear();
}
bool MyList::empty()const
{
    if(_size)
        return false;
    return true;
}
const int MyList::size()const
{
    return _size;
}
void MyList::print()const
{
    std::cout<<"[";
    if(_head)
        MyNode::print(_head,_tail);
    std::cout<<"]"<<std::endl;
}
void MyList::clear()
{
    MyNode::del(_head,_tail,_size);
}
void MyList::add(const int buffer)
{
    MyNode::add(_head,_tail,_size,buffer);
}