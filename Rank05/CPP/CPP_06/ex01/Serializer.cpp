#include "include/Serializer.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other) {}
	std::cout << "Serializer Assignment Operator Called" << std::endl;

	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
