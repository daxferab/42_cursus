#include "include/Jacobsthal.hpp"
#include <cmath>

// ------------------------------------------------------------ MEMBER FUNCTIONS

std::vector<int> Jacobsthal::getFullSequence(size_t count)
{
	std::vector<int> sequence;

	sequence.reserve(count);
	sequence.push_back(1);

	size_t generated = 1;
	int prevJacob = 1;
	int jPos = 3;

	while (generated < count)
	{
		int jacob = getNumber(jPos);
		int end = std::min(jacob, static_cast<int>(count));
		for (int n = end; n > prevJacob && generated < count; --n)
		{
			sequence.push_back(n);
			++generated;
		}
		prevJacob = jacob;
		++jPos;
	}
	return sequence;
}

int Jacobsthal::getNumber(int pos)
{
    if (pos == 0)
        return 0;
    if (pos == 1)
        return 1;

    int a = 0;
    int b = 1;

    for (int i = 2; i <= pos; ++i)
    {
        int c = b + 2 * a;
        a = b;
        b = c;
    }

    return b;
}
