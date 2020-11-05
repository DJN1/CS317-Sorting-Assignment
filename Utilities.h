/**
 * AUTHOR: David Niederweis
 * DATE: 11/03/2020
 * COURSE: CS317-03
 * DESCRIPTION: This file contains all the function headers for the "helper"/Utility functions needed for the assignment. Detailed descriptions can be found above each function in the implementation file("Utilities.cpp")
 * INSTRUCTIONS: To build the project, ensure make is installed. Running 'make' in your terminal in the project directory will generate an executable, "CS317Sorting" on linux-based OS, and "CS317Sorting.exe" on windows. The linux executable can be run with './CS317Sorting' and the windows executable can be be run with 'CS317.exe'. The program will ask for a filename, and then perform the previously described process of sorting and outputting data.
 */
#include <fstream>  // required for loading files, and outputting data to files
#include <iostream> // requried for printing in file prompt, and getting user input
#include <string>   // required to store the data

using namespace std; // use standard namespace, since its the only used

// used for comparisons in partition in quicksort
bool comparison(string string1, string string2);

// reads file to count number of lines
int getFileLength(ifstream &inFile);

// initialize two arrays with unsorted data for quicksort and mergesort
void initializeArrays(string quickSortArray[], string mergeSortArray[], ifstream &inFile);

// load data into array from inFile
void loadArray(ifstream &inFile, string values[]);

// prompt user for file name and open file
ifstream openFile();

// print sorted data and rumtime for each sorting algorithm to their respective files
void printToFile(string mergeSortedValues[], string quickSortedValues[], int length, double mergeSortTime, double quickSortTime);
