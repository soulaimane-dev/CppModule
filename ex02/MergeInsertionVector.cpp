/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertionVector.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:39:10 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/11 12:59:55 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void	PmergeMe::mergeVector(std::vector<std::pair<int, int> >& vec, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<std::pair<int, int> > L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = vec[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = vec[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i].first <= R[j].first) {
			vec[k] = L[i];
			i++;
		} else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		vec[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		vec[k] = R[j];
		j++;
		k++;
	}
}

void	PmergeMe::mergeSortVector(std::vector<std::pair<int, int> >& vec, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSortVector(vec, left, mid);
		mergeSortVector(vec, mid + 1, right);
		mergeVector(vec, left, mid, right);
	}
}


void	PmergeMe::sortVector()
{
	std::vector<std::pair<int, int> > vecPair;
	int x;
	if (vec.size() % 2 != 0)
	{
		x = vec.size() -1;
		saver = vec[vec.size() - 1];
	}
	else {
		x = vec.size();
	}
	for (int i = 0; i < x; i+=2) {
		vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
	}

	for (size_t i = 0; i < vecPair.size(); i++) {
		if (vecPair[i].first < vecPair[i].second)
		{
			std::swap(vecPair[i].first, vecPair[i].second);
		}
	}

	mergeSortVector(vecPair, 0, vecPair.size() - 1);

	vec.clear();
	vec.push_back(vecPair[0].second);
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		vec.push_back(vecPair[i].first);
	}
	for (size_t i = 1; i < vecPair.size(); i++) {
		vec.insert(std::lower_bound(vec.begin(), vec.end(), vecPair[i].second), vecPair[i].second);
	}
	if (saver != -1)
	{
		vec.insert(std::lower_bound(vec.begin(), vec.end(), saver), saver);
	}
}

