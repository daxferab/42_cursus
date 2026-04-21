#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_list;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		~Span();

		class listFull : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Not enough space in the list");
			}
		};
		class listNotLongEnough : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("The list has less than 2 members");
			}
		};
};

#endif
