// Project: Bubble_Sort.cbp
// File   : Bubble_Sort.cpp

#include <iostream>

using namespace std;

void BubbleSort(int arr[], int arrSize)
{
    // Flag for swapping element
    bool isSwapped;

    // The value will be decreased
    // every time one element has been sorted
    int unsortedElements = arrSize;
    do
    {
        // If there's at least two element are swapped
        // it will be true
        isSwapped = false;

        // Iterate through the array's element
        for(int i = 0; i < unsortedElements - 1; ++i)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSwapped = true;
            }
        }

        // After iteration, the last element has been sorted
        // so it will be ignored in the next iteration
        --unsortedElements;
    }
    // Do comparison again if there's swapped element
    // otherwise, all array's elements have been sorted
    while(isSwapped);
}

int main()
{
    cout << "Bubble Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with BubbleSort algorithm
    BubbleSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
