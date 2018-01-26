// Project: Merge_Sort.cbp
// File   : Merge_Sort.cpp

#include <iostream>

using namespace std;

void Merge(
    int arr[],
    int startIndex,
    int middleIndex,
    int endIndex)
{
    // Numbers of elements that will be sorted
    // from startIndex until endIndex
    int totalElements = endIndex - startIndex + 1;

    // Temporary array to store merged array
    int * tempArray = new int[totalElements];

    // Index of left subarray
    // arr[startIndex ... middleIndex]
    int leftIndex = startIndex;

    // Index of right subarray
    // arr[middleIndex + 1 ... endIndex]
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    // Merge the two subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if(arr[leftIndex] <= arr[rightIndex])
        {
            // Store the left subarray's element
            // if it's lower than the right one
            tempArray[mergedIndex] = arr[leftIndex];

            // Go to next left subarray index
            ++leftIndex;
        }
        else
        {
            // Store the right subarray's element
            // if it's lower than the left one
            tempArray[mergedIndex] = arr[rightIndex];

            // Go to next right subarray index
            ++rightIndex;
        }

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in left subarray
    // that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray[mergedIndex] = arr[leftIndex];

        // Go to next left subarray index
        ++leftIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in right subarray
    // that is not stored to merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray[mergedIndex] = arr[rightIndex];

        // Go to next right subarray index
        ++rightIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // Now, the merged array has been sorted
    // Copy the elements to the original array
    for (int i = 0; i < totalElements; ++i)
    {
        arr[startIndex + i] = tempArray[i];
    }

    // Remove the temporary array tempArray
    delete[] tempArray;

    return;
}

void MergeSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if(startIndex < endIndex)
    {
        // Find middle index
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort left subarray
        // arr[startIndex ... middleIndex]
        MergeSort(arr, startIndex, middleIndex);

        // Sort right subarray
        // arr[middleIndex + 1 ... endIndex]
        MergeSort(arr, middleIndex + 1, endIndex);

        // Merge the left and the right subarray
        Merge(arr, startIndex, middleIndex, endIndex);
    }

    return;
}

int main()
{
    cout << "Merge Sort" << endl;

    // Initialize a new array
    int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with MergeSort algorithm
    MergeSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
