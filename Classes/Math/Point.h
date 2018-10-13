//
// Created by Emad Aghajani on 10/6/18.
//


#ifndef COMPGEOVIS_POINT_H
#define COMPGEOVIS_POINT_H

namespace CompGeoVis {
    class Point {
    private:
        double x,y;
    public:
        double getX(){return x;}
        double getY(){return y;}
        Point(double x, double y);
        CompGeoVis::Point& operator=(const CompGeoVis::Point& rhs);
        void Print();
        virtual ~Point(){}
    };
}

#endif //COMPGEOVIS_POINT_H
