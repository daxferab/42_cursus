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

#### 💡Concepts learnt

### Exercise 2️⃣: Mutated abomination

#### 💡Concepts learnt
