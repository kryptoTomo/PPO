#pragma once

#include<iostream>
struct MapPoint
{
    std::string name;
    double longitude,latitude;
};
struct MapDist
{
    double longitude,latitude;
};
MapPoint* construct(const std::string name,const double latitude,const double longitude);
void print(const MapPoint * city);
MapDist distance(const MapPoint * const firstCity,const MapPoint secondCity);
const double distanceMag(const MapDist point);
MapPoint inTheMiddle(const MapPoint * const firstCity,const MapPoint * const secondCity,const std::string name);
MapPoint closestFrom(const MapPoint * reference,const MapPoint * firstCity,const MapPoint * secondCity);
std::string name(const MapPoint city);
void move(MapPoint ** city,const double moveLati,const double moveLong);
void clear(const MapPoint * city);
void clear(MapPoint ** cities,const int size);