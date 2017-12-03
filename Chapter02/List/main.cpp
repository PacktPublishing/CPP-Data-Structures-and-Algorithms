// Project: List.cbp
// File   : main.cpp
#include "List.h"

using namespace std;

int main()
{
    // Initialize a List
    List list = List();

    // Add several items to the List
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);

    // Print current List
    cout << "List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << endl << endl;

    // Insert several items in the middle of the List
    list.Insert(2, 25);
    list.Insert(2, 71);

    // Print the List again
    cout << "New List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << endl << endl;

    // Search value 71
    cout << "Search element 71" << endl;
    int result = list.Search(71);
    if(result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;
    cout << endl << endl;

    // Remove index 2
    cout << "Remove element at index 2" << endl;
    list.Remove(2);
    cout << endl;

    // Print the List again
    cout << "New List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << endl << endl;

    // Search value 71 again
    cout << "Search element 71 again" << endl;
    result = list.Search(71);
    if(result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;
    cout << endl;

    return 0;
}
