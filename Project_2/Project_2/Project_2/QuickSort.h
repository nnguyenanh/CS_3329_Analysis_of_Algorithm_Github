#pragma once
// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025

#include <iostream>
#include <vector>
#include <random>

void PARTITION_EXTEND(std::vector<int>&, int, int, int&, int&);				// PARTITION' 
void RANDOMIZED_PARTITION_EXTEND(std::vector<int>&, int, int, int&, int&);	// RANDOMIZED-PARTITION'
int  RANDOM(int, int);														// RANDOM
void QUICKSORT_EXTEND(std::vector<int>&, int, int);							// QUICKSORT'

void PARTITION_EXTEND(std::vector<int>& array, int start, int end,
	int& pivot_start, int& pivot_end)
{
	int pivot_value = array[end];
	pivot_start = start;
	pivot_end = start;

	for (int count = start; count < end; count++)
	{
		if (array[count] < pivot_value)
		{
			std::swap(array[count], array[pivot_start]);
			if (pivot_start != pivot_end)
			{
				std::swap(array[count], array[pivot_end]);
			}
			pivot_start++;
			pivot_end++;
		}
		else if (array[count] == pivot_value)
		{
			std::swap(array[count], array[pivot_end]);
			pivot_end++;
		}
	}
	std::swap(array[end], array[pivot_end]);
}

void RANDOMIZED_PARTITION_EXTEND(std::vector<int>& array, int start, int end,
	int& pivot_start, int& pivot_end)
{
	// Randomly choose a pivot from the subarray between 'start' and 'end'
	int random_position = RANDOM(start, end);

	// Swap the element at the random position with the element at the 'end' position
	// This makes sure the pivot is at the end of the subarray (as required by PARTITION_EXTEND)
	std::swap(array[random_position], array[end]);

	// Call PARTITION_EXTEND to perform the partitioning around the pivot
	// After partitioning, the pivot will be placed in its correct position and the array
	// will be divided into two subarrays, one containing elements smaller than the pivot
	// and the other containing elements greater than the pivot.
	PARTITION_EXTEND(array, start, end, pivot_start, pivot_end);
}


int RANDOM(int start, int end)
{
	std::random_device seed;
	std::mt19937 prng(seed());
	std::uniform_int_distribution<int> dist(start, end);
	return dist(prng);
}

void QUICKSORT_EXTEND(std::vector<int>& array, int start, int end)
{
	if (start < end)
	{
		int pivot_start = 0;
		int pivot_end = 0;
		RANDOMIZED_PARTITION_EXTEND(array, start, end, pivot_start, pivot_end);
		QUICKSORT_EXTEND(array, start, pivot_start - 1);
		QUICKSORT_EXTEND(array, pivot_end + 1, end);
	}
}