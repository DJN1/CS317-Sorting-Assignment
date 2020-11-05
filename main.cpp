/**
 * AUTHOR: David Niederweis
 * DATE: 11/03/2020
 * COURSE: CS317-03
 * DESCRIPTION: The purpose of this code is to implement MergeSort and Quicksort. It takes a filename from the user, reads in the data as strings into an array, and the sorts the data. Additionally, it also times the runtimes of the sorts. Finally, it create two files, "out_MergeSort.txt" and "out_QuickSort.txt" for the respective sorts that includes the runtime on the first line, followed by a blank line and the sorted data, one line at a time.
 * INSTRUCTIONS: To build the project, ensure make is installed. Running 'make' in your terminal in the project directory will generate an executable, "CS317Sorting" on linux-based OS, and "CS317Sorting.exe" on windows. The linux executable can be run with './CS317Sorting' and the windows executable can be be run with 'CS317.exe'. The program will ask for a filename, and then perform the previously described process of sorting and outputting data.
 */
#include <iostream>    // required for cout
#include <fstream>     // required to open data file
#include <string>      // required for arrays to store data
#include <chrono>      // required for timing sorts
#include "Sorts.h"     // required to run mergesort, quicksort
#include "Utilities.h" // required for setting up files and arrays, and printing to file

using namespace std; // use std namespace, since its the only one used, increases readability
/**
 * SETUP, RUN AND CLEANUP SORTING
 */
int main()
{
    /**
     * INITIALIZE AND SET UP DATA FOR SORTING
     */
    ifstream inFile;                                    // instantiate ifstream to hold data file
    inFile = openFile();                                // store data file in ifstream
    int length = getFileLength(inFile);                 // get length of file to create appropriate length arrays
    string *quickSorted = new string[length];           // dynamically create new array for quicksort
    string *mergeSorted = new string[length];           // dynamically create new array for mergesort
    initializeArrays(quickSorted, mergeSorted, inFile); // initialize both arrays to hold data from file

    /**
     * TIME AND SORT DATA
     */

    // QuickSort
    chrono::steady_clock::time_point quickSortStart = chrono::steady_clock::now(); // get starting timestamp for quicksort
    QuickSort(quickSorted, 0, length - 1);                                         // run quicksort
    chrono::steady_clock::time_point quickSortEnd = chrono::steady_clock::now();   // get ending timestamp for quicksort
    cout << "Finished Quicksort!" << endl;

    // MergeSort
    chrono::steady_clock::time_point mergeSortStart = chrono::steady_clock::now(); // get starting timestamp for mergesort
    MergeSort(mergeSorted, 0, length - 1);                                         // run mergesort
    chrono::steady_clock::time_point mergeSortEnd = chrono::steady_clock::now();   // get ending timestamp for mergesort
    cout << "Finished Mergesort!" << endl;

    // Runtimes
    double quickSortTime = chrono::duration_cast<chrono::milliseconds>(quickSortEnd - quickSortStart).count(); // calculate elapsed time for quicksort in milliseconds
    double mergeSortTime = chrono::duration_cast<chrono::milliseconds>(mergeSortEnd - mergeSortStart).count(); // calculate elapsed time for mergesort in milliseconds

    /**
     * PRINT DATA TO FILE, DELETE DATA AND RETURN
     */
    printToFile(mergeSorted, quickSorted, length, mergeSortTime, quickSortTime); // print sorted data, and run times to files: "out_MergeSort.txt" and "out_QuickSort.txt"
    inFile.close();                                                              // close file to avoid memory leaks
    delete[] quickSorted;                                                        // delete dynamically allocated quicksort array
    delete[] mergeSorted;                                                        // delete dynamically allocated mergesort array
    return 0;                                                                    // return from main
}
