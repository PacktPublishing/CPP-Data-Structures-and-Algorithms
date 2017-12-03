// Project: Singly_Linked_List.cbp
// File   : LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList
{
private:
    int m_count;

public:
    // The first node in the list
    // or null if empty
    Node<T> * Head;

    // The last node in the list
    // or null if empty
    Node<T> * Tail;

    // Constructor
    LinkedList();

    // Get() operation
    Node<T> * Get(int index);

    // Insert() operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additional operation
    int Count();
    void PrintList();
};

template <typename T>
LinkedList<T>::LinkedList() : m_count(0), Head(NULL), Tail(NULL) {}

template <typename T>
Node<T> * LinkedList<T>::Get(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return NULL;

    // Start from the Head
    Node<T> * node = Head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for(int i = 0; i < index; ++i)
    {
        node = node->Next;
    }

    // Simply return the node result
    return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    // Create a new Node
    Node<T> * node = new Node<T>(val);

    // The current Head will no longer become a Head
    // so the Next pointer of the new Node will
    // point to the current Head
    node->Next = Head;

    // The new Node now become the Head
    Head = node;

    // If the linked list is empty
    // The Tail is also the Head
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // Create a new Node
    Node<T> * node = new Node<T>(val);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    Tail->Next = node;

    // The new Node now become the Tail
    Tail = node;

    // One element is added
    m_count++;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return;

    // If inserting a new Head
    if(index == 0)
    {
        InsertHead(val);
        return;
    }
    // If inserting a new Tail
    else if(index == m_count)
    {
        InsertTail(val);
        return;
    }

    // Start to find previous node
    // from the Head
    Node<T> * prevNode = Head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after previous node
    Node<T> * nextNode = prevNode->Next;

    // Create a new node
    Node<T> * node = new Node<T>(val);

    // Insert this new node between
    // the previous node and the next node
    node->Next = nextNode;
    prevNode->Next = node;

    // One element is added
    m_count++;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(m_count == 0)
        return -1;

    // Need to count the index
    int index = 0;

    // Traverse from the Head node
    Node<T> * node = Head;

    // Traverse until the selected value
    // is matched with the value
    // of the current position,
    while(node->Value != val)
    {
        index++;
        node = node->Next;

        // This will happen
        // if the selected value
        // is not found
        if(node == NULL)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current Head
    // to a new node
    Node<T> * node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // Start to find previous node
    // from the Head
    Node<T> * prevNode = Head;

    // This is the candidate of
    // removed items which is
    // the element next to the prevNode
    Node<T> * node = Head->Next;

    // Traverse the elements until
    // the last element
    while(node->Next != NULL)
    {
        prevNode = prevNode->Next;
        node = node->Next;
    }

    // the prevNode now becomes the Tail
    // so the Next pointer of the prevNode
    // point to NULL
    prevNode->Next = NULL;
    Tail = prevNode;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void LinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;

    // If removing the current Head
    if(index == 0)
    {
        RemoveHead();
        return;
    }
    // If removing the current Tail
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from the Head
    Node<T> * prevNode = Head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    Node<T> * node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    Node<T> * nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
int LinkedList<T>::Count()
{
    return m_count;
}

template <typename T>
void LinkedList<T>::PrintList()
{
    Node<T> * node = Head;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    std::cout << "NULL" << std::endl;
}


#endif // LINKEDLIST_H
