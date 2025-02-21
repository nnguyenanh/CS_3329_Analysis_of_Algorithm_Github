// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <iostream>
#include <string>

// For managing files
#include "InputFileGenerate.h"
#include "InputFileRead.h"

// Brute-force and Divide-and-Conquer algorithm 
// for finding maximum subarray 
#include "MaxSubarrayBF.h"
#include "MaxSubarrayDC.h"

// For calculate execution time
#include "CalculateExecutionTime.h"


// Defining CONSTANT and GLOBAL
const int MIN = -999'999;							// Min value of those cases
const int MAX = 999'999;							// Max value of those cases

const int INPUT_CASE = 5;							// 5 input cases
const int INPUT_CASE_SIZE[INPUT_CASE] = 
		{ 100, 1'000, 10'000, 100'000, 1'000'000 }; // Size of those 5 cases
const std::string INPUT_FILE_NAME_PREFIX = "input_";// File name prefix
const std::string FILE_EXTENSION = ".txt";			// File extension

std::vector<std::string> INPUT_FILE_NAME;			// vector to store files' name
std::vector<std::vector<int>> ARRAY;				// 2D vector to store all numbers in input files

int main()
{
	// Generate 5 input files
	for (int count = 0; count < INPUT_CASE; count++)
	{
		// Create name, put them into the GLOBAL vector
		INPUT_FILE_NAME.emplace_back(INPUT_FILE_NAME_PREFIX + std::to_string(count + 1)
			+ FILE_EXTENSION);
		// Create the input files (input_1.txt, input_2.txt, ...)
		generateRandomInputFile(INPUT_FILE_NAME[count],
			INPUT_CASE_SIZE[count], MIN, MAX);
	}
	
	// Read 5 input files to vector
	for (int count_1 = 0; count_1 < INPUT_CASE; count_1++)
	{
		// Create and put them into the GLOBAL 2D vector
		ARRAY.emplace_back(readInputFile(INPUT_FILE_NAME[count_1]));
	}

	// Calculate execution time Divide-and-Conquer and Brute-force
	// and diplay
	for (int count = 0; count < INPUT_CASE; count++)
	{
		std::cout << "INPUT " + std::to_string(count + 1) 
			+ " (" + std::to_string(INPUT_CASE_SIZE[count]) + "): " << '\n';
		int maxsub_DC = 0,
			maxsub_BF = 0;
		int time_DC = calculateET_DC(ARRAY[count], maxsub_DC);
		std::cout << "Max Sub-array DC : " << maxsub_DC << '\n';
		std::cout << "Divide-Conquer ET: " << time_DC << '\n';
		
		// Comment/Uncomment 2 lines belows to wait/skip for 
		// Brute-force time execution for input 5 (1,000,000 inputs)
		//if (count == 4)
		//	break;
		int time_BF = calculateET_BF(ARRAY[count], maxsub_BF);
		std::cout << "Max Sub-array BF : " << maxsub_BF << '\n';
		std::cout << "Brute-force ET   : " << time_BF << '\n';
		std::cout << '\n';
	}

	std::cout << '\n';
	system("pause");
	return 0;
}

