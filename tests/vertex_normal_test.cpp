#include <iostream>
#include <obj_parser.hpp>

int main(int argc, char **argv)
{
    VertexNormal vn1(0.0, 0.0, 1.0);
    if (!(vn1 == VertexNormal(0.0, 0.0, 1.0)))
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "Equal operator not working." << std::endl;
        return 1;
    }
    if (vn1.to_string() != "(0, 0, 1)")
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "To string operation failed." << std::endl;
        return 1;
    }
    std::cout << "Tests passed." << std::endl;
    return 0;
}
