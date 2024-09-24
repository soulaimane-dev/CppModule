#include "easyfind.hpp"
#include <vector>

int	main()
{
	try {
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		vec.push_back(60);
		std::vector<int>::iterator it = easyfind(vec, 40);
		std::cout << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		vec.push_back(60);
		std::vector<int>::iterator it = easyfind(vec, 140);
		std::cout << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
