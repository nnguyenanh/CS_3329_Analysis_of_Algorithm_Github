#pragma once
// PROJECT 1
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : 21/02/2025

#include <iostream>
#include <random>
#include <fstream>

void generateRandomInputFile(const std::string file_name,
	int file_size, int min, int max)
{
	// Check if min > max
	if (min > max)
	{
		std::cerr << "MIN is larger than MAX." << '\n';
		return;
	}

	// From <random> library, to generate random input more efficient
	std::random_device seed;
	std::mt19937 prng(seed());
	std::uniform_int_distribution<int> dist(min, max);

	// Open file + check + generate input files
	std::ofstream file(file_name, std::ios::out);
	if (!file)
	{
		std::cerr << "Error generate files." << '\n';
		return;
	}
	for (int count = 0; count < file_size; count++)
	{
		file << dist(prng) << '\n';
	}
	file.close();
}