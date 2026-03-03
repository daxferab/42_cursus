*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 04 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Polymorphism
Implement the class **Animal** that has a *type* attribute.\
Implement a **Dog** and **Cat** classes that inherit from Animal.\
These two classes must set their type to "dog" or "cat".\
Every animal will have a makeSound() (different for each animal).

Create a WrongCat and WrongAnimal class that inherits incorrectly.

#### 💡Concepts learnt
In order for a class function to be overwritten, it must start with the *virtual* keyword.\
The destructor of a class with virtual functions must also be virtual.

WrongAnimal doesn't have the virtual keyword, so even when we override the member functions, the cat prints the default animal sound.

### Exercise 1️⃣: I don't want to set the world on fire
Implement a **Brain** class with an *array of 100 ideas*.\
**Dog** and **Cat** will have a private *Brain\** attribute.\
They will create a new Brain upon construction and delete it upon destruction.

Create an array of cats and dogs and loop it to delete it.\
The copies of the animals must not be shallow. (They must be deep copies)

#### 💡Concepts learnt
When copying or deleting classes that contain other classes within its attributes, we must also copy/delete that class properly.\

### Exercise 2️⃣: Abstract class
Convert the Animal class into a non-instantiable class.

#### 💡Concepts learnt
An abstract class is a class that works as a base for other classes, but cannot be instantiated.\
Member functions of this class cannot be declared on its .cpp file, this must be done on each child file.\
To indicate this, the member functions are marked as virtual and equaled to 0.
