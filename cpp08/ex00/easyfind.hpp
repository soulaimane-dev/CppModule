#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class	error : public std::exception
{
	const char *what() const throw()
	{
		return "I couldn't find it";
	}
};

template <typename T>
typename T::iterator	easyfind(T &first, int second)
{
	typename T::iterator it = std::find(first.begin(), first.end(), second);
	if (it == first.end())
	{
		throw error();
	}
	return it;
}

#endif
