// Project: Vector.cbp
// File   : main.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int>& vect)
{
    for (auto v: vect)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    // Initialize a vector
    //vector<int> vectorList = { 35, 41, 94 };

    // or use the following code:
    vector<int> vectorList;
    vectorList.push_back(35);
    vectorList.push_back(41);
    vectorList.push_back(94);

    // Print the current vectorList
    cout << "vectorList elements:" << endl;
    PrintVector(vectorList);
    cout << endl;

    // Get item's value based on the index
    int i = vectorList.at(1);
    int j = vectorList[0];

    // Initialize an iterator
    vector<int>::iterator itr;

    // Insert an item to the first position
    itr = vectorList.begin();
    vectorList.insert(itr, 58);

    // Print the vectorList
    cout << "vectorList after inserting an item:" << endl;
    PrintVector(vectorList);
    cout << endl;

    // Insert an item to the last position
    itr = vectorList.end();
    vectorList.insert(itr, 37);

    // Print the vectorList
    cout << "vectorList after inserting an item:" << endl;
    PrintVector(vectorList);
    cout << endl;

    // Insert an item to the 4th position
    itr = vectorList.begin();
    vectorList.insert(itr + 3, 67);

    // Print the vectorList
    cout << "vectorList after inserting an item:" << endl;
    PrintVector(vectorList);
    cout << endl;

    // Search 41 element
    // It should be found
    itr = find (vectorList.begin(), vectorList.end(), 41);
    if (itr != vectorList.end())
        cout << "Element found in vectorList: " << *itr;
    else
        cout << "Element not found in vectorList";
    cout << endl << endl;

    // Remove the 2nd element
    itr = vectorList.begin();
    vectorList.erase (itr + 1);

    // Print the vectorList
    cout << "vectorList after removing an item:" << endl;
    PrintVector(vectorList);
    cout << endl;

    return 0;
}
