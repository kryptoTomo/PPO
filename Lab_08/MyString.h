#pragma once

class MyString
{
    public:
    void set_string(const char * buffer);
    const char * str() const;
    void join(const MyString & str);
    void replace(const char * buffer);
    void swap(MyString & str);
    void clear_string();
    private:
    char * _str = nullptr;
};