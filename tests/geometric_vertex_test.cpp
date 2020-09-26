#include <iostream>
#include <obj_parser.hpp>

int main(int argc, char **argv)
{
    GeometricVertex v1(0.0f, 0.0f, 0.0f, 1.0f);
    GeometricVertex v2(0.0f, 0.0f, 0.0f);
    if (!(v1 == v2))
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "Equal operator not working." << std::endl;
        return 1;
    }
    if (v1.to_string() != "(0, 0, 0, 1)")
    {
        std::cout << "Test failed." << std::endl;
        std::cout << "to_string method not working." << std::endl;
        std::cout << v1.to_string() << std::endl;
        return 1;
    }
    std::cout << "Tests passed." << std::endl;
    return 0;
}