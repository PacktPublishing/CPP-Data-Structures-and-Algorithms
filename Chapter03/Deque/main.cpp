// Project: Deque.cbp
// File   : main.cpp
#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    // NULL
    Deque<int> deque = Deque<int>();

    // Enqueue several numbers to the deque
    // 26
    deque.EnqueueFront(26);
    // 26 - 78
    deque.EnqueueBack(78);
    // 26 - 78 - 44
    deque.EnqueueBack(44);
    // 91 - 26 - 78 - 44
    deque.EnqueueFront(91);
    // 35 - 91 - 26 - 78 - 44
    deque.EnqueueFront(35);
    // 35 - 91 - 26 - 78 - 44 - 12
    deque.EnqueueBack(12);

    // list the element of queue
    while(!deque.IsEmpty())
    {
        // Get the front element
        cout << deque.Back() << " - ";

        // Remove the front element
        deque.DequeueBack();
    }
    cout << "END" << endl;

    return 0;
}
