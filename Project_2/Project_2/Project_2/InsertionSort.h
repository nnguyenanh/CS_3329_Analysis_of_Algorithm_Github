#pragma once
// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025

#include <vector>

void INSERTIONSORT(std::vector<int>& array)
{

	int size = array.size();
	for (int count_1 = 1; count_1 < size; count_1++)
	{
		int key = array[count_1];		// Element that need to be inserted into sorted part
		int count_2 = count_1 - 1;		// Index of sorted part
		while (count_2 >= 0 && key < array[count_2])
		{
			array[count_2 + 1] = array[count_2];	// Shift element position
			count_2--;								// Decrement, loop through sorted part
		}
		array[count_2 + 1] = key;
	}
}