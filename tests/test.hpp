#include <cstdlib>
#include <iostream>

template <class T, class S>
void assert_equals(T x, S y)
{
    if (!(x == y))
    {
        std::exit(1);
    }
}

