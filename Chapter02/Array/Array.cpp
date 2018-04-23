// Project: Array.cbp
// File   : Array.cpp

#include <iostream>

using namespace std;

int main()
{
    // Initialize an array
    int arr[] = { 21, 47, 87, 35, 92 };

    // Access each element
    cout << "Array elements: ";
    for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Manipulate several elements
    arr[2] = 30;
    arr[3] = 64;

    // Access each element again
    cout << "Array elements: ";
    for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
        cout << arr[i] << " ";
    cout << endl;
}
