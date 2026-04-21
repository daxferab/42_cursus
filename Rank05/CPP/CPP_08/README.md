*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 08 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Easy find
Write a function template `easyfind` with two parameters:
- A type **T**
- An integer

Assuming **T** is a container of integers, it finds the first occurrence of the second parameter in the first one.\
Throw an exception or return an error value if no occurence is found.\

#### 💡Concepts learnt
Two types of containers in C++:
- Sequence:
	- `std::vector` : Dynamic one dimension array. Can be iterated with [].
	- `std::list` : Double linked list. Has to be iterated with **std::list<>::iterator**
	- `std::deque` : Double end queue. Can be iterated with [].
- Associative: (not used in this exercise)
	- `std::set`: Store unique elements or duplicates (`std:multiset`).
	- `std::map`: Store key-value pairs. Use `std::multimap` for duplicated keys.

The std::find function finds "n" within a container, returns an iterator. Returns cont.end() if not found.\
`std::find(cont.begin(), cont.end(), n);`

### Exercise 1️⃣: Span
Write a Span class that stores max N (unsigned int) integers:
- N will be the only parameter passed to the Span constructor.
- Member function `addNumber()`: Adds a number to the span. (If size = N, throw an exception).
- Member functions `shortestSpan()` and `longestSpan()`: They will find out the shortest/longest span between all the numbers stored and return it. (If numbers stored < 2, throw an exception).
- member function that adds multiple numbers in a single call.

#### 💡Concepts learnt
New functions:
- `std::sort` : Sorts a container.
- `std::min_element` / `std::max_element` : Finds the smallest / largest element.
- `std::distance` : Returns the distance between two iterators.
- `std::copy` : Copies all elements within a range into another container. `std::back_inserter` inserts an element in the back of a container and moves to the next position.

To insert elements into an uninitialized `std::vector`, we need to use `.push_back()`, if its initialized (vector(n)), we can insert them with an index (`vector[i]`) up to **n**.
### Exercise 2️⃣: Mutated abomination

#### 💡Concepts learnt
