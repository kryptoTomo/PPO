#include"MyString.h"

#include<cstring>
#include<iostream>

void MyString::set_string(const char * buffer)
{
    _str = new char[strlen(buffer)+1];
    strcpy(_str,buffer);
}
const char * MyString::str() const
{
    return _str;
}   
void MyString::join(const MyString & str)
{
    char * temp = new char[strlen(_str)+strlen(str._str)+1];
    strcpy(temp,_str);
    strcat(temp,str._str);
    delete []_str;
    _str = temp;
}
void MyString::replace(const char * buffer)
{
    delete []_str;
    set_string(buffer);
}
void MyString::swap(MyString & str)
{
    char * temp = _str;
    _str = str._str;
    str._str = temp;
}
void MyString::clear_string()
{
    if(_str)
    {
        std::cout<<"- deleting "<<_str<<std::endl;
        delete []_str;
        _str = nullptr;
    }
}