#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <cstddef>

template <typename T>
int    easyfind(T container, int n)
{
    for (size_t i = 0; i < container.size(); i++)
        if (container[i] == n)
            return (container[i]);
    return (-1);
}

#endif
