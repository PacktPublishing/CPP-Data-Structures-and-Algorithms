// Project: Array_As_Pointer.cbp
// File   : Array_As_Pointer.cpp

#include <iostream>

using namespace std;

int main()
{
    // Initialize tee array length
    int arrLength = 5;

    // Initialize a pointer
    // to hold an array
    int * ptr = new int[arrLength] { 21, 47, 87, 35, 92 };

    // Display each element value
    // by incrementing the pointer (ptr++)
    cout << "Using pointer increment" << endl;
    cout << "Value\tAddress" << endl;
    // The use of while(*ptr) resulted in a list of more than 5 value when I run the code on VS and CodeBlock
    // In window base system, suggested changes
    int l = ptr[arrLength];
    while(*ptr != l)
    //while(*ptr)
    {
        cout << *ptr << "\t";
        cout << ptr << endl;
        ptr++;
    }
    cout << endl;

    // Since we have moved forward the pointer five times
    // we need to move it back
    ptr = ptr - 5;

    // Display each element value
    // by accessing pointer index (ptr[])
    cout << "Using pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for(int i = 0; i < arrLength; ++i)
    {
        cout << ptr[i] << "\t";
        cout << &ptr[i] << endl;
    }

    return 0;
}
