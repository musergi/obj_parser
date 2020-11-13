#include <obj_parser/ObjParser.hpp>

#include <cstdio>
#include <string>
#include <sstream>
#include <exception>


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
        } else if (line[0] == 'v') {
            float x, y, z;
            sscanf(line.c_str(), "%*s %f %f %f", &x, &y, &z);
            positions.push_back(x);
            positions.push_back(y);
            positions.push_back(z);
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

void ObjParser::toGLArrayBuffer(float* buffer, size_t buffer_size) {
    if (buffer_size < found_points.size() * sizeof(float))
        throw std::logic_error("Buffer too small");
    for (int i = 0; i < found_points.size(); i++) {
        const Point &point = found_points[i];
        const float position_offset = (point.vp - 1) * 3;
        buffer[i * 8 + 0] = positions[position_offset + 0];
        buffer[i * 8 + 1] = positions[position_offset + 1];
        buffer[i * 8 + 2] = positions[position_offset + 2];
        buffer[i * 8 + 3] = 0.0f;
        buffer[i * 8 + 4] = 0.0f;
        buffer[i * 8 + 5] = 0.0f;
        buffer[i * 8 + 6] = 0.0f;
        buffer[i * 8 + 7] = 0.0f;
    }
}