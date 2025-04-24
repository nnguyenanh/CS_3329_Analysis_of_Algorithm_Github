#pragma once
// PROJECT 3
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 25, 2025

#include <iostream>
#include <fstream>
#include <string>
#include <random>

void readInputFile(const std::string&, std::string&, std::string&);
void generateInputFile(const std::string&, const int&, const int&);

char RANDOM(const int, const int);
const int START = 0;
const int END = 3;
const std::vector<char> RANDOM_CHAR_SET = { 'A', 'T', 'G', 'X' };

void readInputFile(const std::string& file_name, std::string& str_1, std::string& str_2)
{
	std::ifstream file(file_name + ".txt", std::ios::in);
	if (file.is_open())
	{
		std::getline(file, str_1);
		std::getline(file, str_2);
		file.close();
	}
	else
	{
		std::cout << "Cannot open input file." << '\n';
		return;
	}
}

void generateInputFile(const std::string& file_name, 
	const int &MIN_SIZE, const int &MAX_SIZE)
{
	std::string str_1 = "",
		str_2 = "";
	// Generate string size randomly
	int str_size = RANDOM(MIN_SIZE, MAX_SIZE);
	for (int count = 0; count < str_size; count++)
	{
		str_1 += RANDOM_CHAR_SET[RANDOM(START, END)];
	}
	str_size = RANDOM(MIN_SIZE, MAX_SIZE);
	for (int count = 0; count < str_size; count++)
	{
		str_2 += RANDOM_CHAR_SET[RANDOM(START, END)];
	}

	std::ofstream file(file_name + ".txt", std::ios::out);
	if (file.is_open())
	{
		file << str_1 << '\n';
		file << str_2 << '\n';
	}
	file.close();
}

char RANDOM(const int start, const int end)
{
	static std::random_device seed;
	static std::mt19937 prng(seed());
	std::uniform_int_distribution<int> dist(start, end);
	return dist(prng);
}