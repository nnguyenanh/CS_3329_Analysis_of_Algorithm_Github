#pragma once
// PROJECT 2
// Name : Nguyen Anh Nguyen
// ID   : 1624733
// Class: CS 3329 - Analysis of Algorithm
// Due  : April 4, 2025
// REFERENCE: https://www.youtube.com/watch?v=Nrr-lwS_0LY&t=931s

#include <vector>
#include <iostream>

void MERGESORT(std::vector<int>& array, int left, int right);       // MERGE-SORT
void MERGE(std::vector<int>& array, int left, int mid, int right);  // MERGE

void MERGESORT(std::vector<int>& array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;  // Find the middle point

        // Divide into 2 halves
        MERGESORT(array, left, mid);
        MERGESORT(array, mid + 1, right);

        // Merge subproblems
        MERGE(array, left, mid, right);
    }
}

void MERGE(std::vector<int>& array, int left, int mid, int right)
{
    // Find the size of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays for the two subarrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0;      // Initial index of first subarray
    int j = 0;      // Initial index of second subarray
    int k = left;   // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
