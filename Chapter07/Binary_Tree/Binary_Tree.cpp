// Project: Binary_Tree.cbp
// File   : Binary_Tree.cpp

#include <iostream>

using namespace std;

class TreeNode
{
public:
    int Key;
    TreeNode * Left;
    TreeNode * Right;
};

TreeNode * NewTreeNode(
    int key)
{
    // Create a new node
    TreeNode * node = new TreeNode;

    // Assign a key
    node->Key = key;

    // Initialize Left and Right pointer
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

void PrintTreeInOrder(TreeNode * node)
{
	if(node == NULL) return;

	PrintTreeInOrder(node->Left);
	cout << node->Key << " ";
	PrintTreeInOrder(node->Right);
}

void Print (TreeNode * x, int & id)
{
    if (!x) return;

    Print (x->Left,id);

    id++;
    cout << id << ' ' << x->Key << endl;

    Print (x->Right,id);
}

int main()
{
    cout << "Binary Tree" << endl;

    // Creating root element
    TreeNode * root = NewTreeNode(1);

    /*
        Add children to root element
          1
         / \
        2   3
    */
    root->Left = NewTreeNode(2);
    root->Right = NewTreeNode(3);

    /*
        Add children to element 2
             1
           /   \
          2     3
         / \
        4   5
    */
    root->Left->Left = NewTreeNode(4);
    root->Left->Right = NewTreeNode(5);

    /*
        Add children to element 3
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    root->Right->Left = NewTreeNode(6);
    root->Right->Right = NewTreeNode(7);

    int id = 0;
    Print(root, id);

    return 0;
}
