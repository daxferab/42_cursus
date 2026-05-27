*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 09 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises
### Exercise 0️⃣: Bitcoin exchange
Create a program that saves a csv database, which holds bitcoin prices over time (date,price).\
It will take as input a second database in the format "date | value" (y-m-d | 0-1000 float or int).\
The program will print the value of X bitcoins in a certain date (date => X = X * price).\
If the input date doesn't exist, use the closest lower one.\
Handle possible errors (wrong file, date, value).

#### 💡Concepts learnt
std::map -> stores unique (value - key) pairs. Efficient key search (map.lower_bound()) (No need to use multimap since there is only one value per date)

### Exercise 1️⃣: Reverse Polish Notation
Create a program that takes an inverted Polish mathematical expression as an argu-
ment:
 - The numbers will always be less than 10. The calculation and result do not take into account this rule.
 - Process this expression and output the result.
 - If an error occurs, display message on std error.
 - Handle operations with "+ - / *".
 - Don’t handle brackets or decimal numbers.

Standard usage:
	`./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"` -> `42`

#### 💡Concepts learnt
std::stack -> FIFO (First in first out) to follow the RPN logic

### Exercise 2️⃣: PmergeMe
Create a program that takes a positive integer sequence as an argument.\
It must use the merge-insert algorithm (Ford-Johnson) to sort the sequence.\
Use at least two different containers.\
Advise: implement an algorithm for each container (no generic function).\
Handle possible errors and display them (wrong input, duplicate numbers).

Guidelines for info display (4 lines):
- Explicit text + unsorted sequence
- Explicit text + sorted sequence
- Explicit message with the time taken by the algorithm (sorting + data management), specifying the **first** container used
- Explicit message with the time taken by the algorithm (sorting + data management), specifying the **second** container used

(The time precision must allow to clearly see the difference between the two containers)

#### 💡Concepts learnt
