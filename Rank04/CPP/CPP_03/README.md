*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 03 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: Aaaaand... OPEN!
Create the class Claptrap with a name, hit points (10), energy points (10) and attack damage (0).\
It should attack, take damage and be repaired.\
When it attacks or repairs, ClapTrap loses 1 EP.\
ClapTrap cant to anything without EP.

#### 💡Concepts learnt
Good practice: class attributes should start with "_" ( _name, _hitPoints )

### Exercise 1️⃣: Serena, my love!
Create the class ScavTrap that inherits from ClapTrap. Its functions will print different messages.\
It has a name, hit points (100), energy points (50) and attack damage (20).\
It will also have its own ability "guard gate".

#### 💡Concepts learnt
If a class has childs, its destructor must be virtual.\
Attributes from a parent must be *protected* instead of *private* in order for a child class to be able to access them.\
When a child class is created, the program first creates the parent instance and then the child instance, same but in reverse happens when the instance is destroyed.\
The syntaxis for a child class is:\
`class ClassName: public ParentClassName`\
ScavTrap has no attributes declared since it inherits all of them from ClapTrap and initializes them on its constructor.\
A parent's function must be declared as virtual in order to be overriden byb its child.

### Exercise 2️⃣: Repetitive work
Create the class FragTrap that inherits from ClapTrap. Its functions will print different messages.\
It has a name, hit points (100), energy points (100) and attack damage (30).\
It will also have its own ability "high fives guys".

#### 💡Concepts learnt
Same as exercise 1

### Exercise 3️⃣: Now it's weird!
Create the class DiamondTrap that inherits from ScavTrap and FragTrap.\
DiamondTrap's _name variable must be named the same as Claptrap's.\
It has a name (ClapTrap's name + "_clap_name"), hit points (from FragTrap), energy points (from ScavTrap) and attack damage (from FragTrap).\
Its function attack will be inherited from ScavTrap.\
It will also have its own ability "who am I".

#### 💡Concepts learnt
The syntaxis for a child class inheriting from more than one class is:\
`class ClassName: public ParentOneClassName, public ParentTwoClassName`.

Virtual base classes prevent multiple instances when using multiple inheritance.\
`class ClassName: virtual public ParentClassName`\
Without this word, two ClapTraps would be created (one from FragTrap and one from ScavTrap).
