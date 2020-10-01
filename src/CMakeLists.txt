add_library(obj_parser geometric_vertex.cpp vertex_normal.cpp obj_content.cpp
    face.cpp)
target_include_directories(obj_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
