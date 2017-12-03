// Project: Node_Chain.cbp
// File   : main.cpp
#include <iostream>

using namespace std;

class Node
{
public:
    int Value;
    Node * Next;
};

void PrintNode(Node * node)
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
    // |  7   | NULL |
    // +------+------+
    Node * node1 = new Node;
    node1->Value = 7;

    // +------+------+
    // |  14  | NULL |
    // +------+------+
    Node * node2 = new Node;
    node2->Value = 14;

    // +------+------+
    // |  21  | NULL |
    // +------+------+
    Node * node3 = new Node;
    node3->Value = 21;

    // +------+------+  +------+------+  +------+------+
    // |  7   |   +---->|  14  | NULL |  |  21  | NULL |
    // +------+------+  +------+------+  +------+------+
    node1->Next = node2;

    // +------+------+  +------+------+  +------+------+
    // |  7   |   +---->|  14  |   +---->|  21  | NULL |
    // +------+------+  +------+------+  +------+------+
    node2->Next = node3;

    // Print the node
    PrintNode(node1);

    return 0;
}
