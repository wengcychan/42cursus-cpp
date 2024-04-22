#include "PmergeMe.hpp"

const char *PmergeMe::PmergeMeException::what() const throw()
{
	return "Error";
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		try {
			int number = std::stoi(argv[i]);
			if (number <= 0)
				throw PmergeMeException();
			_beforeSort.push_back(number);
		}
		catch (std::exception &e) {
			throw PmergeMeException();
		}
	}
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_beforeSort = rhs._beforeSort;
		_pairs = rhs._pairs;
		_unpairedNbr= rhs._unpairedNbr;
		_mainChainList = rhs._mainChainList;
		_mainChainVector = rhs._mainChainVector;
		_insertChainList = rhs._insertChainList;
		_insertChainVector= rhs._insertChainVector;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sort()
{
	time startList = std::chrono::high_resolution_clock::now();

	this->groupPairs();
	this->formChain(_mainChainList, _insertChainList);
	this->insert(_mainChainList, _insertChainList);

	time stopList = std::chrono::high_resolution_clock::now();

	time startVector = std::chrono::high_resolution_clock::now();

	this->groupPairs();
	this->formChain(_mainChainVector, _insertChainVector);
	this->insert(_mainChainVector, _insertChainVector);

	time stopVector = std::chrono::high_resolution_clock::now();


	this->printResult(stopList, startList, stopVector, startVector);
}

void PmergeMe::groupPairs()
{
	std::set<int> seen;

	for (auto it = _beforeSort.begin(); it != _beforeSort.end(); it += 2) {
		
		if (seen.find(*it) != seen.end())
				throw PmergeMeException();
		seen.insert(*it);
		
		if (it + 1 == _beforeSort.end())
		{
			_unpairedNbr = _beforeSort.back();
			break;
		}

		if (seen.find(*(it + 1)) != seen.end())
				throw PmergeMeException();
		seen.insert(*(it + 1));
	
		if (*(it + 1) > *it)
			_pairs[*(it + 1)] = *it;
		else
			_pairs[*it] = *(it + 1);
	}
}

void PmergeMe::printResult(time stopList, time startList, time stopVector, time startVector)
{
	std::cout << "Before:";
	for (int &nbr : _beforeSort)
		std::cout << ' ' << nbr;
  std::cout << std::endl;

	std::cout << "After:";
	for (int &nbr : _mainChainList) 
		std::cout << ' ' << nbr;
  std::cout << std::endl;

	std::cout << "Time to process a range of " << _mainChainList.size() << " elements with std::list : "
		<<  std::chrono::duration<double, std::micro>(stopList - startList).count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _mainChainVector.size() << " elements with std::vector : "
		<< std::chrono::duration<double, std::micro>(stopVector - startVector).count() << " us" << std::endl;
}
