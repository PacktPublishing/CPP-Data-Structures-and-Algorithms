#include <iostream>

using namespace std;

int Search(int arr[], int arrSize, int x)
{
    // Iterate through arr elements
    for (int i = 0; i < arrSize; ++i)
    {
        // If x is found
        // returns index of x
        if (arr[i] == x)
            return i;
    }

    // If x is not found
    // returns -1
    return -1;
}

int main()
{
    int arr[] = {42, 55, 39, 71, 20, 18, 6, 84};
    int x = 18;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << Search(arr, n, x);

    return 0;
}
