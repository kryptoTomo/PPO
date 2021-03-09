#pragma once
#include<iostream>

class MyString
{
    public:
    MyString();
    MyString(const char * buffer);
    MyString(const MyString & str);
    MyString(MyString && str);
    ~MyString();
    friend std::ostream& operator<<(std::ostream& os,const MyString &buffer);
    friend MyString operator*(const int product,const MyString & str);
    MyString operator+(const MyString& str)const;
    void operator=(const MyString str);
    void operator*(const int product);
    bool operator==(const MyString & str)const;
    private:
    char * _str = nullptr; 
};
std::ostream& operator<<(std::ostream& os,const MyString &buffer);
MyString operator*(const int product,const MyString & str);