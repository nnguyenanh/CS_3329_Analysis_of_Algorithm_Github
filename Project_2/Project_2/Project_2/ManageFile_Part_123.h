#pragma once
// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025

#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <sstream>

void generateRandomInputFile(const std::string, int, int, int);
void generateOutputFile(const std::string, const std::vector<int>&);
void readInputFileToVector(const std::string&, std::vector<int>&);

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
		file << dist(prng) << '\t';
	}
	file.close();
}


void generateOutputFile(const std::string file_name, const std::vector<int>& array)
{
	std::ofstream file(file_name + ".txt", std::ios::out);
	if (!file.is_open()) {
		std::cerr << "Could not open the file for writing!" << std::endl;
		return;
	}
	for (int count = 0; count < array.size(); count++)
	{
		file << array[count] << '\t';
	}
	file.close();
}

void readInputFileToVector(const std::string& filename, std::vector<int>& array)
{
	std::ifstream file(filename);  
	// Check if the file is open
	if (!file.is_open())
	{  
		std::cerr << "Could not open the file!" << std::endl;
		return;
	}

	std::string line;
	// Read the first line from the file
	while (std::getline(file, line)) 
	{  
		std::stringstream ss(line);  // Use a stringstream to split the line
		std::string value;

		// Read each number separated by tab '\t'
		while (std::getline(ss, value, '\t')) 
		{
			array.push_back(std::stoi(value));  // Convert string to int and add to the vector
		}
	}
	file.close();  // Close the file
}