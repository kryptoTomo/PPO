#include"Prezent.h"

#include<iostream>

int Prezent::_counter = 0;
Prezent::Prezent(): _value(0),_previous(nullptr) {
    ++_counter;
}
Prezent::Prezent(const float value): _value(value), _previous(nullptr){
    ++_counter;
}
Prezent::Prezent(const Prezent & gift):_value(gift._value),_previous(gift._previous){
    _counter++;
}
Prezent::~Prezent()
{
    --_counter;
}
void Prezent::Wypisz()const
{
    std::cout<<"Ten prezent kosztuje: "<<_value<<std::endl;
}
void Prezent::NapiszIleJestPrezentow()const
{
    std::cout<<"Aktualna liczba prezentow: "<<_counter<<std::endl;
}
void Prezent::previous(Prezent * prev)
{
    _previous = prev;
}

Prezent * Prezent::get_previous()
{
    return _previous;
}