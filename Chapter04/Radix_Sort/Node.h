// Project: Radix_Sort.cbp
// File   : Node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node
{
public:
    T Value;
    Node<T> * Next;

    Node(T value);
};

template <typename T>
Node<T>::Node(T value) : Value(value), Next(NULL) {}

#endif // NODE_H
