#include <obj_parser/ObjParser.hpp>

#include <cstdio>
#include <string>
#include <sstream>

ObjParser::ObjParser(std::istream& input_stream) {
    std::string line;
    while (getline(input_stream, line)) {
        if (line[0] == 'f') {
            std::string point_string;
            std::istringstream line_stream(line);
            getline(line_stream, point_string, ' ');
            while (getline(line_stream, point_string, ' ')) {
                Point point;
                int parsed_values = sscanf(point_string.c_str(), "%u/%u/%u", &point.vp, &point.vt, &point.vn);
                if (parsed_values == 1) {
                    sscanf(point_string.c_str(), "%u//%u", &point.vp, &point.vn);
                }
                if (!contains(point)) {
                    found_points.push_back(point);
                }
            }
        }
    }
}

bool ObjParser::contains(const Point& point) const {
    for (auto& found_point: found_points) {
        if (point == found_point) {
            return true;
        }
    }
    return false;
}

size_t ObjParser::getGLArrayBufferSize() const { return found_points.size() * 8 * sizeof(float); }

void ObjParser::toGLArrayBuffer(float* buffer, size_t buffer_size) {}