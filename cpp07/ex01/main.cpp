#include "iter.hpp"
#include <string>

int main()
{
	string arr[] = {"hello", "world", "Welcome"};
	::iter(arr, 3, ::printElement<std::string>);

	int	arr2[] = {10, 20, 30, 40};
	::iter(arr2, 4, ::incrementElement<int>);
	::iter(arr2, 4, ::printElement<int>);
}
