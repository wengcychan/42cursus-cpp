#ifndef ITER_HPP
# define ITER_HPP

template < typename T >
void iter (T *array, int n, void (*f)(const T &))
{
	for (int i = 0; i < n; ++i)
		f(array[i]);
}

template < typename T >
void print(const T &i)
{
	std::cout << i << std::endl;
}

#endif