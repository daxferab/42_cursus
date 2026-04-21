#include "include/Span.hpp"
#include "iostream"
#include <cstddef>
#include <exception>
#include <vector>

int main()
{
	//----------------------------- 5-length Span ----------------------------//
	std::cout << "Creating 5-length Span 'sp':" << std::endl;
	Span sp = Span(5);
	try
	{
		std::cout << "Filling sp..." << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(4); // Not enough space for this one
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "The shortest span in 'sp' is " << sp.shortestSpan() << std::endl;
	std::cout << "The largest span in 'sp' is " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	//------------------------------- Big Span -------------------------------//
	{
		std::cout << "Creating 10000000-length Span 'sp':" << std::endl;
		Span sp = Span(10000000);

		std::cout << "Filling sp..." << std::endl;
		for (size_t i = 0; i < 10000000; i++)	
			sp.addNumber(i);

		std::cout << "The shortest span in 'sp' is " << sp.shortestSpan() << std::endl;
		std::cout << "The largest span in 'sp' is " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	//----------------------------- addMultiple() ----------------------------//
	{
		std::cout << "Creating 5-length Span 'sp' and a vector = {0, 1, 2, 3, 4}:" << std::endl;
		Span spDup = Span(5);
		std::vector<int>	vect;
		for (size_t i = 0; i < 5; i++)
			vect.push_back(i);
		std::cout << "Filling with range (from vect)..." << std::endl;
		spDup.addMultiple(vect.begin(), vect.end());
		std::cout << "The shortest span in 'sp' is " << spDup.shortestSpan() << std::endl;
		std::cout << "The largest span in 'sp' is " << spDup.longestSpan() << std::endl;

		std::cout << "Trying to fill again (there should be no space)..." << std::endl;
		try
		{
			spDup.addMultiple(vect.begin(), vect.end());
		} catch (const std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	//------------------------- Copy and assignment --------------------------//
	std::cout << "Creating copy and assignement Spans from 'sp':" << std::endl;
	Span spCopy = Span(sp);
	Span spAssign = sp;

	std::cout << "The shortest span in 'spCopy' is " << spCopy.shortestSpan() << std::endl;
	std::cout << "The largest span in 'spCopy' is " << spCopy.longestSpan() << std::endl;
	std::cout << "The shortest span in 'spAssign' is " << spAssign.shortestSpan() << std::endl;
	std::cout << "The largest span in 'spAssign' is " << spAssign.longestSpan() << std::endl;
	return 0;
}
