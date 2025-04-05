#pragma once
// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025
#include <vector>
const int MAX[4] = { 100, 1000, 10000, 100000 };

void generateInputPart4(std::vector<std::vector<int>>& input_ascending, std::vector<std::vector<int>>& input_descending)
{
	for (int case_max = 0; case_max < 4; case_max++)
	{
		int max = MAX[case_max];
		for (int count = 0; count <= max; count++)
		{
			input_ascending[case_max].emplace_back(count);
		}
	}

	for (int case_max = 0; case_max < 4; case_max++)
	{
		int max = MAX[case_max];
		for (int count = max; count >= 0; count--)
		{
			input_descending[case_max].emplace_back(count);
		}
	}
}
