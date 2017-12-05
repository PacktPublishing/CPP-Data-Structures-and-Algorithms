// Project: Doubly_Linked_List.cbp
// File   : main.cpp
#include <iostream>
#include "DoublyNode.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    // NULL
    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();

    // it will be printed backwardly
    // 43->NULL
    linkedList.InsertHead(43);

    // 43->76->NULL
    linkedList.InsertHead(76);

    // 15->43->76->NULL
    linkedList.InsertTail(15);

    // 44->15->43->76->NULL
    linkedList.InsertTail(44);

    // Print the list element
    cout << "First Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;

    // 100->44->15->43->76->NULL
    linkedList.Insert(4, 100);

    // 100->44->48->15->43->76->NULL
    linkedList.Insert(3, 48);

    // 100->44->48->15->43->76->22->NULL
    linkedList.Insert(0, 22);

    // Print the list element
    cout << "Second Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;

    return 0;
}
