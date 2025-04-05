// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025

// Execution information:
// - Operating System: Windows 11.
// - IDE: Visual Studio 2022 Community .
//		+ Download link: https://visualstudio.microsoft.com/downloads/
// - Platform Toolset: Visual Studio 2022 (v143).
// - Language: ISO C++ 14 Standard.

#include <iostream>
#include <chrono>
#include "ManageFile_Part_123.h"
#include "CreateInput_Part_4.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;

const string FILE_NAME_PART_123 = "input_part_123.txt ";
const string SORT_NAME[3] = { "INSERTION_SORT", "QUICK_SORT", "MERGE_SORT" };
const int FILE_SIZE = 10;
const int MAX_RANGE = 0;
const int MIN_RANGE = 99999;

void print(const string, const vector<int>&);

int main()
{
	/*-------------------------------------------------------------------
	*																	*
	*							PART 1, 2, 3							*
	*																	*
	-------------------------------------------------------------------*/
	// Generate vector input file and 3 vectors for 3 sorts
	// 3 sort will sort the same input
	vector<int> array_insertion;
	vector<int> array_quick;
	vector<int> array_merge;
	generateRandomInputFile(FILE_NAME_PART_123, FILE_SIZE, MAX_RANGE, MIN_RANGE);
	readInputFileToVector(FILE_NAME_PART_123, array_insertion);
	readInputFileToVector(FILE_NAME_PART_123, array_quick);
	readInputFileToVector(FILE_NAME_PART_123, array_merge);
	
	// Prints to check the input vectors
	cout << "Vectors BEFORE sorting: " << "\n\n";
	print(SORT_NAME[0], array_insertion);
	print(SORT_NAME[1], array_quick);
	print(SORT_NAME[2], array_merge);
	
	// Operates 3 sorts
	INSERTIONSORT(array_insertion);
	QUICKSORT_EXTEND(array_quick, 0, array_quick.size() - 1);
	MERGESORT(array_merge, 0, array_merge.size() - 1);

	// Generates 3 output files after 3 sorts sorted those vectors
	generateOutputFile(SORT_NAME[0] + "_OUTPUT_PART_123", array_insertion);
	generateOutputFile(SORT_NAME[1] + "_OUTPUT_PART_123", array_quick);
	generateOutputFile(SORT_NAME[2] + "_OUTPUT_PART_123", array_merge);

	// Prints to check the sorted vectors
	cout << "Vectors AFTER sorting: " << "\n\n";
	print(SORT_NAME[0], array_insertion);
	print(SORT_NAME[1], array_quick);
	print(SORT_NAME[2], array_merge);


	/*-------------------------------------------------------------------
	*																	*
	*								PART 4								*
	*																	*
	-------------------------------------------------------------------*/
	// 8 cases, 8 input, insertion
	vector<vector<int>> input_ascending(4);
	vector<vector<int>> input_descending(4);
	generateInputPart4(input_ascending, input_descending);

	// To holds and calculates running time of sorts
	std::chrono::duration<double>time_insertion_input_1;
	std::chrono::duration<double>time_insertion_input_11;
	std::chrono::duration<double>time_insertion_input_2;
	std::chrono::duration<double>time_insertion_input_22;
	std::chrono::duration<double>time_insertion_input_3;
	std::chrono::duration<double>time_insertion_input_33;
	std::chrono::duration<double>time_insertion_input_4;
	std::chrono::duration<double>time_insertion_input_44;

	std::chrono::duration<double>time_quick_input_1;
	std::chrono::duration<double>time_quick_input_11;
	std::chrono::duration<double>time_quick_input_2;
	std::chrono::duration<double>time_quick_input_22;
	std::chrono::duration<double>time_quick_input_3;
	std::chrono::duration<double>time_quick_input_33;
	std::chrono::duration<double>time_quick_input_4;
	std::chrono::duration<double>time_quick_input_44;

	std::chrono::duration<double>time_merge_input_1;
	std::chrono::duration<double>time_merge_input_11;
	std::chrono::duration<double>time_merge_input_2;
	std::chrono::duration<double>time_merge_input_22;
	std::chrono::duration<double>time_merge_input_3;
	std::chrono::duration<double>time_merge_input_33;
	std::chrono::duration<double>time_merge_input_4;
	std::chrono::duration<double>time_merge_input_44;

	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();


	vector<int> clone;
	/*-------------------------------------------------------------------
	*																	*
	*			    Operates INSERTIONSORT for 8 inputs					*
	*																	*
	-------------------------------------------------------------------*/ 
	// ASCENDING ORDER INPUTS
	clone = input_ascending[0];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[1];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[2];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[3];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_4 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// DESCENDING ORDER INPUTS
	clone = input_descending[0];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_11 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[1];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_22 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[2];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_33 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[3];
	start = std::chrono::high_resolution_clock::now();
	INSERTIONSORT(clone);
	end = std::chrono::high_resolution_clock::now();
	time_insertion_input_44 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	/*-------------------------------------------------------------------
	*																	*
	*			      Operates QUICKSORT for 8 inputs					*
	*																	*
	-------------------------------------------------------------------*/
	// ASCENDING ORDER INPUTS
	clone = input_ascending[0];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[1];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[2];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[3];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_4 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// DESCENDING ORDER INPUTS
	clone = input_descending[0];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_11 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[1];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_22 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[2];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_33 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[3];
	start = std::chrono::high_resolution_clock::now();
	QUICKSORT_EXTEND(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_quick_input_44 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	/*-------------------------------------------------------------------
	*																	*
	*			      Operates MERGESORT for 8 inputs					*
	*																	*
	-------------------------------------------------------------------*/
	// ASCENDING ORDER INPUTS
	clone = input_ascending[0];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[1];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[2];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_ascending[3];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_4 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// DESCENDING ORDER INPUTS
	clone = input_descending[0];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_11 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[1];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_22 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[2];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_33 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	clone = input_descending[3];
	start = std::chrono::high_resolution_clock::now();
	MERGESORT(clone, 0, clone.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	time_merge_input_44 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// INSERTIONSORT ascending times
	cout << "TIME INSERTIONSORT ASCENDING ORDER INPUTS: " << '\n';
	cout << time_insertion_input_1.count() << '\n';
	cout << time_insertion_input_2.count() << '\n';
	cout << time_insertion_input_3.count() << '\n';
	cout << time_insertion_input_4.count() << '\n';
	// INSERTIONSORT descending times
	cout << "TIME INSERTIONSORT DESCENDING ORDER INPUTS: " << '\n';
	cout << time_insertion_input_11.count() << '\n';
	cout << time_insertion_input_22.count() << '\n';
	cout << time_insertion_input_33.count() << '\n';
	cout << time_insertion_input_44.count() << '\n';
	cout << '\n';

	// QUICKSORT ascending times
	cout << "TIME QUICKSORT ASCENDING ORDER INPUTS: " << '\n';
	cout << time_quick_input_1.count() << '\n';
	cout << time_quick_input_2.count() << '\n';
	cout << time_quick_input_3.count() << '\n';
	cout << time_quick_input_4.count() << '\n';
	// QUICKSORT descending times
	cout << "TIME QUICKSORT DESCENDING ORDER INPUTS: " << '\n';
	cout << time_quick_input_11.count() << '\n';
	cout << time_quick_input_22.count() << '\n';
	cout << time_quick_input_33.count() << '\n';
	cout << time_quick_input_44.count() << '\n';
	cout << '\n';
	
	// MERGESORT ascending times
	cout << "TIME MERGESORT ASCENDING ORDER INPUTS: " << '\n';
	cout << time_merge_input_1.count() << '\n';
	cout << time_merge_input_2.count() << '\n';
	cout << time_merge_input_3.count() << '\n';
	cout << time_merge_input_4.count() << '\n';
	// MERGESORT descending times
	cout << "TIME MERGESORT DESCENDING ORDER INPUTS: " << '\n';
	cout << time_merge_input_11.count() << '\n';
	cout << time_merge_input_22.count() << '\n';
	cout << time_merge_input_33.count() << '\n';
	cout << time_merge_input_44.count() << '\n';

	cout << '\n';
	system("pause");
	return 0;
}

void print(const string sort_name, const vector<int>& array)
{
	int size = array.size();
	cout << sort_name << '\n';
	for (int count = 0; count < size; count++)
	{
		cout << array[count] << '\t';
	}
	cout << '\n' << '\n';
}