*This project has been created as a part of the 42 curriculum by daxferna*
# 🖥️ CPP 02 🖥️

## Description

CPP is a group of projects using C++, an object oriented programing language.
The goal of these exercises is to introduce students to OOP through short exercises that aim to cover the most important points of this type of programming.

## Instructions

Each exercise has its own Makefile that will automatically compile every program, creating an output file. This file can be executed by the user to test the exercise's functionality.

## Exercises

### Exercise 0️⃣: My First Class in Orthodox Canonical Form
Create a class **Fixed** in Orthodox Canonical Form (every class will be OCF from now on).\
It will have two private attributes: an int (fixed-point number value) and an static const int (the number of fractional bits, set to 8).\
It will also have public members (apart from the OCF ones):\
`getRawBits(void) const`, that returns the raw value of the fixed-point\
`setRawBits(int const raw)` that sets it

#### 💡Concepts learnt
**Orthodox Canonical Form:**\
A class in OCF has the next public members:\
Default constructor: `Class()`\
Copy constructor: `Class(const Class &other)`\
Overload assignment operator: `Class &operator=(const Class &other)`\
Destructor: `~Class()`

An "overloaded operator" function is a function that defines the behave of an operator such as =, <, >...\
The syntaxis is `operatorX(...)`, being X the operator sign.\
In the assignment operator function, the class **other** changes its parameters to equal **this** . the function returns a reference to the changed class.

A fixed point value, is a binary number with a binary point, similar to a decimal point in decimal notation.\
It acts as a divider between the decimal and the fractional part of a number.\
The number 10100.1₂ equals 20.5₁₀:\
1 \* 2⁴ + 0 \* 2³ + 1 \* 2² + 0 \* 2¹ + 0 \* 2⁰ + 1 \* 2⁻¹ = 20.5

### Exercise 1️⃣: Towards a more useful fixed-point number class
Add the next public constructors and member functions to the Fixed class:\
Function that takes an int and converts it to a fixed-point value.\
Function that takes a float and converts it to a fixed-point value.\
`float toFloat( void ) const`: converts the fixed-point value to a floating-point value.\
`int toInt( void ) const`: converts the fixed-point value to an integer value.

Add the following function to the Fixed class files:\
Overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter.

#### 💡Concepts learnt
`Fixed(const int value)`:\
    setRawBits(value << _fractionalBits): if value is 3 (11 in binary), it moves it 8 bits to the left, which will convert it to 1100000000 (same as mutiplying the decimal by 2⁸).\
    Since the fractional bits is 8, the fixed-point number is 11.00000000 (3).\
    The number stored will be 1100000000 in decimal, which equals 768.

`toInt`is the same but in reverse.

`Fixed(const int value)`:\
    setRawBits(roundf(value * 256)): in this case, we get a float and we can't move its bits, therfore we directly multiplly it by 256 (2⁸).\
    Since we have to store it as an int, we round it with roundf().

`toFloat`:\
    `static_cast<float>(getRawBits()) / 256)` converts the raw bits to float and it divides it by 256 (2⁸), if the bits aren't converted, the result would be an int and lose decimals.

The "<<" overload:\
    The "<<" operator inserts something into an output stream.\
    `std::ostream& operator<<(std::ostream& os, const Fixed& f)`\
    In this case we are asked to insert a floating-point representation of the passed value (const Fixed& f) into the output stream object passed (std::ostream& os).\
    It's simply done by inserting *toFloat(f)* into *os*.

### Exercise 2️⃣: Now we're talking
Add the following to the Fixed class:\
- The 6 comparison operators: >, <, >=, <=, ==, and !=.
- The 4 arithmetic operators: +, -, *, and /.
- The 4 increment/decrement operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1.

Add these four public overloaded member functions to your class:
- Two static member functions `min` that take two references to:
    - Fixed-point numbers
    - Constant fixed-point numbers
    and return a reference to the smallest one.
- Two static member functions `max` that take two references to:
    - Fixed-point numbers
    - Constant fixed-point numbers
    and return a reference to the greatest one.

#### 💡Concepts learnt
Syntaxis of the comparison and arithmetic operators:\
`Class  &operatorX(const Class &other)`

Syntaxis of the increment / decrement operators:\
`Class	&Class::operator++()` and `Class	&Class::operator--()`\
Since the operator sign for post and pre are the same (++ and --), we distinguish the functions by passing a dummy int parameter in the postfix version.\
`Class	&Class::operator++(int)` and `Class	&Class::operator--(int)`\`

### Exercise 3️⃣: BSP

#### 💡Concepts learnt
