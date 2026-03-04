*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 05 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Mommy, when I grow up, I want to be a bureaucrat!
Create a class **Bureaucrat** that has a *const name* and a *grade* (1 - 150).\
Any attempt to instantiate a bureaucrat with an invalid grade must throw an exception:\
`Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`.\
Provide a getter for both attributes and two functions that increment and decrement the grade.\
Implement an overload of the insertion operator "<<".

#### 💡Concepts learnt
To create an exception from a class, it must be encapsulated inside of that class declaration (for cohesion) and inherit from std::exception.
```
class MyException : public std::exception
{
	virtual const char* what() const throw();
};
```
Then, implement the what() function, that will return the exception.
Use the try-catch block to handle the exception:
```
try
{
	// Block of code that can throw an exception
}
catch (std::exception& e)
{
	std::cout << "Exception caught: " << e.what() << std::endl;
}
```

### Exercise 1️⃣: Form up, maggots!
Create a class **Form** that has these private attributes: *const name*, bool *signed*, *const sign grade* and *const execute grade*.\
The exceptions for the grades are the same as in the **Bureaucrat** class.\
Implement getters and the overload of the insertion operator.\
Add a `beSigned()` member function (in **Form**) that changes the signed parameter if the bureaucrat grade is high enough.\
Add a `signForm()` (in **Bureaucrat**), that calls `beSigned()`, it prints wether the form could be signed or not.

#### 💡Concepts learnt
Since the exception must be encapsulated and both classes use the same exception, it must be declared inside each class (repetition).\

### Exercise 2️⃣: No, you need form 28B, not 28C...
Convert the **Form** class into an abstract class.\
These classes will inherit from **AForm**:\
`ShrubberyCreationForm`: sign 145 and exec 137.\
`RobotomyRequestForm`: sign 72 and exec 45.\
`PresidentialPardonForm`: sign 25 and exec 5.\
They take *target* as a parameter.\
Add `execute(Bureaucrat const & executor) const` member function to **AForm** and implement a function to execute each form.\
Add a `exectueForm()` (in **Bureaucrat**), that calls, it prints wether the form could be executed or not.

#### 💡Concepts learnt

### Exercise 3️⃣: At least this beats coffee-making
Implement an **Intern** class without attrubutes.\
It has a member function `makeForm()` that takes two strings: *name* and *target*. It returns a pointer to an AForm object *name* with the target initialized to *target*.\

#### 💡Concepts learnt
Instead of creating a long if/else structure, we use a switch and an array of string to handle the different cases.
