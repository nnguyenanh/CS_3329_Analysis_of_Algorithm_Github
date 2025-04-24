// PROJECT 3
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 25, 2025

// Execution information:
// - Operating System: Windows 11.
// - IDE             : Visual Studio 2022 Community .
//	+ Download link  : https://visualstudio.microsoft.com/downloads/
// - Platform Toolset: Visual Studio 2022 (v143).
// - Language        : ISO C++ 14 Standard.

#include <iostream>
#include <iomanip>
#include "FileManagerATGX.h"
#include "LCS.h"
using namespace std;

const string FILE_NAME = "input";
const int	 MIN_SIZE = 50;
const int	 MAX_SIZE = 80;
void printResults(const string&, const string&, const string&);

int main()
{
	string inputfile_name = "input";
	string string_1 = "";
	string string_2 = "";

	// Generate input file
	generateInputFile(FILE_NAME, MIN_SIZE, MAX_SIZE);
	
	// Read input file to 2 strings
	readInputFile(FILE_NAME, string_1, string_2);

	// Get LCS of 2 strings
	string LCS = getLCS(string_1, string_2);

	// Print out results
	printResults(string_1, string_2, LCS);

	cout << '\n';
	system("pause");
	return 0;
}

void printResults(const string& str_1, const string& str_2, const string &LCS)
{
	cout << showpoint << fixed <<setprecision(2);
	cout << "STATISTIC" << "\n\n";
	cout << "STRING 1  : " << str_1 << '\n';
	cout << "STRING 2  : " << str_2 << '\n';
	cout << "LCS       : " << LCS << "\n\n";
	cout << "STRING 1 length: " << str_1.size() << '\n';
	cout << "STRING 2 length: " << str_2.size() << '\n';
	cout << "LCS length     : " << LCS.size() << '\n';
	cout << "Percentage     : " << '\n';
	cout << "  + LCS / STRING 1: " 
		<< static_cast<float>(LCS.size()) / static_cast<float>(str_1.size()) * 100.0 << '%' << '\n';
	cout << "  + LCS / STRING 2: " 
		<< static_cast<float>(LCS.size()) / static_cast<float>(str_2.size()) * 100.0 << '%' << '\n';
} 