#pragma once
// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <chrono> 
// For getting time from "https://stackoverflow.com/questions/36042637/how-to-calculate-execution-time-in-milliseconds"
#include <vector>
#include "MaxSubarrayBF.h"
#include "MaxSubarrayDC.h"

int calculateET_BF(const std::vector<int>& array, int &max_subarray)
{
	// Get start time
	auto time_start = std::chrono::high_resolution_clock::now();
	// Run function
	max_subarray = sumMaxSubarray_BF(array);
	// Get end time
	auto time_end = std::chrono::high_resolution_clock::now();

	// Return execution time (end - start) in milliseconds
	return std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();
}


int calculateET_DC(const std::vector<int>& array, int& max_subarray)
{
	// Get start time
	auto time_start = std::chrono::high_resolution_clock::now();
	// Run function
	max_subarray = sumMaxSubarray_DC(array, 0, array.size() - 1);
	// Get end time
	auto time_end = std::chrono::high_resolution_clock::now();

	// Return execution time (end - start) in milliseconds
	return std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();
}