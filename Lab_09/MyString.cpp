#include"MyString.h"

#include<iostream>
#include<cstring>

int MyString::_counter = 0;
MyString::MyString(const char * buffer)
{
    _str = new char[strlen(buffer)+1];
    strcpy(_str,buffer);
    ++_counter;
    _numStr = _counter;
}
MyString::~MyString()
{
    std::cout <<"- deleting "<<_str<<std::endl;
    --_counter;
    delete []_str;
}
MyString MyString::create(const char * buffer)
{
    return MyString(buffer);
}
void MyString::print() const
{
    std::cout<<"ID: "<<_numStr<<"str: "<<_str<<std::endl;
}
void MyString::join(const MyString & str)
{
    char * temp = new char[strlen(str._str)+strlen(_str)+1];
    strcpy(temp,_str);
    strcat(temp,str._str);
    delete []_str;
    _str = temp;
}
void MyString::replace(const char * buffer)
{
    delete []_str;
    _str = new char[strlen(buffer)+1];
    strcpy(_str,buffer);
}
void swap(MyString & str_1,MyString & str_2)
{
    char * temp = str_1._str;
    str_1._str = str_2._str;
    str_2._str = temp;   
}