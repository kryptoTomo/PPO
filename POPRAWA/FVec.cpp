#include"FVec.h"
#include<cmath>
FVec::FVec(const int floor,const int ceil):_floor(floor),_ceil(ceil)
{
  
    _vect = new int[abs(_floor)+abs(_ceil)];
    for(int i = _floor ; i<_ceil;i++)
        (*this)[i] = 0;
}
FVec::FVec(const FVec & vect):FVec(vect._floor,vect._ceil)
{
    for(int i = _floor ; i<_ceil;i++)
        (*this)[i] = vect[i];
}
FVec::FVec(FVec && vect):_vect(vect._vect),_floor(vect._floor),_ceil(vect._ceil)
{
    vect._vect=nullptr;
    vect._floor = 0;
    vect._ceil = 0;
}
FVec::FVec(int (*function)(const int n),const int size):FVec(0,size)
{
    for(int i = _floor ; i<_ceil;i++)
        (*this)[i] = function(i);
}
FVec::~FVec()
{
    delete []_vect;
}
FVec FVec::create(const int buffer)
{
    return FVec(0,buffer);
}
void FVec::operator=(const FVec & vect)
{
    delete []_vect;
    _floor = vect._floor;
    _ceil = vect._ceil;
    _vect = new int[abs(_floor)+abs(_ceil)];
    for(int i = _floor ; i<_ceil;i++)
        (*this)[i] = vect[i];
}
int & FVec::operator[](const int num)
{
    if(num>=_ceil)
        return *(_vect + abs(_floor)+abs(_ceil)-1);
    return *(_vect-_floor+num);
}
const int & FVec::operator[](const int num)const
{
    if(num>=_ceil)
        return *(_vect + abs(_floor)+abs(_ceil)-1);
    return *(_vect-_floor+num);
}
FVec & FVec::set(const int num,const int val)
{
    (*this)[num]=val;
    return *this;
}
//Wektor a:idx[0,5] 7 6 5 -1 0
std::ostream& operator<<(std::ostream& os,const FVec &vect)
{
    os << "idx["<<vect._floor<<","<<vect._ceil<<"]";
    for(int i = vect._floor;i<vect._ceil;i++)
        os<<" "<<vect[i];
    return os;
}
const int FVec::begin()const
{
    return _floor;
}
const int FVec::end()const
{
    return _ceil;
}