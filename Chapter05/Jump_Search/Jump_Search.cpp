// Project: Jump_Search.cbp
// File   : Jump_Search.cpp

#include <iostream>
#include <cmath>

using namespace std;

//int JumpSearch(int arr[], int arrSize, int val)
//{
//    // Finding block size to be jumped
//    int step = sqrt(arrSize);
//
//    // Finding the block where element is
//    // present (if it is present)
//    int prev = 0;
//    while (arr[min(step, arrSize)-1] < val)
//    {
//        prev = step;
//        step += sqrt(arrSize);
//        if (prev >= arrSize)
//            return -1;
//    }
//
//    // Doing a linear search for x in block
//    // beginning with prev.
//    while (arr[prev] < val)
//    {
//        prev++;
//
//        // If we reached next block or end of
//        // array, element is not present.
//        if (prev == min(step, arrSize))
//            return -1;
//    }
//    // If element is found
//    if (arr[prev] == val)
//        return prev;
//
//    return -1;
//}

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

int JumpSearch(int arr[], int arrSize, int val)
{
    // Defining step used to jump the array
    int step = sqrt(arrSize);

    int i;
    for(i = 0; i < arrSize; i += step)
    {
        if(arr[i] > val)
        {
            if(i == 0)
            {
                return -1;
            }
            else
            {
//                i -= step;
                break;
            }
        }
    }


                i -= step;

//    if(i >= arrSize)
//    {
//        return -1;
//    }

    return LinearSearch(arr, i, i + step, val);
}

int main()
{
    cout << "Jump Search" << endl;

    // Initialize a new array
    int arr[] = {11, 17, 21, 22, 25, 26, 30, 38, 43, 49};
    int arrSize = sizeof(arr)/sizeof(*arr);

    int i = JumpSearch(arr, arrSize, 100);
    cout << i << endl;

    return 0;
}
