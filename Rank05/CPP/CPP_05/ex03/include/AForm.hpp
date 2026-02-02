#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <math.h>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_exeGrade;
		
		virtual void		executeAction() const = 0;

	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			virtual const char* what() const throw();
		};
		AForm();
		AForm(std::string name, int sign, int exe);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		std::string			getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExeGrade() const;
		void				beSigned(Bureaucrat *bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const;

		virtual ~AForm();
};

std::ostream	&operator<<(std::ostream& so, AForm& f);

#endif
