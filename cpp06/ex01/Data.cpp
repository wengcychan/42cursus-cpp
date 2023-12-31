#include "Data.hpp"

Data::Data(int value) : _value(value)
{
}

Data::Data(const Data &src)
{
	*this = src;
}

Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
		_value = rhs.getValue();
	return *this;
}

Data::~Data(void)
{
}

const int &Data::getValue(void) const
{
	return _value;
}
