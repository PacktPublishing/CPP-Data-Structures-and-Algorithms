// Project: Quick_Sort.cbp
// File   : Quick_Sort.cpp

#include <iostream>

using namespace std;

int Partition(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Set the first item as pivot
    int pivot = arr[startIndex];

    // Left sublist and right sublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (arr[i] < pivot)
        {
            // the current item is on the left sublist
            // prepare a seat by shifting middle index
            ++middleIndex;

            // the arr[middleIndex] is
            // the member of right sublist,
            // swap it to the current item which is
            // member of left list
            swap(arr[i], arr[middleIndex]);
        }
    }

    // By now, the arr[middleIndex] item is
    // member of left sublist.
    // We can swap it with the pivot
    // so the pivot will be in the correct position
    // which is between left sublist and right sublist
    swap(arr[startIndex], arr[middleIndex]);

    // return the index of pivot
    // to be used by next quick sort
    return middleIndex;
}

void QuickSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if (startIndex < endIndex)
    {
        // Retrieve pivot position from Partition() function
        // This pivotIndex is the index of element that is already
        // in correct position
        int pivotIndex = Partition(arr, startIndex, endIndex);

        // Sort left sublist
        // arr[startIndex ... pivotIndex - 1]
        QuickSort(arr, startIndex, pivotIndex - 1);

        // Sort right sublist
        // arr[pivotIndex + 1 ... endIndex]
        QuickSort(arr, pivotIndex + 1, endIndex);
    }
}

int main()
{
    cout << "Quick Sort" << endl;

    // Initialize a new array
    int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with QuickSort algorithm
    QuickSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
