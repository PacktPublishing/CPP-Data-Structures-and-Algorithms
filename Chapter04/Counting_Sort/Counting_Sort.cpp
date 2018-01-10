// Project: Counting_Sort.cbp
// File   : Counting_Sort.cpp

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
                Swap(&arr[i], &arr[i+1]);
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

void CountingSort(int arr[], int arrSize)
{
    // Create key/counting array
    // with assumption that all element value
    // are from 0 to 99
    int counterSize = 100;
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
    int arr[] = {3, 43, 5, 1, 21, 56, 4, 1, 3, 78, 97, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    DisplayElements(arr, arrSize);

    // Sort the array with BubbleSort algorithm
    CountingSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    DisplayElements(arr, arrSize);

    return 0;
}
