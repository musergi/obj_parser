#include <iostream>
#include <obj_parser.hpp>

int main(int argc, char **argv)
{
    ObjContent obj_content;
    obj_content.addGeometricVertex(GeometricVertex(0.0f, 0.0f, 0.0f));
    if (!(obj_content.getGeometricVertex(0) == 
        GeometricVertex(0.0f, 0.0f, 0.0f)))
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "ObjContent did not return saved vertex." << std::endl;
        return 1;
    }
    obj_content.addVertexNormal(VertexNormal(0.0f, 0.0f, 1.0f));
    if (!(obj_content.getVertexNormal(0) == VertexNormal(0.0f, 0.0f, 1.0f)))
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "ObjContent did not return saved vertex." << std::endl;
        return 1;
    }
    if (obj_content.to_string() != "([(0, 0, 0, 1)], [(0, 0, 1)])")
    {
        std::cout << "Test failed." << std::endl;
        std::cout << obj_content.to_string() <<
            " did not match expected result" << std::endl;
        return 0;
    }
    std::cout << "Tests passed." << std::endl;
    return 0;
}
