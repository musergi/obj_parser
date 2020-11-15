#include "gtest/gtest.h"
#include "obj_parser/ObjParser.hpp"

#include <sstream>

#define FLOAT_TOLERANCE 1e-8

#define VERTEX_COMPONENTS 8
#define ARRAY_BUFFER_STRIDE_SIZE VERTEX_COMPONENTS * sizeof(float)

TEST(obj_parser, creation) {
    std::istringstream stream("v 0.0 0.0 0.0");
    ObjParser obj_parser(stream);
}

TEST(obj_parser, vertex_size_no_faces) {
    std::istringstream stream("v 0.0 0.0 0.0");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), 0);
}

TEST(obj_parser, vertex_size_position_triangle) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 3);
}

TEST(obj_parser, vertex_size_position_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "f 1 2 3\n"
        "f 1 3 4");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 4);
}

TEST(obj_parser, vertex_size_complete_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "vt 0.0 0.0\n"
        "vn 0.0 0.0 1.0\n"
        "f 1/1/1 2/1/1 3/1/1\n"
        "f 1/1/1 3/1/1 4/1/1");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 4);
}

TEST(obj_parser, vertex_size_only_texture_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "vt 0.0 0.0\n"
        "vt 1.0 1.0\n"
        "f 1/1 2/1 3/1\n"
        "f 1/2 3/2 4/2");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 6);
}

TEST(obj_parser, vertex_size_only_normal_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "vn 0.0 0.0 1.0\n"
        "vn 0.0 0.0 -11.0\n"
        "f 1//1 2//1 3//1\n"
        "f 1//2 2//2 3//2");
    ObjParser obj_parser(stream);
    ASSERT_EQ(obj_parser.getGLArrayBufferSize(), ARRAY_BUFFER_STRIDE_SIZE * 6);
}

void assertFloatBufferEquals(
    float *actual, float *expected, unsigned int count) {
    for (int i = 0; i < count; i++) {
        ASSERT_NEAR(actual[i], expected[i], FLOAT_TOLERANCE);
    }
}

TEST(obj_parser, vertex_buffer_position_triangle) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    ObjParser obj_parser(stream);
    float buffer[3 * VERTEX_COMPONENTS];
    obj_parser.toGLArrayBuffer(buffer, sizeof(buffer));
    float buffer_expected[3 * VERTEX_COMPONENTS] = {0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    assertFloatBufferEquals(buffer, buffer_expected, 3 * VERTEX_COMPONENTS);
}

TEST(obj_parser, vertex_buffer_position_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "f 1 2 3\n"
        "f 1 3 4");
    ObjParser obj_parser(stream);
    float buffer[4 * VERTEX_COMPONENTS];
    obj_parser.toGLArrayBuffer(buffer, sizeof(buffer));
    float buffer_expected[4 * VERTEX_COMPONENTS] = {0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f};
    assertFloatBufferEquals(buffer, buffer_expected, 4 * VERTEX_COMPONENTS);
}

TEST(obj_parser, vertex_buffer_complete_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "vt 0.5 0.3\n"
        "vn 0.0 0.0 1.0\n"
        "f 1/1/1 2/1/1 3/1/1\n"
        "f 1/1/1 3/1/1 4/1/1");
    ObjParser obj_parser(stream);
    float buffer[4 * VERTEX_COMPONENTS];
    obj_parser.toGLArrayBuffer(buffer, sizeof(buffer));
    float buffer_expected[4 * VERTEX_COMPONENTS] = {0.0f, 0.0f, 0.0f, 0.5f,
        0.3f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.3f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 0.5f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f,
        0.3f, 0.0f, 0.0f, 1.0f};
    assertFloatBufferEquals(buffer, buffer_expected, 4 * VERTEX_COMPONENTS);
}

TEST(obj_parser, index_size) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    ObjParser obj_parser(stream);
    ASSERT_EQ(
        obj_parser.getGLElementArrayBufferSize(), 3 * sizeof(unsigned int));
}

TEST(obj_parser, index_size_complete_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "vt 0.5 0.3\n"
        "vn 0.0 0.0 1.0\n"
        "f 1/1/1 2/1/1 3/1/1\n"
        "f 1/1/1 3/1/1 4/1/1");
    ObjParser obj_parser(stream);
    ASSERT_EQ(
        obj_parser.getGLElementArrayBufferSize(), 6 * sizeof(unsigned int));
}

TEST(obj_parser, index_buffer_position_triangle) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "f 1 2 3");
    ObjParser obj_parser(stream);
    unsigned int buffer[3];
    obj_parser.toGLElementArrayBuffer(buffer, sizeof(buffer));
    unsigned int expected_buffer[3] = {0, 1, 2};
    ASSERT_EQ(buffer[0], expected_buffer[0]);
    ASSERT_EQ(buffer[1], expected_buffer[1]);
    ASSERT_EQ(buffer[2], expected_buffer[2]);
}

TEST(obj_parser, index_buffer_complete_quad) {
    std::istringstream stream(
        "v 0.0 0.0 0.0\n"
        "v 1.0 0.0 0.0\n"
        "v 1.0 1.0 0.0\n"
        "v 0.0 1.0 0.0\n"
        "vt 0.5 0.3\n"
        "vn 0.0 0.0 1.0\n"
        "f 1/1/1 2/1/1 3/1/1\n"
        "f 1/1/1 3/1/1 4/1/1");
    ObjParser obj_parser(stream);
    unsigned int buffer[6];
    obj_parser.toGLElementArrayBuffer(buffer, sizeof(buffer));
    unsigned int expected_buffer[6] = {0, 1, 2, 0, 2, 3};
    ASSERT_EQ(buffer[0], expected_buffer[0]);
    ASSERT_EQ(buffer[1], expected_buffer[1]);
    ASSERT_EQ(buffer[2], expected_buffer[2]);
    ASSERT_EQ(buffer[3], expected_buffer[3]);
    ASSERT_EQ(buffer[4], expected_buffer[4]);
    ASSERT_EQ(buffer[5], expected_buffer[5]);
}
