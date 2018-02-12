// Project: Binary_Search.cbp
// File   : Binary_Search.cpp

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
        // then perform another Binary Search to the left sub array
        // arr[middleIndex + 1 ... endIndex]
        else
        {
            return BinarySearch(arr, middleIndex + 1, endIndex, val);
        }
    }

    // Just in case no any value found
    return -1;
}

int main()
{
    cout << "Binary Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Binary Search
    int i = BinarySearch(arr, 0, arrSize - 1, searchedValue);

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
