#pragma once
// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <vector>
#include <fstream>

std::vector<int> readInputFile(const std::string file_name)
{
	std::ifstream file(file_name, std::ios::in);
	std::vector<int> array;
	int clone = 0;

	// Check file error
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file " << file_name << std::endl;
		return array;
	}

	// Read input file to vector
	while (file >> clone)
	{
		array.push_back(clone);
	}

	file.close();
	return array;
}