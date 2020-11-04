#include "Sorts.h" // include header file for Sorts

using namespace std; // use standard namespace, since it is the only namespace used

/**
 * MergeSort
 * VALUES: pointer to the array of values to be sorted
 * FIRST: the left-most index of the (sub)array to sort
 * LAST: the right-most index of the (sub)array to sort
 * DESCRIPTION: performs mergesort recursively on the passed in data
 */
void MergeSort(string values[], int first, int last)
{
    // only sort if the length of the array is at least 2
    if (first < last)
    {
        int middle = (first + last) / 2;     // calculate the middle index of the (sub)array
        MergeSort(values, first, middle);    // call mergesort on the left subarray
        MergeSort(values, middle + 1, last); // call mergesort on the right subarray
        Merge(values, first, middle, last);  // merge the arrays to create one sorted array
    }
}
/**
 * Merge
 * VALUES: pointer to the array containing the values
 * START: the start index of the left subarray
 * MID: the end index of the left subarray
 * END: the end index of the righ subarray
 * DESCRIPTION: merges left and right subarray by taking the smaller of the two one at a time and placing into values
 */
void Merge(string values[], int start, int mid, int end)
{
    string temp[end + 1]; // create temp array of size end + 1 to avoid segmentation fault
    int index = start;    // temp array iterator
    int i = start;        // left subarray iterator
    int j = mid + 1;      // right subarray iterator

    /**
     * COPY SMALLER NUMBER OF LEFT AND RIGHT SUBARRAY INTO TEMP
     */
    // while i is in the left subarray and j in the right subarray, copy the smaller of the two into the temp array
    while ((i <= mid) && (j <= end))
    {
        // if value of left subarray(values[i]) < value of right subarray(values[j])
        if (comparison(values[i], values[j]))
        {
            temp[index] = values[i]; // copy value of left subarray into temp
            i++;                     // increment left subarray iterator
        }
        // value of left subarray(values[i]) >= value of right subarray(values[j])
        else
        {
            temp[index] = values[j]; // copy value of right subarray into temp
            j++;                     // increment left subarray iterator
        }
        index++; // increment temp array iterator
    }

    // while i is less than the last index of left subarray, copy the remaining values of the left subarray into temp
    while (i <= mid)
    {
        temp[index] = values[i]; // copy value of left subarray into temp
        index++;                 // increment temp iterator
        i++;                     // increment left subarray iterator
    }

    // while j is less than the last index of right subarray, copy the remaining values of the right subarray into temp
    while (j <= end)
    {
        temp[index] = values[j]; // copy the value of the right subarray into temp
        index++;                 // increment temp iterator
        j++;                     // increment right subarray iterator
    }

    // copy all the values in temp from the start of the left subarray index to the end of the right subarray into the values array
    for (int i = start; i <= end; i++)
    {
        values[i] = temp[i]; // copy the value in temp into values
    }
}

/**
 * QuickSort
 * VALUES: pointer to the array of values to be sorted
 * LEFT: the left-most index of the (sub)array
 * RIGHT: the right-most index of the (sub)array
 * DESCRIPTION: performs quicksort of the passed in data
 */
void QuickSort(string values[], int left, int right)
{
    // only sort if the length of the array is at least 2
    if (left < right)
    {
        int partitionIndex = Partition(values, left, right); // partition (sub)array to get partition index
        QuickSort(values, left, partitionIndex - 1);         // call quicksort on left subarray not including partition value
        QuickSort(values, partitionIndex + 1, right);        // call quicksort on the right subarray not including partition value
    }
}

/**
 * Partition
 * VALUES: pointer to the array containing the data
 * LEFT: left-most index of the array
 * RIGHT: right-most index of the array
 */
int Partition(string values[], int left, int right)
{
    string pivot = values[left]; // use value at the first index as pivot and store
    int i = left;                // left iterator
    int j = right;               // right iterator

    // while left iterator is less than right, swap values in the left subarray with pivot if they are >= pivot and swap values in the right subarray with pivot if they are <= pivot
    while (i < j)
    {
        // while i is in bounds, and values in the left subarray(values[i]) >= pivot increment left iterator
        while (!comparison(pivot, values[i]) && i < right)
        {
            i++; // increment left iterator
        }

        // while j is in bounds, and values in teh right subarray(values[j]) <= pivot increment right iterator
        while (comparison(pivot, values[j]) && j > left)
        {
            j--; // decrement right iterator
        }
        swap(values[i], values[j]); // swap values in the left and right subarray
    }
    swap(values[i], values[j]);    // undo last swap since it was when i == j
    swap(values[left], values[j]); // swap pivot into correct position
    return j;                      // return partition index
}
