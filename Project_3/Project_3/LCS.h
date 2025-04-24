#pragma once
// PROJECT 3
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 25, 2025

#include <iostream>
#include <vector>
#include <string>

//-----------------------------------------------------------------------------------------//
//                                   FUNCTION PROTOTYPE                                    //
//-----------------------------------------------------------------------------------------//
// Used to simplify tracking
enum tracking { EMPTY = 0, UPPER_LEFT, LEFT, UPPER };

// Used to fill the LCS and BT tables (Longest Common Subsequence and Back-tracking tables)
void fillTableLCSandBT(const std::string&, const std::string&,
    std::vector<std::vector<int>>&,
    std::vector<std::vector<int>>&);

// Used to get LCS using LCS and BT table
std::string getLCSfromTables(const int&, const int&, const std::string&,
    const std::vector<std::vector<int>>&,
    const std::vector<std::vector<int>>&);

// Used to call 2 above functions and return the LCS
std::string getLCS(const std::string&, const std::string&);

//-----------------------------------------------------------------------------------------//
//                                 FUNCTION IMPLEMENTATION                                 // 
//-----------------------------------------------------------------------------------------//
void fillTableLCSandBT(const std::string& str_1, const std::string& str_2,
    std::vector<std::vector<int>>& LCS,
    std::vector<std::vector<int>>& BT)
{
    // Get table size
    int max_row = LCS.size();  // Rows will be based on str_2 (x-axis)
    int max_col = LCS[0].size();  // Columns will be based on str_1 (y-axis)

    // Fill the LCS and BT tables
    for (int row = 1; row < max_row; row++)
    {
        for (int col = 1; col < max_col; col++)
        {
            if (str_1[col - 1] == str_2[row - 1])
            {
                // If matching, add 1 from UPPER-LEFT
                LCS[row][col] = LCS[row - 1][col - 1] + 1;
                BT[row][col] = UPPER_LEFT;
            }
            else
            {
                // If not matching, take value of the larger (LEFT or UPPER)
                if (LCS[row][col - 1] >= LCS[row - 1][col])
                {
                    // If LEFT >= UPPER
                    LCS[row][col] = LCS[row][col - 1];
                    BT[row][col] = LEFT;
                }
                else
                {
                    // If LEFT < UPPER
                    LCS[row][col] = LCS[row - 1][col];
                    BT[row][col] = UPPER;
                }
            }
        }
    }
}

std::string getLCSfromTables(const int& r, const int& c, const std::string& str_1,
    const std::vector<std::vector<int>>& LCS,
    const std::vector<std::vector<int>>& BT)
{
    std::string LCS_str = "";
    int row = r;
    int col = c;
    while (row > 0 && col > 0)
    {
        if (BT[row][col] == UPPER_LEFT)
        {
            // If BT[row][col] == UPPER_LEFT, move UPPER-LEFT in the LCS table
            // and take the character from str_1 (columns, y-axis)
            LCS_str += str_1[col - 1]; 
            row--;
            col--;
        }
        else if (BT[row][col] == LEFT)
        {
            // If BT[row][col] == LEFT, move LEFT in the LCS table (decrease column)
            col--;
        }
        else
        {
            // If BT[row][col] == UPPER, move UP in the LCS table (decrease row)
            row--;
        }
    }
    std::reverse(LCS_str.begin(), LCS_str.end());
    return LCS_str;
}

std::string getLCS(const std::string& str_1, const std::string& str_2)
{
    int row = str_2.size(); // str_2 is now the row (x-axis)
    int col = str_1.size(); // str_1 is now the column (y-axis)

    // Create and Initialize 2D vectors LCS and BT 
    std::vector<std::vector<int>> LCS(row + 1, std::vector<int>(col + 1, 0));
    std::vector<std::vector<int>> BT(row + 1, std::vector<int>(col + 1, EMPTY));

    // Fill vector tables
    fillTableLCSandBT(str_1, str_2, LCS, BT);

    // Get string using backtracking
    return getLCSfromTables(row, col, str_1, LCS, BT); // Passing str_1 for backtracking
}
