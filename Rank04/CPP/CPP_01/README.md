*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 01 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: BraiiiiiiinnnzzzZ
Create a **Zombie** class with a function that announces itself.\
Create the function `newZombie(std::string name)` that creates a zombie, names it and returns it.\
Create the function `randomChump(sdt::string name)` that creates a zombie, names it, and makes it announce itself. It returns nothing.

#### Concepts learnt
- In the `newZombie` function, the object Zombie is created with the **new** keyword, which allocates memory in heap so it can be used outside the function scope. It must be deleted by the user to prevent memory leaks.
- In the `randomChump` function, the object Zombie is created in stack. It's automatically deleted at the end of the function.

### Exercise 1️⃣: Moar brainz!
Create the function `zombieHorde(int N, sdt::string name)` that allocates N Zombies and names them. It returns a pointer to the first one.

#### Concepts learnt
- To create a heap allocated object array: `new Object[N]`
- To delete an entire object array: `delete[] objName`

### Exercise 2️⃣: HI THIS IS BRAIN
Write a program that contains:
- A string variable initialized to "HI THIS IS BRAIN".
- stringPTR: a pointer to the string.
- stringREF: a reference to the string.
Print the memory address and the value of the string.\
Print the memory address held by and the value pointed to of the PTR and the REF.

#### Concepts learnt
- A pointer is a variable that stores the memory location of the variable its pointed to.
- A reference to a variable is like an "alias" to that variable.

### Exercise 3️⃣: Unnecessary violence
Implement the **Weapon** class that has a *type*
Implement the **HumanA** and **HumanB** classes:
- They have a *weapon* and a *type*
- They can `attack()`
- **HumanA** takes the weapon in its constructor, **HumanB** doesn't, so it won't always be armed

#### Concepts learnt
Passing by reference vs pointer:
- HumanB might not have a weapon, so its attribute is a pointer that can be NULL.
- HumanA must be always armed, so it's passed by reference since it has to be assigned when instantiating the object.

### Exercise 4️⃣: Sed is for losers
Create a program that takes a file *example* and two words as parameters. It must create a file *example.replace*, with the content of the original file but replacing every instance of the second parameter with the third parameter.

#### Concepts learnt
- Opening a file with `std::ifstream file(filename)`
- Creating a new file with `std::ofstream newFile(newfilename)`
- Closing a file with `file.close()`
- Reading each line of a string with `getline(file, line)`
- std::string member functions:
	- `.find(word)` returns the position of the given word in the string
	- `.length()` returns length of a string
	- `.append(word)` appends given word to string
	- `.substr(pos)` creates a substring of the string from *pos*
	- `.clear()` clears a string

### Exercise 5️⃣: Harl 2.0
Create a class **Harl** that has a function `complain(LEVEL)`
the levels can be\
"DEBUG" "INFO" "WARNING" and "ERROR"\
Each one outputs a different message. If a different word is passed, nothing happens.

#### Concepts learnt
Pointers to member functions store the address of a function inside a class.\
`void (Class::*varname)(void) = &Class::function`\
This pointers need to know the class to which the pointed function belongs.\
It's used like a normal member function: `this->*varname()`

### Exercise 6️⃣: Harl filter
Same as exercise 5, but this time when a LEVEL is passed, the function outputs its message and the next levels' messages.\
For example, if the level is WARNING, it outputs the WARNING and ERROR messages.

#### Concepts learnt
The **switch** structure:
```
switch (num)
{
	case 0:
		//code
	case 1:
		//code
	...
	default:
}
```
The program ignores the sentence until *num* matches the case number, then, the code is executed until a `break;` sentence is found.\
In some languages, like C++, the user must explicit if a case is /\* fall through \*/ (no break) with a comment, otherwise the compiler prompts a warning/error.
