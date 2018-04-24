// Project: Jump_Search.cbp
// File   : Jump_Search.cpp

#include <iostream>
#include <cmath>

using namespace std;

int LinearSearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // Iterate through the start index
    // to the end index and
    // return the searched value's index
    for(int i = startIndex; i < endIndex; ++i)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }

    // return -1 if no val is found
    return -1;
}

int JumpSearch(
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

    // Defining step used to jump the array
    int step = sqrt(arrSize);

    // Start comparing from index 0
    int blockIndex = 0;

    // Increase the blockIndex by the step
    // if blockIndex is lower than array size
    // and the value of element in blockIndex
    // is still lower than searched value
    while (blockIndex < arrSize && arr[blockIndex] < val)
    {
        blockIndex += step;
    }

    // After find the blockIndex,
    // perform Linear Search to the sub array
    // defined by the blockIndex
    // arr[blockIndex - step .... blockIndex or arrSize]
    return LinearSearch(
        arr,
        blockIndex - step,
        min(blockIndex, arrSize),
        val);
}

int main()
{
    cout << "Jump Search" << endl;

    // Initialize a new array
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 39;

    // Find the searched value using Jump Search
    int i = JumpSearch(arr, arrSize, searchedValue);

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
