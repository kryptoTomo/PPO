#include"MyString.h"
#include<cstring>
MyString::MyString(){}
MyString::MyString(const char * buffer)
{
    _str = new char[strlen(buffer)+1];
    strcpy(_str,buffer);
}
MyString::MyString(const MyString & str)
{
    _str = new char[strlen(str._str)+1];
    strcpy(_str,str._str);
}
MyString::MyString(MyString && str)
{
    _str = str._str;
    str._str = nullptr;
}
MyString::~MyString()
{
    delete []_str;
}
std::ostream& operator<<(std::ostream& os,const MyString &buffer)
{
    return os << buffer._str;
}
MyString MyString::operator+(const MyString& str)const
{
    char * temp = new char[strlen(_str)+strlen(str._str)+1];
    strcpy(temp,_str);
    strcat(temp,str._str);
    MyString help(temp);
    delete []temp;
    return help;
}
void MyString::operator=(const MyString str)
{
    if(!strcmp(_str,str._str))
        return;
    delete []_str;
    _str = new char[strlen(str._str)+1];
    strcpy(_str,str._str);
}
MyString operator*(const int product,const MyString & str)
{
    MyString temp;
    if(product>0)
    {
        temp._str = new char[product*strlen(str._str)+1];
        strcpy(temp._str,str._str);
        for(int i = 1 ; i!=product;i++)
            strcat(temp._str,str._str);
    }
    return temp;
}
void MyString::operator*(const int product)
{
    if(product>1&&_str)
    {
        char * temp = new char[product*strlen(_str)+1];
        strcpy(temp,_str);
        for(int i = 1;i<product;i++)
            strcat(temp,_str);
        delete []_str;
       _str = temp; 
    }
}
bool MyString::operator==(const MyString & str)const
{
    if(strcmp(_str,str._str))
        return false;
    return true;
}