#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main (void)
{
	Data data(42);

	Data *data1;

	data1 = Serializer::deserialize(Serializer::serialize(&data));

	std::cout << data.getValue() << std::endl;
	std::cout << data1->getValue() << std::endl;

	return 0;
}