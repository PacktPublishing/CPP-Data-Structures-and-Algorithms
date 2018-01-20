// Project: Selection_Sort.cbp
// File   : Selection_Sort.cpp

#include <iostream>

using namespace std;

void SelectionSort(int arr[], int arrSize)
{
    // variable to store the index of the minimum value
    // in each iteration
    int minIndex;

    // Iterate until the N-1 elements
    for(int i = 0; i < arrSize - 1; ++i)
    {
        // Set the first unsorted element
        // as the minimum value
        minIndex = i;

        // Iterate through the unsorted elements only
        for(int j = i + 1; j < arrSize; ++j)
        {
            // set the new minimum value
            // if the saved minimum value is higher
            // than the current index value
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the the first unsorted element
        // with the minimum value
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Selection Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with SelectionSort algorithm
    SelectionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
