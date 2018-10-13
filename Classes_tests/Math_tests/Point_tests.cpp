//
// Created by Emad Aghajani on 10/6/18.
//

#include <gtest/gtest.h>
#include "../Classes/Math/Point.h"
using namespace CompGeoVis;

TEST(PointAssignment, objectAssignmentTest){
    Point *p1 = new Point(4,5);
    Point *p2 = new Point(*p1);
    ASSERT_TRUE(p1->getX() == p2->getX());
    ASSERT_TRUE(p1->getY() == p2->getY());
}
