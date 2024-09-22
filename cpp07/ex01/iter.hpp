#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using namespace std;

template <typename T, typename F>
void	iter(T *arr, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	printElement(T element)
{
	cout << element << endl;
}

template <typename T>
void	incrementElement(T &element)
{
	element+=1;
}

#endif
