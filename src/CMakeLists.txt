add_library(obj_parser obj_content.cpp face.cpp line_parser.cpp
	obj_file_parser.cpp vertex_parser.cpp)
target_compile_features(obj_parser PRIVATE cxx_defaulted_functions
    cxx_auto_type cxx_range_for)
