// DoublyNode.h
#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

#include <iostream>

template <typename T>
class DoublyNode
{
    public:
        T Value;
        DoublyNode<T> * Previous;
        DoublyNode<T> * Next;

        DoublyNode(T value);
};

template <typename T>
DoublyNode<T>::DoublyNode(T value)
    : Value(value), Previous(NULL), Next(NULL) {}

#endif // DOUBLYNODE_H
