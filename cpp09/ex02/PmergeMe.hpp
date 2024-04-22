#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <stdexcept>
#include <map>
#include <list>
#include <vector>
#include <chrono>
#include <iostream>
#include <set>

class PmergeMe {

	private:

		typedef std::chrono::time_point<std::chrono::high_resolution_clock> time;

		std::vector<int> _beforeSort; 
		std::map<int, int> _pairs;
		int _unpairedNbr;
		std::list<int> _mainChainList;
		std::list<int> _insertChainList;
		std::vector<int> _mainChainVector;
		std::vector<int> _insertChainVector;

		PmergeMe();
		void groupPairs();
		void printResult(time stopList, time startList, time stopVector, time startVector);
	
		template <typename Container>
		void formChain(Container &_mainChain, Container &_insertChain);

		template <typename Container>
		void insert(Container &_mainChain, Container &_insertChain);

	public:

		class PmergeMeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();
		void sort();
};

#endif

template <typename Container>
void PmergeMe::formChain(Container &_mainChain, Container &_insertChain)
{
	for(auto &pair: _pairs)
		_mainChain.push_back(pair.first);

	for(auto &pair: _pairs)
		_insertChain.push_back(pair.second);

	if (_beforeSort.size() % 2 != 0)
		_insertChain.push_back(_unpairedNbr);
}

template <typename Container>
void PmergeMe::insert(Container &_mainChain, Container &_insertChain)
{
	for (auto itInsert = _insertChain.begin(); itInsert != _insertChain.end(); ++itInsert) {
			auto insertionPoint = std::lower_bound(_mainChain.begin(), _mainChain.end(), *itInsert);
			_mainChain.insert(insertionPoint, *itInsert);
	}

	if (_beforeSort.size() % 2 != 0 && (_mainChain.empty() || _unpairedNbr > _mainChain.back()))
			_mainChain.push_back(_unpairedNbr);
}
