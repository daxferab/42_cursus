#include "include/Bureaucrat.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Bureaucrat::Bureaucrat() : 
	_name("default"),
	_grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : 
	_name(name),
	_grade(150)
{
	setGrade(grade);
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : 
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called"<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other) {
		_grade = other._grade;
	}
	std::cout << "Bureaucrat Assignment Operator Called" << std::endl;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

/************************** ENCAPSULATED FUNCTIONS ****************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
