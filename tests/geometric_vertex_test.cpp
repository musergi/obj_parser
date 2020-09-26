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
    std::cout << "Test passed." << std::endl;
    return 0;
}