#include "RPN.hpp"
#include <iostream>

const char *RPN::RpnErrorException::what() const throw()
{
	return "Error";
}

RPN::RPN(std::string input) : _input(input)
{
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_stack = rhs._stack;
		_input = rhs._input;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::handleDigit(std::string::iterator it)
{			
	if (it != _input.begin())
	{
		if (std::isdigit(*(it - 1)))
			throw RpnErrorException();
	}
	_stack.push(static_cast<int>(*it - '0'));
}

void RPN::handleOperation(char &sign)
{
	if (_stack.size() < 2)
		throw RpnErrorException();

	float secondOperand = _stack.top();
	_stack.pop();
	float firstOperand = _stack.top();
	_stack.pop();

	switch (sign)
	{
		case '+':
			_stack.push(firstOperand + secondOperand);
			break;
		case '-':
			_stack.push(firstOperand - secondOperand);
			break;
		case '/':
			if (firstOperand == 0)
				throw RpnErrorException();
			_stack.push(static_cast<float>(firstOperand) / secondOperand);
			break;
		case '*':
			_stack.push(firstOperand * secondOperand);
			break;
		default:
			throw RpnErrorException();
	}
}

float RPN::calculate()
{
	if (_input.size() == 0)
		throw RpnErrorException();

	for (std::string::iterator it = _input.begin(); it != _input.end(); ++it)
	{
		if (std::isdigit(*it))
			handleDigit(it);
		else if (*it == '+' || *it == '-' || *it == '/' || *it == '*')
			handleOperation(*it);
		else if (*it == ' ')
			continue;
		else
			throw RpnErrorException();
	}

	if (_stack.size() > 1)
		throw RpnErrorException();

	return _stack.top();
}
