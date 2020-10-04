#include <iostream>
#include <obj_parser/obj_parser.hpp>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "File argument required" << std::endl;
        return 1;
    }
    ObjContent obj_content(argv[1]);
    std::cout << obj_content.to_string() << std::endl;
    return 0;
}
