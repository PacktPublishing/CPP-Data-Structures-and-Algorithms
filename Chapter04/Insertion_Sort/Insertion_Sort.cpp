// Project: Insertion_Sort.cbp
// File   : Insertion_Sort.cpp

#include <iostream>

using namespace std;

void Swap(int *firstPtr, int *secondPtr)
{
    // Save the first value
    // to temporary variable
    int temp = *firstPtr;

    // Store the second value
    // to first storage
    *firstPtr = *secondPtr;

    // Store the first value
    // that has been saved in the temp variable
    // to second storage
    *secondPtr = temp;
}

void DisplayElements(
    int arr[],
    int arrSize)
{
    // Iterate all array's element
    // then print it to screen
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(int arr[], int arrSize)
{
    // Iterate to all array's element
    for(int i = 0; i < arrSize; ++i)
    {
        // Set the current element
        // as reference value
        int refValue = arr[i];

        // variable to shift the element
        // to right position
        int j;

        // Iterate through the sorted element
        // to insert the reference value
        // in right position
        for(j = i - 1; j >= 0; --j)
        {
            // if the value of the current index
            // is greater than the reference value then
            // move the current value to right side
            // otherwise, put the reference value
            // in the current index
            if(arr[j] > refValue)
                arr[j+1] = arr[j];
            else
                break;
        }

        // here's the line to put the reference value
        // in the current index (the right position)
        arr[j + 1] = refValue;
    }
}

int main()
{
    cout << "Insertion Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 56, 78, 97, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    DisplayElements(arr, arrSize);

    // Sort the array with InsertionSort algorithm
    InsertionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    DisplayElements(arr, arrSize);

    return 0;
}
