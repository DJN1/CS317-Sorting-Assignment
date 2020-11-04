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