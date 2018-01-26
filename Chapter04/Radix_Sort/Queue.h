// Project: Radix_Sort.cbp
// File   : Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue
{
private:
    int m_count;
    Node<T> * m_front;
    Node<T> * m_back;

public:
    Queue();
    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
};

template <typename T>
Queue<T>::Queue() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Queue<T>::IsEmpty()
{
    // return TRUE if there's at least one item
    // otherwise, return FALSE
    return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
    // Just return the value
    // of m_front node
    return m_front->Value;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
    // Create a new Node
    Node<T> * node = new Node<T>(val);

    if(m_count == 0)
    {
        // If the queue is empty
        // the new node will be
        // m_front and m_back
        node->Next = NULL;
        m_front = node;
        m_back = m_front;
    }
    else
    {
        // If there's at least one element
        // in the queue, the current m_back element
        // won't be the Back element anymore
        // so the Next pointer of the current m_back
        // point to the new node
        m_back->Next = node;

        // The new Node now become the Back position
        m_back = node;
    }

    // One element is added
    m_count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current Front
    // to a new node
    Node<T> * node = m_front;

    // Point the Front pointer
    // to the element next to the current Front
    m_front = m_front->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One element is removed
    m_count--;
}

#endif // QUEUE_H
