#include <cstdlib>
#include <iostream>

template <class T>
void assert_equals(T x, T y)
{
    if (!(x == y))
    {
        std::cout << "Test failed." << std::endl;
        std::exit(1);
    }
}

