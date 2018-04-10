// Project: Binary_Heap.cbp
// File   : Binary_Heap.cpp

#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main()
{
    cout << "Priority Queue" << endl;

    // Instantiate priority queue
    BinaryHeap * priorityQueue =
        new BinaryHeap();

    // Check if the queue is empty
    // it should be TRUE
    cout << "Is queue empty? ";
    bool b = priorityQueue->IsEmpty();
    if(b)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;

    // Insert a new element
    priorityQueue->Insert(14);
    cout << "Insert 14 to queue" << endl;

    // Check again if the queue is empty
    // it should be FALSE now
    cout << "Is queue empty? ";
    b = priorityQueue->IsEmpty();
    if(b)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;

    // Insert others elements
    priorityQueue->Insert(53);
    priorityQueue->Insert(8);
    priorityQueue->Insert(32);
    cout << "Insert 53, 8 and 32 to queue";
    cout << endl;

    // Peek the maximum element
    // It should be 53
    cout << "GetMax() = ";
    cout << priorityQueue->GetMax();
    cout << endl;

    // Extract maximum element
    cout << "ExtractMax() = ";
    cout << priorityQueue->ExtractMax();
    cout << endl;

    // Peek the maximum element
    // It should be 32 now
    cout << "GetMax() = ";
    cout << priorityQueue->GetMax();
    cout << endl;

    return 0;
}
