#pragma once

class MyString
{
    public:
    friend void swap(MyString & str_1,MyString & str_2);
    ~MyString();
    void print()const;
    static MyString create(const char * buffer);
    void join(const MyString & str);
    void replace(const char * buffer);
    private:
    static int _counter;
    int _numStr;
    MyString(const char * buffer);
    char * _str;
};
void swap(MyString & str_1,MyString & str_2);