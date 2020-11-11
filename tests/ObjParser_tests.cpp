#include "gtest/gtest.h"
#include "obj_parser/ObjParser.hpp"

#include <sstream>

#define VERTEX_COMPONENTS 8
#define ARRAY_BUFFER_STRIDE_SIZE VERTEX_COMPONENTS * sizeof(float)

TEST(obj_parser, creation) {
    std::istringstream stream("v 0.0 0.0 0.0");
    ObjParser obj_parser(stream);
}

TEST(obj_parser, vertex_size) {
    std::istringstream stream1("v 0.0 0.0 0.0");
    ObjParser obj_parser1(stream1);
    ASSERT_EQ(obj_parser1.getGLArrayBufferSize(), 0);

    std::istringstream stream2(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    ObjParser obj_parser2(stream2);
    ASSERT_EQ(obj_parser2.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 3);

    std::istringstream stream3(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.1 0.0\n"
        "f 1 2 3\n"
        "f 1 3 4");
    ObjParser obj_parser3(stream3);
    ASSERT_EQ(obj_parser3.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 4);

    std::istringstream stream4(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.1 0.0\n"
        "vt 0.0 0.0\n"
        "vn 0.0 0.0 1.0\n"
        "f 1/1/1 2/1/1 3/1/1\n"
        "f 1/1/1 3/1/1 4/1/1");
    ObjParser obj_parser4(stream4);
    ASSERT_EQ(obj_parser4.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 4);

    std::istringstream stream5(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.1 0.0\n"
        "vt 0.0 0.0\n"
        "vt 1.0 1.0\n"
        "f 1/1 2/1 3/1\n"
        "f 1/2 3/2 4/2");
    ObjParser obj_parser5(stream5);
    ASSERT_EQ(obj_parser5.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 6);

    std::istringstream stream6(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "vn 0.0 0.0 1.0\n"
        "vn 0.0 0.0 -11.0\n"
        "f 1//1 2//1 3//1\n"
        "f 1//2 2//2 3//2");
    ObjParser obj_parser6(stream6);
    ASSERT_EQ(obj_parser6.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 6);
}

TEST(obj_parser, vertex_buffer) {
    std::istringstream stream1(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    float buffer1[3 * VERTEX_COMPONENTS];
    ObjParser obj_parser1(stream1);
    obj_parser1.toGLArrayBuffer(buffer1, sizeof(buffer1));
}