#include "Utilities.h" // include header file for Utilities

using namespace std; // use standard namespace, since it is the only namespace being used

/**
 * comparison
 * FIRST: copy of the first string to compare
 * SECOND: copy of the second string to compare
 * DESCRIPTION: for each string, change every character to lowercase, and then compare first and second string. Return true if the first is lexicographically before the second, false otherwise
 */
bool comparison(string first, string second)
{
    // for every character in the first string, convert to lower case
    for (char &c : first)
    {
        c = tolower(c); // convert character to lowercase
    }

    // for every character in the second string, convert to lower case
    for (char &c : second)
    {
        c = tolower(c); // convert character to lowercase
    }

    return (first < second); // return true if the first string comes before the second string
}

/**
 * getFileLength
 * INFILE: reference to data file
 * DESCRIPTION: iterate through the file, and increment counter for every line. Return number of lines
 */
int getFileLength(ifstream &inFile)
{
    string lineHolder = ""; // create dummy variable to load lines into
    int length = 0;         // initialize length counter to 0

    // while not having reached the end of the file, load next line, and increment length counter
    while (!inFile.eof())
    {
        getline(inFile, lineHolder); // load next line
        length++;                    // increment length counter
    }
    return length; // return the number of lines in the file
}

/**
 * initializeArrays
 * QUICKSORTARRAY: pointer to the array for quicksort
 * MERGESORTARRAY: pointer to the array for mergesort
 * INFILE: reference to data file
 * DESCRIPTION: load each array with data from file
 */
void initializeArrays(string quickSortArray[], string mergeSortArray[], ifstream &inFile)
{
    loadArray(inFile, quickSortArray);
    loadArray(inFile, mergeSortArray);
}

/**
 * loadArray
 * INFILE: reference to the data file
 * VALUES: pointer to the array to store the data
 * DESCRIPTION: load data from file line by line into array, each line having their own index
 */
void loadArray(ifstream &inFile, string values[])
{
    inFile.seekg(0);        // seek to the beginning of the file
    string lineHolder = ""; // initialize variable to hold each line from file
    int iterator = 0;       // initialize index iterator for the array

    // while not at the end of the file, load data line by line into array at iterator
    while (!inFile.eof())
    {
        getline(inFile, lineHolder);   // get next line from file
        values[iterator] = lineHolder; // store line in array at iterator
        iterator++;                    // increment index iterator
    }
}

/**
 * openFile
 * DESCRIPTION: prompt user for file name from which to load the data, why the file is invalid, re-prompt the user. Return valid opened file
 */
ifstream openFile()
{
    ifstream inFile;                                                   // create empty file stream
    string fileName = "";                                              // initialize filename holder
    cout << "Please enter the name of the file containing the data: "; // prompt user to enter filename
    cin >> fileName;                                                   // get user filename
    inFile.open(fileName);                                             // open file

    // while the file is invalid, show error to user and re-prompt to enter new filename
    while (!inFile)
    {
        cout << "ERROR: Could not open \"" << fileName << "\"" << endl
             << endl;                                                                 // inform user what file could not be opened
        cout << "Please try again. Enter the name of the file containing the data: "; // prompt the user to enter new filename
        cin >> fileName;                                                              // get user filename
        inFile.open(fileName);                                                        // open file
    }
    return inFile; // return valid opened file
}

/**
 * printToFile
 * MERGESORTEDVALUES: pointer to array containing data that was sorted using mergesort
 * QUICKSORTEDVALUES: pointer to array containing data that was sorted using quicksort
 * LENGTH: length of arrays
 * MERGESORTTIME: runtime in milliseconds of mergesort
 * QUICKSORTTIME: runtime in milliseconds of quicksort
 * DESCRIPTION: write runtimes, and sorted values into out files for each sort
 */
void printToFile(string mergeSortedValues[], string quickSortedValues[], int length, double mergeSortTime, double quickSortTime)
{
    ofstream msFile;                  // create output file for mergesort
    ofstream qsFile;                  // create output file for quicksort
    msFile.open("out_MergeSort.txt"); // open file for mergesort
    qsFile.open("out_QuickSort.txt"); // open file for quicksort
    msFile << "MergeSort took " << mergeSortTime << " milliseconds for " << length << " items." << endl
           << endl; // write mergesort runtime into mergesort file
    qsFile << "QuickSort took " << quickSortTime << " milliseconds for " << length << " items." << endl
           << endl; // write quicksort runtime into quicksort file

    // write every line of each array into their respective file followed by newline
    for (int i = 0; i < length; i++)
    {
        msFile << mergeSortedValues[i]; // write line at i from mergesort data into mergesort file
        qsFile << quickSortedValues[i]; // write line at i from quicksort data into quicksort file

        // add newline for line except last
        if (i != length - 1)
        {
            msFile << "\n"; // write newline at end of line for mergesort
            qsFile << "\n"; // write newline at end of line for quicksort
        }
    }
    msFile.close(); // close mergesort file
    qsFile.close(); // close quicksort file
}
