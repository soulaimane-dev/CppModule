#include "Span.hpp"
#include <algorithm>
#include <cstddef>

Span::Span(un_int n)
	: _n(n)
	{
		_arr.reserve(n);
		std::cout << "Constructor Called" << std::endl;
	}

Span::Span(const Span &other)
	: _n(other._n)
{
	*this = other;
	std::cout << "Copy Constructor Called" << std::endl;
}

Span	&Span::operator=(const Span &other)
{
	std::cout << "Copy Assignment Called" << std::endl;
	if (this != &other)
	{
		this->_n = other._n;
		_arr.reserve(_n);
		for (size_t i = 0; i < other._arr.size(); i++)
		{
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor Called" << std::endl;
}

const char * Span::errorMaxSpan::what() const throw()
{
	return "Span is full. Cannot add more numbers.";
}

const char * Span::errorCalculateSpan::what() const throw()
{
	return "Not enough numbers to calculate shortest span.";
}

void	Span::addNumber(int nbr)
{
	if (_arr.size() >= _n)
	{
		throw errorMaxSpan();
	}
	_arr.push_back(nbr);
}

int	Span::longestSpan()
{
	if (_arr.size() < 2)
	{
		throw errorCalculateSpan();
	}
	std::sort(_arr.begin(), _arr.end());
	return (_arr[_arr.size() - 1] - _arr[0]);
}

int	Span::shortestSpan()
{
	int min = _arr[_arr.size() - 1];
	if (_arr.size() < 2)
	{
		throw errorCalculateSpan();
	}
	std::sort(_arr.begin(), _arr.end());
	for (size_t i = 0; i < _arr.size() - 1; i++)
	{
		if ((_arr[i + 1] - _arr[i]) < min)
		{
			min = _arr[i + 1] - _arr[i];
		}
	}
	return min;
}

