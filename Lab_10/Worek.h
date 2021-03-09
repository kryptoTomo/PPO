#pragma once
#include"Prezent.h"

class Worek
{
    public:
    Worek();
    void Wloz(Prezent & gift);
    const Prezent Wyciagnij();
    private:
    Prezent * _lastGift;
};