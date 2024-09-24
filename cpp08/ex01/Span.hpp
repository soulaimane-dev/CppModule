#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

typedef unsigned int un_int ;

class	Span
{
	private:
		un_int _n;
		std::vector<int> _arr;
	public:
		Span(un_int n);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();

		class	errorMaxSpan : public std::exception
		{
			const char *what() const throw();
		};
		class	errorCalculateSpan : public std::exception
		{
			const char *what() const throw();
		};
};

#endif
