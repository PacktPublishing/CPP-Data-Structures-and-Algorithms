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

    // LeftSublist and RightSublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n-1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        // explore the unknown region
        if (arr[i] < pivot)
        {
            ++middleIndex;
            swap(arr[i], arr[middleIndex]);
        }
    }

    // Final step, swap pivot with a[m]
    swap(arr[startIndex], arr[middleIndex]);

    // return the index of pivot, to be used by Quick Sort
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
        int pivotIndex = Partition(arr, startIndex, endIndex);

        // arr[startIndex..endIndex] ~> arr[startIndex..pivotIndex–1], pivot, a[pivotIndex+1..endIndex]
        QuickSort(arr, startIndex, pivotIndex-1); // recursively sort left subarray

        // arr[pivotIndex] = pivot is already sorted after partition
        QuickSort(arr, pivotIndex+1, endIndex); // then sort right subarray
    }
}

int main()
{
    cout << "Quick Sort" << endl;

    // Initialize a new array
    int arr[] = {27, 38, 12, 39, 27, 16};
//    int arr[] = {43, 21, 26, 38, 17, 30};
//    int arr[] = {43, 21, 56, 78, 97, 30, 44, 61, 72, 90, 39};
//    int arr[] = {4, 0, 3, 5, 8, 7, 9, 6, 1, 10, 2, 11};
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
