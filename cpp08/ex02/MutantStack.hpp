#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template < typename T >
class MutantStack : public std::stack<T> {

	public:

		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack(void);
		MutantStack(MutantStack &src);
		MutantStack<T> &operator=(MutantStack<T> &rhs);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;
		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void) const;
		
};

#endif

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &src)
{
	*this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> &rhs)
{
	for (typename std::stack<T>::container_type::iterator it = rhs.begin(); it != rhs.end(); ++it)
	{
		this->push(*it);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
	return this->c.rend();
}
