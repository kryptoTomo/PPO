#pragma once

struct node
{
    char * data;
    node * previous, *next;
};
struct List
{
    node * head;
};

void prepare(List * array);
void push_back(List * array,const char * buffer);
void push_front(List * array,const char * buffer);
bool empty(const List * array);
void dump(const List * array);
void clear(List * array);