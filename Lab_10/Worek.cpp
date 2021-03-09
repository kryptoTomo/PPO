#include"Worek.h"
#include<iostream>

Worek::Worek() : _lastGift(nullptr) {}

void Worek::Wloz(Prezent & gift)
{
    Prezent * temp = new Prezent(gift);
    temp->previous(_lastGift);
    _lastGift = temp;
}
const Prezent Worek::Wyciagnij()
{
    Prezent farewell;
    if(_lastGift)
    {
        farewell = *_lastGift;
        Prezent * prev = _lastGift->get_previous();
        delete _lastGift;
        _lastGift = prev;        
    }
    else
    {
        std::cout<<"Niestety, prezenty juz sie skonczyly."<<std::endl;
    }
    return farewell;
}