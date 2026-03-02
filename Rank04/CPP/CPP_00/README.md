*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 00 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Megaphone
Program that prints the passed parameters in uppercase, without spaces between each parameter.

If none passed, print:\
**\* LOUD AND UNBEARABLE FEEDBACK NOISE \***

#### 💡Concepts learnt
- **std::** is a namespace that lets the compiler know where to get functions or objects such as `cout`, `endl` or `string` from.
- Printing in C++ manner:

	`std::cout << "Message" << std::endl`\
	- **cout** outputs whatever follows "<<" to the console\
	- **endl** prints an endline
- **length()** is a method from the "string" object that returns the string length.

### Exercise 1️⃣: My Awesome PhoneBook
Program that creates a phonebook that stores up to 8 contacts. I has three options "ADD", "SEARCH" and "EXIT".

If a 9th contact is added, the oldest one is removed.

#### 💡Concepts learnt
- **getline(istring, str)**: Reads from the console input and stores the string in 'str'.
- `Classes` can have private and public methods like attributes or member functions:
	- **Private** methods can only be accessed inside a class instance scope
	- **Public** methods can be accessed outside the class instance scope

### Exercise 2️⃣: The Job Of Your Dreams
Reverse engineering exercise that has the files Account.hpp and main.cpp. The student must implement the Account methods so when the program is compiled, its output equals the given log file

#### 💡Concepts learnt
- Reverse engineering.
- `static` attributes: its values are common to every class instance. They are public.
- `std::time_t` and `std::tm`: variable types that let you store timestamps along with the `std::localtime` method.
	`tm` has its own attributes that store each component of a date (hours, minutes, month, day...).
