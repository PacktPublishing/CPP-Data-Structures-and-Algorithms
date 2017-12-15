// Project: Queue.cbp
// File   : main.cpp
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    // NULL
    Queue<int> queueInt = Queue<int>();

    // Enqueue several numbers to the queue
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);

    // list the element of queue
    while(!queueInt.IsEmpty())
    {
        // Get the front element
        cout << queueInt.Front() << " - ";

        // Remove the front element
        queueInt.Dequeue();
    }
    cout << "END" << endl;

    return 0;
}
