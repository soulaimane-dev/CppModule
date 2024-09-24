#include <exception>
#include <iostream>
#include <vector>
#include "Span.hpp"

int	main()
{
	Span span(10);
	span.addNumber(90);
	span.addNumber(50);
	span.addNumber(40);
	span.addNumber(60);
	span.addNumber(70);
	span.addNumber(30);
	span.addNumber(80);
	span.addNumber(20);
	span.addNumber(10);
	span.shortestSpan();
}
