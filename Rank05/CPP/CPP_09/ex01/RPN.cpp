#include "include/RPN.hpp"
#include <exception>
#include <sstream>
#include <climits>

// ---------------------------------------------------------------- Constructors

RPN::RPN() {}
RPN::RPN(const RPN& other) : _result(other._result) {}
RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_result = other._result;
	return *this;
}
RPN::~RPN() {}

// ------------------------------------------------------------ Member functions

long	RPN::solveOperation(char	*operation)
{
	std::stringstream	ss(operation);
	std::string			token;
	while (ss >> token)
	{
		if (token.size() == 1)
		{
			if (isOperator(token[0]))
			{
				try {
					evaluate(token[0]);
				} catch (std::exception &e) {
					throw;
				}
			}
			else if (isdigit(token[0]))
				_result.push(token[0] - '0');
			else
				throw invalidToken();
		} else {
			throw invalidToken();
		}
	}
	if (_result.size() == 1)
	{
		if (_result.top() >= INT_MIN && _result.top() <= INT_MAX)
			return _result.top();
		throw outOfBounds();
	}
	throw invalidSyntax();
}

void RPN::evaluate(char sign)
{
	if (_result.size() < 2)
		throw invalidSyntax();

	long b = _result.top();
	_result.pop();
	long a = _result.top();
	_result.pop();

	switch (sign) {
		case ADD:
			_result.push(a + b);
			break;
		case SUBSTRACT:
			_result.push(a - b);
			break;
		case MULTIPLY:
			_result.push(a * b);
			break;
		case DIVIDE:
			if (b == 0)
				throw std::out_of_range("Cannot divide by zero");
			_result.push(a / b);
			break;
	}
}

// ---------------------------------------------------------------------- Helper

bool isOperator(char token)
{
	return (token == ADD || token == SUBSTRACT || token == MULTIPLY || token == DIVIDE);
}

// ------------------------------------------------------------------ Exceptions

const char* RPN::invalidToken::what() const throw()
{
	return ("Invalid token. Allowed: +, -, *, /, 0-9");
}

const char* RPN::invalidSyntax::what() const throw()
{
	return ("Syntax is invalid.");
}

const char* RPN::divisionByZero::what() const throw()
{
	return ("Division by 0 not allowed");
}

const char* RPN::outOfBounds::what() const throw()
{
	return ("Result is out of 'int' bounds");
}
