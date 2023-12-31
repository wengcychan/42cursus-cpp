#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <string>

template < typename T >
class Array {

	private:

		T *_array;
		int _size;

		int size(void) const
		{
			return _size;
		}

	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &src);
		Array<T> &operator=(Array<T> const &rhs);
		~Array<T>(void);

		T &operator[](int i);

};

#endif

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_array = new T[n];
	for (unsigned int i = 0; i < n; ++i)
		_array[i] = '\0';
}

template <typename T>
Array<T>::Array(Array<T> const &src)
{
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
		_array = new T[rhs._size];
		for (int i = 0; i < rhs._size; ++i)
			_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int i)
{
	if (i < 0 || i >= _size)
		throw std::out_of_range("Array<T>::index is out of bounds");
	return _array[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete []_array;
}

