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
    if(endIndex >= startIndex)
    {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;

        if(arr[middleIndex] == val)
        {
            return middleIndex;
        }
        else if(arr[middleIndex] > val)
        {
            return BinarySearch(arr, startIndex, middleIndex - 1, val);
        }
        else
        {
            return BinarySearch(arr, middleIndex + 1, endIndex, val);
        }
    }

    return -1;
}

int main()
{
    cout << "Binary Search" << endl;

    // Initialize a new array
    int arr[] = {25, 43, 21, 49, 26, 38, 17, 30, 22, 11};
    int arrSize = sizeof(arr)/sizeof(*arr);

    int i = BinarySearch(arr, 0, arrSize - 1, 30);
    cout << i << endl;

    return 0;
}
