//
// Created by Emad Aghajani on 10/6/18.
//

#include <gtest/gtest.h>
#include "../Classes/Math/Point.h"
using namespace CompGeoVis;

TEST(PointAssignment, objectAssignmentTest){
    Point *p1 = new Point(4,5);
    Point *p2;
    {
        p2 = new Point(*p1);
    }
    ASSERT_TRUE(p1->getX() == p2->getX());
    ASSERT_TRUE(p1->getY() == p2->getY());
    ASSERT_TRUE((*p1)==(*p2));
}


TEST(PointAssignment, plusEqual){
    Point p1 = Point(4,5);
    Point p1_copy = Point(p1);
    Point p3 = Point(p1);
    p1 += p1_copy;
    ASSERT_TRUE(Point(8,10)==p1);
    ASSERT_TRUE(p1_copy + p1_copy == p1);
}
