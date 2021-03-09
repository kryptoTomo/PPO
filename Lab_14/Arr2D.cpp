#include"Arr2D.h"

Arr2D::Arr2D(){}
Arr2D::Arr2D(const int rows,const int columns)
{
    alloc(rows,columns);
    for(int i = 0; i!= _rows;i++)
        for(int j = 0; j!= _columns;j++)
            (*this)[i][j]=0;
}
Arr2D::Arr2D(const Arr2D & array):Arr2D(array._rows,array._columns)
{
    enter(array);
}
void Arr2D::alloc(int rows,int columns)
{
    _rows = rows;
    _columns = columns;
    _array = new int*[rows];
    for(int i = 0;i!=rows;i++)
        *(_array+i) = new int[columns];
}
void Arr2D::enter(const Arr2D & array)
{
    for(int i = 0; i!= _rows;i++)
        for(int j = 0; j!= _columns;j++)
            (*this)[i][j]=array[i][j];
}
void Arr2D::del()
{
    for(int i = 0;i!=_rows;i++)
        delete []*(_array+i);
    delete []_array; 
    _array =nullptr;  
    _rows = 0;
    _columns = 0;
}
Arr2D::~Arr2D()
{
    del();
}
Arr2D  Arr2D::adopt(const int * buffer,const int rows,const int columns)
{
    Arr2D temp;
    temp.alloc(rows,columns);
    int k = 0;
    for(int i = 0; i!= temp._rows;i++)
        for(int j = 0; j!= temp._columns;j++)
            temp._array[i][j] = buffer[k++];
    return temp;
}
int * Arr2D::operator[](const int & num)
{
    return *(_array+num);
}
const int * Arr2D::operator[](const int & num)const
{
    return *(_array+num);
}
void operator<<=(std::string buffer,const Arr2D & array)
{
    std::cout<<buffer<<std::endl;
    for(int i = 0; i!= array._rows;i++)
    {
        for(int j = 0; j!= array._columns;j++)
            std::cout<<array[i][j]<<" ";
        std::cout<<std::endl;    
    }
    std::cout<<buffer<<std::endl;
}
void Arr2D::operator=(const Arr2D &array)
{
    del();
    alloc(array._rows,array._columns);
    enter(array);
}