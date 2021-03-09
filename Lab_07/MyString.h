#pragma once

struct MyString
{
    char * str = nullptr;
};
static MyString exchange;
void init(MyString & word,const char * buffer);
MyString join(const MyString & str_1,const MyString & str_2);
void swap(MyString & str_1,MyString & str_2);
void swap(MyString *& str_1,MyString *& str_2);
void del(MyString & str_1,MyString & str_2 = exchange,MyString & str_3 = exchange,MyString & str_4 = exchange,MyString & str_5=exchange);