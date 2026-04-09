*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 07 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Start with a few functions
Implement this function templates that take two parameters:
- `swap()`: swaps the two values given. No return.
- `min()`: compares them and returns the smallest one. (The second one if equal).
- `min()`: compares them and returns the greatest one. (The second one if equal).

They can be called with any type of argument (both of the same type and must support all the comparison operators)

#### 💡Concepts learnt
There are some functions that may be called with different type of arguments.\
Instead of creating the same function for each type, we use **templates**.\
A template function is a function that has one or more placeholders within his parameters, that accept all types of data.\
It is defined like this: `template <typename T>`, where T represents a type.\
T is used as a normal type in the function definition, then substituted with any type when calling it.

When calling a function that we created, the scope resolution operator (::) makes the compiler look for it in the global namespace. In this case, it's the same as not specifying it.\
When calling it with a direct value (not a variable), the type of it should be specified (`function<type>(x, y, ...)`), else, they will be set by default by the compiler. For example, if using 2 and 5 as parameters, the compiler will assume they are integers, if we want them to be a double, we may write `function<double>(2, 5)`.

### Exercise 1️⃣: Iter
Implement a function template `iter()` that returns nothing and takes 3 parameters:\
- Address of an array (any type)
- Lenght of the array (const)
- Function that will be called on every element of the array (even an instantiated function template). This function may take its argument by const or non-const.

#### 💡Concepts learnt
Passing an argument address: `T *addr`:\
The [] aren't needed, since the function doesn't need to know it is an array, only that it is a pointer to a T type variable

Passing a function as a template:\
`rv (*f)(param)`
- *rv* -> Return value of said function
- *f* -> Pointer to the function
- *param* -> List of parameters the function takes

When calling the function, we need to pass the parameter as the name of the other function without the (): `myFunction(passedFunction);`

*int* and *const int* are treated as different types, such as *int* and *double*.\
When using a function that gets *const T* as a parameter, ALL of the T values must be const (in this example, if the function takes a const int, the array passed to the iter function must be const int too)


### Exercise 2️⃣: Array

#### 💡Concepts learnt
