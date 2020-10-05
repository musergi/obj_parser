link_libraries(obj_parser)

add_executable(point_test point_test.cpp)
add_test(point point_test)

add_executable(face_test face_test.cpp)
add_test(face face_test)

add_executable(line_parser_test line_parser_test.cpp)
add_test(line_parser line_parser_test)

add_executable(vertex_test vertex_test.cpp)
add_test(vertex vertex_test)

add_executable(obj_content_test obj_content_test.cpp)
add_test(obj_content obj_content_test)

add_executable(vertex_parser_creation_test vertex_parser_creation_test.cpp)
add_test(vertex_parser_creation vertex_parser_creation_test)
add_executable(vertex_parser_getting_test vertex_parser_getting_test.cpp)
add_test(vertex_parser_getting vertex_parser_getting_test)

add_executable(obj_content_file_test obj_content_file_test.cpp)