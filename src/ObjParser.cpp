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
                int parsed_values = sscanf(point_string.c_str(), "%u/%u/%u",
                    &point.vp, &point.vt, &point.vn);
                if (parsed_values == 1) {
                    sscanf(
                        point_string.c_str(), "%u//%u", &point.vp, &point.vn);
                }
                if (!findAndAddIndex(point)) {
                    indices.push_back(unique_points.size());
                    unique_points.push_back(point);
                }
            }
        } else if (line[0] == 'v') {
            if (line[1] == ' ') {
                float x, y, z;
                sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
                positions.push_back(x);
                positions.push_back(y);
                positions.push_back(z);
            } else if (line[1] == 't') {
                float u, v;
                sscanf(line.c_str(), "vt %f %f", &u, &v);
                textures.push_back(u);
                textures.push_back(v);
            } else if (line[1] == 'n') {
                float i, j, k;
                sscanf(line.c_str(), "vn %f %f %f", &i, &j, &k);
                normals.push_back(i);
                normals.push_back(j);
                normals.push_back(k);
            }
        }
    }
}

bool ObjParser::findAndAddIndex(const Point& point) {
    int index = 0;
    for (auto& found_point: unique_points) {
        if (point == found_point) {
            indices.push_back(index);
            return true;
        }
        index++;
    }
    return false;
}

size_t ObjParser::getGLArrayBufferSize() const {
    return unique_points.size() * 8 * sizeof(float);
}

size_t ObjParser::getGLElementArrayBufferSize() const {
    return indices.size() * sizeof(unsigned int);
}

void ObjParser::toGLArrayBuffer(float* buffer, size_t buffer_size) {
    if (buffer_size < unique_points.size() * sizeof(float))
        throw std::logic_error("Buffer too small");
    for (int i = 0; i < unique_points.size(); i++) {
        const Point& point = unique_points[i];
        const unsigned int position_offset = (point.vp - 1) * 3;
        buffer[i * 8 + 0] = positions[position_offset + 0];
        buffer[i * 8 + 1] = positions[position_offset + 1];
        buffer[i * 8 + 2] = positions[position_offset + 2];
        if (point.vt) {
            const unsigned int texture_offset = (point.vt - 1) * 2;
            if (texture_offset + 1 >= textures.size())
                throw std::logic_error("Invalid format texture index");
            buffer[i * 8 + 3] = textures[texture_offset + 0];
            buffer[i * 8 + 4] = textures[texture_offset + 1];
        } else {
            buffer[i * 8 + 3] = 0.0f;
            buffer[i * 8 + 4] = 0.0f;
        }
        if (point.vn) {
            const unsigned int normal_offset = (point.vn - 1) * 3;
            if (normal_offset + 2 >= normals.size())
                throw std::logic_error("Invalid format normal index");
            buffer[i * 8 + 5] = normals[normal_offset + 0];
            buffer[i * 8 + 6] = normals[normal_offset + 1];
            buffer[i * 8 + 7] = normals[normal_offset + 2];
        } else {
            buffer[i * 8 + 5] = 0.0f;
            buffer[i * 8 + 6] = 0.0f;
            buffer[i * 8 + 7] = 0.0f;
        }
    }
}

void ObjParser::toGLElementArrayBuffer(
    unsigned int* buffer, unsigned long buffer_size) {
    if (buffer_size < indices.size() * sizeof(unsigned int))
        throw std::logic_error("Buffer too small");
    for (int i = 0; i < indices.size(); i++) {
        buffer[i] = indices[i];
    }
}
