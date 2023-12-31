#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template < typename T >
int easyfind(T container, int target)
{
	if (std::find(container.begin(), container.end(), target) == container.end())
		return 1;
	return 0;
}

#endif