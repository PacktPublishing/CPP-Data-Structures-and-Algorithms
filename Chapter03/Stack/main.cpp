// Project: Stack.cbp
// File   : main.cpp
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    // NULL
    Stack<int> stackInt = Stack<int>();

    // Store several numbers to the stack
    stackInt.Push(32);
    stackInt.Push(47);
    stackInt.Push(18);
    stackInt.Push(59);
    stackInt.Push(88);
    stackInt.Push(91);

    // list the element of stack
    while(!stackInt.IsEmpty())
    {
        // Get the top element
        cout << stackInt.Top() << " - ";

        // Remove the top element
        stackInt.Pop();
    }
    cout << "END" << endl;

    return 0;
}
