// Project: Counting_Sort.cbp
// File   : Counting_Sort.cpp

#include <iostream>

using namespace std;

void CountingSort(int arr[], int arrSize)
{
    // Create key/counting array
    // with assumption that all element value
    // are from 0 to 9
    int counterSize = 10;
    int * counterArray = new int [counterSize];

    // Increase the respective counter by 1
    for(int i = 0; i < arrSize; ++i)
    {
        ++counterArray[arr[i]];
    }

    // Counter for iterating the arrCounter array
    int arrCounter = 0;

    for(int i = 0; i < counterSize; ++i)
    {
        while(counterArray[i] > 0)
        {
            // Restore element to list
            arr[arrCounter++] = i;

            // Decrease counter by 1
            --counterArray[i];
        }
    }
}

int main()
{
    cout << "Counting Sort" << endl;

    // Initialize a new array
    int arr[] = {9, 6, 5, 6, 1, 7, 2, 4, 3, 5, 7, 7, 9, 6};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with BubbleSort algorithm
    CountingSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
