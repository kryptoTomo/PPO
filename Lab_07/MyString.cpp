#include"MyString.h"
#include<cstring>
#include<iostream>
void init(MyString & word,const char * buffer)
{
    word.str = new char[strlen(buffer)+1];
    strcpy(word.str,buffer);
}
MyString join(const MyString & str_1,const MyString & str_2)
{
    MyString temp{new char[strlen(str_1.str)+strlen(str_2.str)+1]};
    strcpy(temp.str,str_1.str);
    strcat(temp.str,str_2.str);
    return temp;
}
void swap(MyString & str_1,MyString & str_2)
{
    MyString temp = str_1;
    str_1 = str_2;
    str_2 = temp;
}
void swap(MyString *& str_1,MyString *& str_2)
{
    MyString * temp = str_1;
    str_1 = str_2;
    str_2 = temp;
}
void destroy(MyString &word)
{
  if(word.str){
    std::cout<<"deleting "<<word.str<<std::endl;
    delete []word.str;
    word.str = nullptr;
  }
}
void del(MyString & str_1,MyString & str_2,MyString & str_3,MyString & str_4,MyString & str_5)
{
    if(&str_1 != &exchange)
        destroy(str_1);
    if(&str_2 != &exchange)
        destroy(str_2);
    if(&str_3 != &exchange)
        destroy(str_3);
    if(&str_4 != &exchange)
        destroy(str_4);
    if(&str_5 != &exchange)
        destroy(str_5);
}