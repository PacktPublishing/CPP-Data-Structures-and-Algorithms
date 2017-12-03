// Project: Node_Chain_Template.cbp
// File   : main.cpp
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T Value;
    Node<T> * Next;

    Node(T value) : Value(value){}
};

template<typename T>
void PrintNode(Node<T> * node)
{
    // It will print the initial node
    // until it finds NULL for the Next pointer
    // that indicate the end of the Node Chain
    while(node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

int main()
{
    // +------+------+
    // | 4.93 | NULL |
    // +------+------+
    Node<float> * node1 = new Node<float>(4.93);

    // +------+------+
    // | 6.45 | NULL |
    // +------+------+
    Node<float> * node2 = new Node<float>(6.45);

    // +------+------+
    // | 8.17 | NULL |
    // +------+------+
    Node<float> * node3 = new Node<float>(8.17);

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 | NULL |  | 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    node1->Next = node2;

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    node2->Next = node3;

    // Print the node
    PrintNode(node1);

    return 0;
}
