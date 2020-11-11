set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(tests face_tests.cpp ObjParser_tests.cpp)
target_link_libraries(tests obj_parser)
target_link_libraries(tests gmock_main)