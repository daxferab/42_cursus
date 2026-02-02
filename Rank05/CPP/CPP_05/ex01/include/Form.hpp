#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_exeGrade;

	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		Form();
		Form(std::string name, int sign, int exe);
		Form(const Form &other);
		Form &operator=(const Form &other);

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExeGrade() const;

		void		beSigned(Bureaucrat *bureaucrat);

		~Form();
};

std::ostream	&operator<<(std::ostream& so, Form& f);

#endif
