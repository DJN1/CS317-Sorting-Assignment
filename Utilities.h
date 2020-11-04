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
