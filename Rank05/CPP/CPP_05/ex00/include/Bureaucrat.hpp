#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int grade);
		void		incrementGrade();
		void		decrementGrade();
};

std::ostream&	operator<<(std::ostream& so, const Bureaucrat& b);

#endif
