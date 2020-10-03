#pragma once

#include "obj_content.hpp"

class ObjFileParser
{
private:
    ObjContent *m_obj_content;
    std::vector<LineParser *> m_line_parsers;

public:
    ObjFileParser(ObjContent *obj_content);
    ~ObjFileParser();
    void parse(const char *path);

private:
    void buildLineParsers();

    class LineParser
    {
    private:
        const char *pattern;

    public:
        LineParser(const char *pattern);
        virtual ~LineParser();
        bool maches(const std::string &line) const;
        virtual void parse(const std::string &line,
                ObjContent *content) const;
    };

    class GeometricVertexLineParser : public LineParser
    {
    public:
        void parse(const std::string &line, ObjContent *content) const;
    };
};
