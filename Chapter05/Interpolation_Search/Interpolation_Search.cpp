// Project: Interpolation_Search.cbp
// File   : Interpolation_Search.cpp

#include <iostream>

using namespace std;

int InterpolationSearch(
    int arr[],
    int lowIndex,
    int highIndex,
    int val)
{
    if(lowIndex <= highIndex)
    {
        // Find middle index
        int middleIndex =
            lowIndex + (
                (val - arr[lowIndex]) * (highIndex - lowIndex) /
                (arr[highIndex] - arr[lowIndex]));

        // If the middle index's value is the searched value
        // then return the index
        if(arr[middleIndex] == val)
        {
            return middleIndex;
        }
        // If the middle index's value is greater than the searched value
        // then perform another Interpolation Search to the left sub array
        // arr[lowIndex ... middleIndex - 1]
        else if(arr[middleIndex] > val)
        {
            return InterpolationSearch(arr, lowIndex, middleIndex - 1, val);
        }
        // If the middle index's value is lower than the searched value
        // then perform another Interpolation Search to the right sub array
        // arr[middleIndex + 1 ... highIndex]
        else
        {
            return InterpolationSearch(arr, middleIndex + 1, highIndex, val);
        }
    }

    // Just in case no any value found
    return -1;
}

int main()
{
    cout << "Interpolation Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Interpolation Search
    int i = InterpolationSearch(arr, 0, arrSize - 1, searchedValue);

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
