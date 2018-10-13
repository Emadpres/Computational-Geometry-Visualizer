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

void Point::Print() {
    std::cout<<"Point: "<<x<<","<<y<<std::endl;
}


