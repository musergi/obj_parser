#include "gtest/gtest.h"
#include "obj_parser/face.hpp"

TEST(face, empty_on_create) {
    Face face;
    ASSERT_EQ(face.getPointCount(), 0);
}

TEST(face, add_point) {
    Face face;
    face.addPoint(Point(2u, 3u, 6u));
    ASSERT_EQ(face.getPointCount(), 1);
}

TEST(face, get_point) {
    Face face;
    face.addPoint(Point(1u, 2u, 3u));
    ASSERT_EQ(face.getPoint(0).getGeometricVertexPointer(), 1u);
    ASSERT_EQ(face.getPoint(0).getTextureVertexPointer(), 2u);
    ASSERT_EQ(face.getPoint(0).getVertexNormalPointer(), 3u);
}