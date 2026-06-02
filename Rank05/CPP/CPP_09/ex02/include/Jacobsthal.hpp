#ifndef JACOBSTHAL_HPP
#define JACOBSTHAL_HPP

#include <vector>
#include <cstddef>

class Jacobsthal
{
	public:
		static std::vector<int>		getFullSequence(size_t count);

	private:
		Jacobsthal();
		Jacobsthal(const Jacobsthal &other);
		Jacobsthal &operator=(const Jacobsthal &other);
		~Jacobsthal();

		static int	getNumber(int pos);
};

#endif
