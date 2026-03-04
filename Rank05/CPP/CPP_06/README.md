*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 06 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Conversion of scalar types
Write a non-instantiable class **ScalarConverter** that contains only one static method `convert()` that converts a string representation of a C++ literal and outputs it in this scalar types: `char`, `int`, `float` and `double`.\
If a conversion is not possible, print a message.\
Handle *-inff*, *+inff*, *nanf*, *-inf*, *+inf* and *nan*.

#### 💡Concepts learnt
To make a non-instantiable class, make the constructor/s private.\
**Static cast**: compiler-time type conversion. Used for conversions that are considered safe to the compiler:\
`static_cast<new_type>(data)`

### Exercise 1️⃣: Serialization
Write a non-instantiable class **Serializer** that has two member functions:\
`uintptr_t serialize(Data* ptr)`: takes a pointer and converts it to the unsigned integer type *uintptr_t*.\
`Data* deserialize(uintptr_t raw)`: It takes an unsigned integer parameter and converts it to a pointer to **Data**.

Create a non-empty **Data** structure.\
Serialize and deserialize a pointer to a **Data** object and compare them.

#### 💡Concepts learnt
**Reinterpret cast**: Convert a pointer to any other type of pointer without checking types. For example, casting to int, the value of a char held by a pointer:\
`reinterpret_cast<new_type>(data)`

### Exercise 2️⃣: Identify real type
Write a **Base** class that has a public virtual destructor.\
Create three empty classes **A**, **B**, and **C**, that publicly inherit from **Base**.\
Implement the following functions:\
`Base * generate(void)`: Randomly instantiates A, B, or C and returns the instance as a Base pointer.\
`void identify(Base* p)`: Prints the actual type of the object pointed to by p.\
`void identify(Base& p)`: Prints the actual type of the object referenced by p. Using a pointer is forbidden.

#### 💡Concepts learnt
**Dynamic cast**: mainly used for downcasting (converting an object of a base class to a derived class) in polymorphism and inheritance:\
`dynamic_cast<new_type>(data)`
