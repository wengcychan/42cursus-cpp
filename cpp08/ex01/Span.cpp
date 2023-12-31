#include <algorithm>
#include <limits.h>
#include "Span.hpp"

#include <iostream>

const char *Span::MaxLenException::what() const throw()
{
	return "Exceed maximum number of intergers";
}

const char *Span::NoSpanException::what() const throw()
{
	return "No span can be found";
}

Span::Span(unsigned int maxLen) : _maxLen(maxLen)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxLen = rhs._maxLen;

		for (std::vector<int>::const_iterator it = rhs._v.begin() ; it != rhs._v.end(); ++it)
			_v.push_back(*it);
	}
	return *this;
}

Span::~Span(void)
{
}

std::vector<int> const &Span::getSpan(void) const
{
	return _v;
}

void Span::addNumber(int number)
{
	if (_v.size() == _maxLen)
		throw MaxLenException();
	_v.push_back(number);
}

void Span::addManyNumbers(int array[], int size)
{
	if (_v.size() + size > _maxLen)
		throw MaxLenException();

	_v.insert(_v.end(), array, array + size);
}

int Span::shortestSpan(void)
{
	if (_v.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());

	int shortestSpan = INT_MAX;
	std::vector<int>::iterator it_prev = tmp.begin();

	for (std::vector<int>::iterator it = tmp.begin() + 1 ; it != tmp.end(); ++it)
	{
		if (*it - *it_prev < shortestSpan)
			shortestSpan = *it - *it_prev;
		it_prev = it;
	}

	return shortestSpan;
}

int Span::longestSpan(void)
{
	if (_v.size() < 2)
		throw NoSpanException();

	return *std::max_element(_v.begin(), _v.end()) 
		- *std::min_element(_v.begin(), _v.end());
}
