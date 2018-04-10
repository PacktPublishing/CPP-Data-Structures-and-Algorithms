#include "AVLNode.h"

AVL::AVL() : root(NULL)
{
}

int AVL::GetHeight(BSTNode * node)
{
    // Return the Height of the node
    // Return -1 if the node is NULL
    return node == NULL ?
        -1 :
        node->Height;
}

BSTNode * AVL::RotateLeft(BSTNode * node)
{
    // The node must have a right child

    // Create a new node as a result
    // that will be a balanced node
    BSTNode * balancedNode = node->Right;

    // the balanced node will replace
    // the current node
    balancedNode->Parent = node->Parent;

    // the current node will be child
    // of the balanced node
    node->Parent = balancedNode;

    // The right child of current node
    // will be balanced node's left child
    node->Right = balancedNode->Left;

    // If balanced node has left child
    // point the parent to the current node
    if (balancedNode->Left != NULL)
        balancedNode->Left->Parent = node;

    // The left child of balanced node
    // will be the current node
    balancedNode->Left = node;

    // Refresh the node's height
    node->Height = std::max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    // Refresh the balanced node's height
    balancedNode->Height = std::max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    // return balancedNode
    return balancedNode;
}

BSTNode * AVL::RotateRight(BSTNode * node)
{
    // The node must have a left child

    // Create a new node as a result
    // that will be a balanced node
    BSTNode * balancedNode = node->Left;

    // the balanced node will replace
    // the current node
    balancedNode->Parent = node->Parent;

    // the current node will be child
    // of the balanced node
    node->Parent = balancedNode;

    // The left child of current node
    // will be balanced node's right child
    node->Left = balancedNode->Right;

    // If balanced node has right child
    // point the parent to the current node
    if (balancedNode->Right != NULL)
        balancedNode->Right->Parent = node;

    // The right child of balanced node
    // will be the current node
    balancedNode->Right = node;

    // Refresh the node's height
    node->Height = std::max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    // Refresh the balanced node's height
    balancedNode->Height = std::max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    // return balancedNode
    return balancedNode;
}

BSTNode * AVL::Insert(BSTNode * node, int key)
{
    // If AVL tree doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if (node == NULL)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
        node->Height = 0;
    }
    // If the given key is greater than
    // node's key then go to right subtree
    else if(node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    // If the given key is smaller than
    // node's key then go to left subtree
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    // Get the balance
    int balance =
        GetHeight(node->Left) - GetHeight(node->Right);

    // If left heavy
    if (balance == 2)
    {
        // Get left subtree's height
        int balance2 =
            GetHeight(node->Left->Left) -
            GetHeight(node->Left->Right);

        if (balance2 == 1)
        {
            node = RotateRight(node);
        }
        else
        {
            node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }
    }
    // If right heavy
    else if (balance == -2)
    {
        // Get right subtree's height
        int balance2 =
            GetHeight(node->Right->Left) -
            GetHeight(node->Right->Right);

        if (balance2 == -1)
            node = RotateLeft(node);
        else
        { // 1
            node->Right = RotateRight(node->Right);
            node = RotateLeft(node);
        }
    }

    // Refresh node's height
    node->Height = std::max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    // Return the updated AVL tree
    return node;
}

void AVL::Insert(int v)
{
    root = Insert(root, v);
}

BSTNode * AVL::Remove(BSTNode * node, int key)
{
    // The given node is
    // not found in AVL tree
    if (node == NULL)
        return NULL;

    // Target node is found
    if (node->Key == key)
    {
        // If the node is a leaf node
        // The node can be safely removed
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        // The node have only one child at right
        else if (node->Left == NULL && node->Right != NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Right->Parent = node->Parent;

            // Bypass node
            node = node->Right;
        }
        // The node have only one child at left
        else if (node->Left != NULL && node->Right == NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Left->Parent = node->Parent;

            // Bypass node
            node = node->Left;
        }
        // The node have two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);

            // Replace node's key with successor's key
            node->Key = successorKey;

            // Delete the old successor's key
            node->Right = Remove(node->Right, successorKey);
        }
    }
    // Target node's key is smaller than
    // the given key then search to right
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    // Target node's key is greater than
    // the given key then search to left
    else
        node->Left = Remove(node->Left, key);

    // Only perform rotation if node is not NULL
    if (node != NULL)
    {
        // Get the balance
        int balance =
            GetHeight(node->Left) - GetHeight(node->Right);

        // If left heavy
        if (balance == 2)
        {
            // Get left subtree's height
            int balance2 =
                GetHeight(node->Left->Left) -
                GetHeight(node->Left->Right);

            if (balance2 == 1)
            {
                node = RotateRight(node);
            }
            else
            {
                node->Left = RotateLeft(node->Left);
                node = RotateRight(node);
            }
        }
        // If right heavy
        else if (balance == -2)
        {
            // Get right subtree's height
            int balance2 =
                GetHeight(node->Right->Left) -
                GetHeight(node->Right->Right);

            if (balance2 == -1)
                node = RotateLeft(node);
            else
            { // 1
                node->Right = RotateRight(node->Right);
                node = RotateLeft(node);
            }
        }

        // Refresh node's height
        node->Height = std::max(
            GetHeight(node->Left),
            GetHeight(node->Right)) + 1;

    }

    // Return the updated AVL tree
    return node;
}

void AVL::Remove(int v)
{
    root = Remove(root, v);
}
