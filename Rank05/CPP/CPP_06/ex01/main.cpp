#include "include/Serializer.hpp"

int main()
{
	Data	*data = new Data;

	data->x = 2;
	data->y = 3;

	std::cout << "Original data: x = " << data->x << ", y = " << data->y << std::endl;

	std::cout << "Serializing and deserializing data structure..." << std::endl;
	uintptr_t seri = Serializer::serialize(data);
	Data* unserialized = Serializer::deserialize(seri);

	std::cout << "Converted data: x = " << unserialized->x << ", y = " << unserialized->y << std::endl;

	delete data;
	return 0;
}