#include"lab04.h"
#include<cmath>
MapPoint* construct(const std::string name,const double latitude,const double longitude)
{
    MapPoint * new_city = new MapPoint;
    new_city -> name = name;
    new_city ->latitude = latitude;
    new_city -> longitude = longitude;
    return new_city;
}
void print(const MapPoint * city)
{
    std::cout<<"Position of "<<city->name<<". Latitude: "<<city->latitude<<". Longitude: "<<city->longitude<<std::endl;
}
MapDist distance(const MapPoint * const firstCity,const MapPoint secondCity)
{
    return {firstCity->longitude-secondCity.longitude,firstCity->latitude-secondCity.latitude};
}
const double distanceMag(const MapDist point)
{
    return sqrt(pow(point.latitude,2)+pow(point.longitude,2));
}
MapPoint inTheMiddle(const MapPoint * firstCity,const MapPoint * secondCity,const std::string name)
{
    return {name,(firstCity->longitude+secondCity->longitude)/2,(firstCity->latitude+secondCity->latitude)/2};
}
MapPoint closestFrom(const MapPoint * reference,const MapPoint * firstCity,const MapPoint * secondCity)
{
    if(distanceMag(distance(reference,*firstCity))<distanceMag(distance(reference,*secondCity)))
        return *firstCity;
    return *secondCity;
}
std::string name(const MapPoint city)
{
    return city.name;
}
void move(MapPoint ** city,const double moveLati,const double moveLong)
{
    (*city)->latitude += moveLati;
    (*city)->longitude += moveLong;
}
void clear(const MapPoint * city)
{
    delete city;
}
void clear(MapPoint ** cities,const int size)
{
    for(int i = 0 ; i < size ; i++)
        delete *(cities+i);
}