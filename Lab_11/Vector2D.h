#pragma once

#include<iostream>

class Vector2D
{
    public:
    static Vector2D fromCarthesian(const double x,const double y);
    static Vector2D fromPolar(const double r,const double phi);
    Vector2D(const Vector2D & vect);
    Vector2D(Vector2D && vect);
    ~Vector2D();
    void print(std::string title) const;
    static const int number_vertices();
    double dot(const Vector2D & vect)const;
    Vector2D add(const Vector2D & vect)const;
    private:
    static int _counter;
    double _x,_y;
    Vector2D(const double x, const double y);
};