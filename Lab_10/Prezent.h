#pragma once

class Prezent
{
    public:
    Prezent();
    Prezent(const float value);
    Prezent(const Prezent & gift);
    ~Prezent();
    void previous(Prezent * prev);
    Prezent * get_previous();
    void Wypisz()const;
    void NapiszIleJestPrezentow()const;
    private:
    static int _counter;
    float _value;
    Prezent * _previous;
};