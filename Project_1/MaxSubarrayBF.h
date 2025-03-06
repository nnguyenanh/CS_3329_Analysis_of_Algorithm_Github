#pragma once
// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <iostream>
#include <vector>

int sumMaxSubarray_BF(const std::vector<int>& array)
{
	int sum_current = 0;
	int sum_max = array[0];
	int size = array.size();

	for (int count_1 = 0; count_1 < size; count_1++)
	{
		sum_current = 0;
		for (int count_2 = count_1; count_2 < size; count_2++)
		{
			sum_current += array[count_2];
			if (sum_current > sum_max)
			{
				sum_max = sum_current;
			}
		}
	}

	return sum_max;
}