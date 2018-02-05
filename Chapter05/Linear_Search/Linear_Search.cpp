// Project: Linear_Search.cbp
// File   : Linear_Search.cpp
#include <iostream>

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

int main()
{
    cout << "Linear Search" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30, 25, 18};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 30;

    // Find the searched value using Linear Search
    int i = LinearSearch(arr, 0, arrSize - 1, searchedValue);

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
