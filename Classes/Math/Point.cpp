//
// Created by Emad Aghajani on 10/6/18.
//

#include "Point.h"
#include <iostream>
using namespace CompGeoVis;

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point& Point::operator=(const Point& rhs) {
    if(&rhs!=this) {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    return *this;
}

Point Point::operator+(const Point& rhs)
{
    Point res(this->x+rhs.x, this->y+rhs.y);
    return res;
}

Point& Point::operator+=(const Point& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

bool Point::operator==(const Point& rhs)
{
    return (x==rhs.x&&y==rhs.y);
}


void Point::Print() {
    std::cout<<"Point: "<<x<<","<<y<<std::endl;
}


