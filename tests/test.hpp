#include <cstdlib>
#include <iostream>

template <class T, class S>
void assert_equals(T x, S y)
{
    if (!(x == y))
    {
        std::cout << "Test failed." << std::endl;
        std::exit(1);
    }
}

