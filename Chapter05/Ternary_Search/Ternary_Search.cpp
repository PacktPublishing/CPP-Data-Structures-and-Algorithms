// Project: Ternary_Search.cbp
// File   : Ternary_Search.cpp

#include <iostream>

using namespace std;

int TernarySearch(
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
        // Find index of area of the first third
        int middleLeftIndex = startIndex + (endIndex - startIndex) / 3;

        // Find index of area of the last third
        int middleRightIndex =
            middleLeftIndex + (endIndex - startIndex) / 3;

        // If val is at middleLeftIndex
        // then return middleLeftIndex
        if(arr[middleLeftIndex] == val)
        {
            return middleLeftIndex;
        }
        // If val is at middleRightIndex
        // then return middleRightIndex
        else if(arr[middleRightIndex] == val)
        {
            return middleRightIndex;
        }
        // If val is at the are of the first third
        // then perform another Ternary Search to this subarray
        // arr[startIndex ... middleLeftIndex - 1]
        else if(arr[middleLeftIndex] > val)
        {
            return TernarySearch(
                arr,
                startIndex,
                middleLeftIndex - 1,
                val);
        }
        // If val is at the area of the last third
        // then perform another Ternary Search to this subarray
        // arr[middleRightIndex + 1 ... endIndex]
        else if(arr[middleRightIndex] < val)
        {
            return TernarySearch(
                arr,
                middleRightIndex + 1,
                endIndex,
                val);
        }
        // The val is at the area
        // between middleLeftIndex and middleRightIndex
        // arr[middleLeftIndex + 1 ... middleRightIndex - 1]
        else
        {
            return TernarySearch(
                arr,
                middleLeftIndex + 1,
                middleRightIndex - 1,
                val);
        }
    }

    // Just in case no any value found
    return -1;
}

int main()
{
    cout << "Ternary Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Ternary Search
    int i = TernarySearch(arr, 0, arrSize - 1, searchedValue);

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
