#pragma once

#include <string>

class VertexParser {
  private:
    std::string vertex_type;
    std::string vertex_content;
    std::size_t content_offset;

  public:
    VertexParser(const std::string &vertex_string);
    bool hasFloat() const;
    const std::string &getType() const;
    float getNextFloat();
};
