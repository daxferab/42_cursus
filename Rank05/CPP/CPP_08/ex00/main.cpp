#include "include/easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> intContainer;
    for (int i = 0; i < 7; i++)
        intContainer.push_back(i);
    std::cout << easyfind(intContainer, 3) + 1 << std::endl;
}
