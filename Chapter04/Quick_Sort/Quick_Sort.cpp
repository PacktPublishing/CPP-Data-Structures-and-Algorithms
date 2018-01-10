// Project: Quick_Sort.cbp
// File   : Quick_Sort.cpp

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

int partition(
    int arr[],
    int i,
    int j)
{
    // p is the pivot
    int p = arr[i];

    // S1 and S2 are initially empty
    int m = i;

    for (int k = i+1; k <= j; ++k)
    {
        // explore the unknown region
        if (arr[k] < p)
        {
            // case 2
            m++;
            Swap(&arr[k], &arr[m]);
        } // notice that we do nothing in case 1: a[k] >= p
    }

    // final step, swap pivot with a[m]
    Swap(&arr[i], &arr[m]);

    // return the index of pivot, to be used by Quick Sort
    return m;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIdx = partition(arr, low, high); // O(N)

        // arr[low..high] ~> arr[low..pivotIdx–1], pivot, a[pivotIdx+1..high]
        quickSort(arr, low, pivotIdx-1); // recursively sort left subarray

        // arr[pivotIdx] = pivot is already sorted after partition
        quickSort(arr, pivotIdx+1, high); // then sort right subarray
    }
}

int main()
{
    cout << "Quick Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 56, 78, 97, 30, 44, 61, 72, 90, 39};
//    int arr[] = {4, 0, 3, 5, 8, 7, 9, 6, 1, 10, 2, 11};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    DisplayElements(arr, arrSize);

    // Sort the array with QuickSort algorithm
    quickSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    DisplayElements(arr, arrSize);

    return 0;
}
