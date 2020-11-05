/**
 * AUTHOR: David Niederweis
 * DATE: 11/03/2020
 * COURSE: CS317-03
 * DESCRIPTION: This file contains all the function headers for the MergeSort and QuickSort algorithms. Detailed information about each can be found above each function in the implementation file("Sorts.cpp").
 * INSTRUCTIONS: To build the project, ensure make is installed. Running 'make' in your terminal in the project directory will generate an executable, "CS317Sorting" on linux-based OS, and "CS317Sorting.exe" on windows. The linux executable can be run with './CS317Sorting' and the windows executable can be be run with 'CS317.exe'. The program will ask for a filename, and then perform the previously described process of sorting and outputting data.
 */
#include <string>      // required for storing data in arrays
#include "Utilities.h" // required for comparison in partition

using namespace std; // use standard namespace, since it is the only namespace used

// implements mergesort
void MergeSort(string values[], int left, int right);
// implements the merge algorithm for mergesort
void Merge(string values[], int left, int mid, int right);

// implements quicksort
void QuickSort(string[], int left, int right);
// implements the partition algorithm for quicksort
int Partition(string[], int left, int right);