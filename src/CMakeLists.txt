add_library(obj_parser vertex_parser.cpp point.cpp face_parser.cpp
			vertex_data.cpp obj_parser.cpp face.cpp obj_content.cpp)
target_compile_features(obj_parser PRIVATE cxx_defaulted_functions
    cxx_auto_type cxx_range_for)
