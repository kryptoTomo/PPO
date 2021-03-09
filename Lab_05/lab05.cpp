#include"lab05.h"
#include<cstring>
#include<iostream>
void prepare(List * array)
{
    array->head = nullptr;
}
void push_back(List * array,const char * buffer)
{
    node * tmp = new node;
    tmp->data = new char[strlen(buffer)+1];
    strcpy(tmp->data,buffer);
    tmp->next = nullptr;
    if(array->head)
    {
        node * help = array -> head;
        while(help -> next)
            help = help->next;
        tmp->previous = help;
        help->next = tmp;
    }
    else
    {
        tmp->previous=nullptr;
        array->head = tmp;
    }
}
void push_front(List * array,const char * buffer)
{
    node * tmp = new node;
    tmp->data = new char[strlen(buffer)+1];
    strcpy(tmp->data,buffer);
    tmp->previous = nullptr; 
    if(array->head)
    {
        tmp->next = array->head;
        array->head->previous = tmp;    
    }
    else
    {
        tmp->next = nullptr;
    } 
    array->head = tmp;
}
bool empty(const List * array)
{
    if(array->head)
        return false;
    return true;
}
void dump(const List * array)
{
    node * help = array -> head;
    while(help)
    {
        std::cout << help -> data << " ";
        help = help->next;
    }
}
void clear(List * array)
{
    if(array->head)
    {
        node * tmp = array->head;
        while(tmp)
        {
            delete []tmp->data;
            node * help = tmp->next;
            delete tmp;
            tmp = help;
        }
        array->head = nullptr;
    }
}