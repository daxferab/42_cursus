#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>

#define RED "\033[31m"
#define ADD '+'
#define SUBSTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'

class RPN {
	private:
		std::stack<int> _result;
	public:
		RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN&other);
		~RPN();

		int	solveOperation(char	*operation);
		void evaluate(char sign);

		class invalidToken : public std::exception {
			virtual const char* what() const throw();
		};

		class invalidSyntax : public std::exception {
			virtual const char* what() const throw();
		};

		class divisionByZero : public std::exception {
			virtual const char* what() const throw();
		};
};

bool isOperator(char token);

#endif
