#pragma once
// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <vector>
#include <algorithm>

int sumMaxSubarray_CROSS(const std::vector<int>& array, int left, int mid, int right)
{
	// Find max left
	int sum = 0;
	int left_sum = INT_MIN; // INT_MIN = -2,147,483,648 - the smallest number of int
	for (int count = mid; count >= left; count--)
	{
		sum += array[count];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}

	// Find max right
	sum = 0;
	int right_sum = INT_MIN;
	for (int count = mid + 1; count <= right; count++)
	{
		sum += array[count];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}

	return left_sum + right_sum;
}

int sumMaxSubarray_DC(const std::vector<int>& array, int left, int right) 
{
	// Check if array is empty
	if (array.empty()) {
		std::cerr << "Array is empty." << std::endl;
		return 0;
	}

	// Base case left == right, subarray have only 1 element left
	if (left == right)
		return array[left];

	// Find middle point
	int mid = (left + right) / 2;

	// Return max subarray 3 case left, right or mid
	int left_sum_max = sumMaxSubarray_DC(array, left, mid);
	int right_sum_max = sumMaxSubarray_DC(array, mid + 1, right);
	int cross_sum_max = sumMaxSubarray_CROSS(array, left, mid, right);
	
	// Compare 3 values above and find max
	return std::max({left_sum_max, right_sum_max, cross_sum_max});
}