// HOMEWORK 5
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : March 7, 2025

// Execution information:
// - Operating System: Windows 11.
// - IDE: Visual Studio 2022 Community.
//		+ Download link: https://visualstudio.microsoft.com/downloads/
// - Platform Toolset: Visual Studio 2022 (v143).
// - Language: ISO C++ 14 Standard.

#include <iostream>
#include <vector>
#include <random>
using namespace std;

void PARTITION_EXTEND(vector<int>&, int, int, int&, int&);				// PARTITION' 
void RANDOMIZED_PARTITION_EXTEND(vector<int>&, int, int, int&, int&);	// RANDOMIZED-PARTITION'
int  RANDOM(int, int);													// RANDOM
void RANDOMIZED_QUICKSORT_EXTEND(vector<int>&, int, int);				// QUICKSORT'
void print(vector<int>&);

int main()
{
	vector<int> array = { 3, 1, 4, 6, 4, 2, 1, 4, 8, 1, 2, 9, 5, 5 };
	print(array);

	RANDOMIZED_QUICKSORT_EXTEND(array, 0, array.size() - 1);
	print(array);

	cout << '\n';
	system("pause");
	return 0;
}

void PARTITION_EXTEND(vector<int>& array, int start, int end,
	int &pivot_start, int &pivot_end)
{
	int pivot_value = array[end];
	pivot_start = start;
	pivot_end = start;

	for (int count = start; count < end; count++)
	{
		if (array[count] < pivot_value)
		{
			swap(array[count], array[pivot_start]);
			if (pivot_start != pivot_end)
			{
				swap(array[count], array[pivot_end]);
			}
			pivot_start++;
			pivot_end++;
		}
		else if (array[count] == pivot_value)
		{
			swap(array[count], array[pivot_end]);
			pivot_end++;
		}
	}
	swap(array[end], array[pivot_end]); 
}

void RANDOMIZED_PARTITION_EXTEND(vector<int>& array, int start, int end,
	int &pivot_start, int &pivot_end)
{
	int random_position = RANDOM(start, end);
	swap(array[random_position], array[end]);

	PARTITION_EXTEND(array, start, end, pivot_start, pivot_end);
}

int RANDOM(int start, int end)
{
	std::random_device seed;
	std::mt19937 prng(seed());
	std::uniform_int_distribution<int> dist(start, end);
	return dist(prng);
}

void RANDOMIZED_QUICKSORT_EXTEND(vector<int>& array, int start, int end)
{
	if (start < end)
	{
		int pivot_start = 0;
		int pivot_end = 0;
		RANDOMIZED_PARTITION_EXTEND(array, start, end, pivot_start, pivot_end);
		RANDOMIZED_QUICKSORT_EXTEND(array, start, pivot_start - 1);
		RANDOMIZED_QUICKSORT_EXTEND(array, pivot_end + 1, end);
	}
}

void print(vector<int>& array)
{
	int size = array.size();
	for (int count = 0; count < size; count++)
	{
		cout << array[count] << '\t';
	}
	cout << '\n';
}