#include "include/printTypes.hpp"

void	printChar(float f)
{
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f) || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(f);
		if (c >= 32 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void	printInt(float f)
{
	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) || f < INT_MIN || f > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
}

void	printFloat(float f)
{
	std::cout << "float: ";
	
	std::ios::fmtflags old_flags = std::cout.flags();
	std::streamsize old_precision = std::cout.precision();
	
	if (std::isnan(f))
		std::cout << "nanf";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "+inff");
	else
	{
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		if (f == static_cast<float>(static_cast<int>(f)))
		{
			std::cout.precision(1);
			std::cout << f << "f";
		}
		else
		{
			std::cout.precision(6);
			std::cout << f << "f";
		}
	}
	std::cout.flags(old_flags);
	std::cout.precision(old_precision);
	std::cout << std::endl;
}

void	printDouble(double d)
{
	std::cout << "double: ";
	
	std::ios::fmtflags old_flags = std::cout.flags();
	std::streamsize old_precision = std::cout.precision();
	
	if (std::isnan(d))
		std::cout << "nan";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf");
	else
	{
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		if (d == static_cast<double>(static_cast<int>(d)))
		{
			std::cout.precision(1);
			std::cout << d;
		}
		else
		{
			std::cout.precision(15);
			std::cout << d;
		}
	}
	std::cout.flags(old_flags);
	std::cout.precision(old_precision);
	std::cout << std::endl;
}
