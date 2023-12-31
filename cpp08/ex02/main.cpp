#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"

int main (void)
{
	{
		std::cout << "----------- Mutant Stack -----------" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it; 
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << "----------- List -----------" << std::endl;
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it; 
		}
		std::list<int> s(mstack);
	}

	{
		MutantStack<int> stack;

		stack.push(1);
		stack.push(2);
		stack.push(3);

		std::cout << "----------- int begin() -----------" << std::endl;

		for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- int rbegin() -----------" << std::endl;

		for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- int cbegin() -----------" << std::endl;

		for (MutantStack<int>::const_iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- int crbegin() -----------" << std::endl;

		for (MutantStack<int>::const_reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	{
		MutantStack<float> stack;

		stack.push(1.23);
		stack.push(2.98);
		stack.push(3.45);

		std::cout << "----------- float begin() -----------" << std::endl;

		for (MutantStack<float>::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- float rbegin() -----------" << std::endl;

		for (MutantStack<float>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- float cbegin() -----------" << std::endl;

		for (MutantStack<float>::const_iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- float crbegin() -----------" << std::endl;

		for (MutantStack<float>::const_reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	{
		MutantStack<std::string> stack;

		stack.push("str1");
		stack.push("str2");
		stack.push("str3");

		std::cout << "----------- string begin() -----------" << std::endl;

		for (MutantStack<std::string>::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- string rbegin() -----------" << std::endl;

		for (MutantStack<std::string>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- string cbegin() -----------" << std::endl;

		for (MutantStack<std::string>::const_iterator it = stack.begin(); it != stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----------- string crbegin() -----------" << std::endl;

		for (MutantStack<std::string>::const_reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	return 0;
}