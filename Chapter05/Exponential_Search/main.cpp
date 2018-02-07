// Project: Exponential_Search.cbp
// File   : Exponential_Search.cpp

#include <iostream>

using namespace std;

int BinarySearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // Only perform searching process
    // if the end index is higher than
    // or equals to start index
    if(startIndex <= endIndex)
    {
        // Find middle index
        int middleIndex = startIndex + (endIndex - startIndex) / 2;

        // If the middle index's value is the searched value
        // then return the index
        if(arr[middleIndex] == val)
        {
            return middleIndex;
        }
        // If the middle index's value is greater than the searched value
        // then perform another Binary Search to the left sub array
        // arr[startIndex ... middleIndex - 1]
        else if(arr[middleIndex] > val)
        {
            return BinarySearch(arr, startIndex, middleIndex - 1, val);
        }
        // If the middle index's value is lower than the searched value
        // then perform another Binary Search to the right sub array
        // arr[middleIndex + 1 ... endIndex]
        else
        {
            return BinarySearch(arr, middleIndex + 1, endIndex, val);
        }
    }

    // Just in case no any value found
    return -1;
}

int ExponentialSearch(
    int arr[],
    int arrSize,
    int val)
{
    // It's impossible to search value
    // in array contains zero or less element
    if (arrSize <= 0)
    {
        return -1;
    }

    // Start comparing from index 1
    int blockIndex = 1;

    // Increase the blockIndex exponentially
    // if blockIndex is lower than array size
    // and the value of element in blockIndex
    // is still lower than searched value
    while (blockIndex < arrSize && arr[blockIndex] < val)
    {
        blockIndex *= 2;
    }

    // After find the blockIndex,
    // perfom Binary Search to the sub array
    // defined by the blockIndex
    // arr[blockIndex / 2 .... blockIndex or arrSize]
    return BinarySearch(
        arr,
        blockIndex / 2,
        min(blockIndex, arrSize),
        val);
}

int main()
{
    cout << "Exponential Search" << endl;

    // Initialize a new array
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 39;

    // Find the searched value using blockIndex Search
    int i = ExponentialSearch(arr, arrSize, searchedValue);

    // Notify user the result
    // if the return is not -1,
    // the searched value is found
    if(i != -1)
    {
        cout << searchedValue << " is found in index ";
        cout << i << endl;
    }
    else
    {
        cout << "Could not find value " << searchedValue;
        cout << endl;
    }

    return 0;
}
