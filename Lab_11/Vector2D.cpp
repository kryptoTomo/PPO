#include"Vector2D.h"
#include<cmath>

int Vector2D::_counter = 0;
Vector2D Vector2D::fromCarthesian(const double x,const double y)
{
    return Vector2D(x,y);
}
Vector2D Vector2D::fromPolar(const double r,const double phi)
{
    return Vector2D(r*cos(phi*M_PI/180), r*sin(phi*M_PI/180));
}
Vector2D::Vector2D(const double x, const double y) : _x(x), _y(y) {
    _counter ++;
}
Vector2D::Vector2D(const Vector2D & vect): _x(vect._x),_y(vect._y){
    print("copying ");
    _counter++;
}
Vector2D::Vector2D(Vector2D && vect):_x(vect._x),_y(vect._y)
{
    print("moving ");
    _counter++;
}
Vector2D::~Vector2D()
{
    --_counter;
}
void Vector2D::print(std::string title) const
{
    std::cout<<title<<"("<<_x<<", "<<_y<<")"<<std::endl;
}
const int Vector2D::number_vertices()
{
    return _counter;
}
double Vector2D::dot(const Vector2D & vect)const
{
    return (_x*vect._x)+(_y*vect._y);
}
Vector2D Vector2D::add(const Vector2D & vect)const
{
    return Vector2D(_x+vect._x,_y+vect._y);
}
