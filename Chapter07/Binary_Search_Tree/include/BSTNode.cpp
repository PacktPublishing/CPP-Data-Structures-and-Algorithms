// Project: Binary_Search_Tree.cbp
// File   : BSTNode.cpp

#include "BSTNode.h"

BST::BST() : root(NULL)
{
}

BSTNode * BST::Insert(BSTNode * node, int key)
{
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
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

    return node;
}

void BST::Insert(int key)
{
    // Invoking Insert() function
    // and passing root node and given key
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode * node)
{
    // Stop printing if no node found
    if(node == NULL)
        return;

    // Get the smallest key first
    // which is in the left subtree
    PrintTreeInOrder(node->Left);

    // Print the key
    std::cout << node->Key << " ";

    // Continue to the greatest key
    // which is in the right subtree
    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    // Traverse the BST
    // from root node
    // then print all keys
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

BSTNode * BST::Search(BSTNode * node, int key)
{
    // The given key is
    // not found in BST
    if (node == NULL)
        return NULL;
    // The given key is found
    else if(node->Key == key)
        return node;
    // The given is greater than
    // current node's key
    else if(node->Key < key)
        return Search(node->Right, key);
    // The given is smaller than
    // current node's key
    else
        return Search(node->Left, key);
}

bool BST::Search(int key)
{
    // Invoking Search() operation
    // and passing root node
    BSTNode * result = Search(root, key);

    // If key is found, returns TRUE
    // otherwise returns FALSE
    return result == NULL ?
        false :
        true;
}

int BST::FindMin(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Successor(BSTNode * node)
{
    // The successor is the minimum key value
    // of right subtree
    if (node->Right != NULL)
    {
        return FindMin(node->Right);
    }
    // If no any right subtree
    else
    {
        BSTNode * parentNode = node->Parent;
        BSTNode * currentNode = node;

        // If currentNode is not root and
        // currentNode is its right children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the successor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Successor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // successor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Successor(keyNode);
}

int BST::Predecessor(BSTNode * node)
{
    // The predecessor is the maximum key value
    // of left subtree
    if (node->Left != NULL)
    {
        return FindMax(node->Left);
    }
    // If no any left subtree
    else
    {
        BSTNode * parentNode = node->Parent;
        BSTNode * currentNode = node;

        // If currentNode is not root and
        // currentNode is its left children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the predecessor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Predecessor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // predecessor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Predecessor(keyNode);
}

BSTNode * BST::Remove(
    BSTNode * node,
    int key)
{
    // The given node is
    // not found in BST
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

    // Return the updated BST
    return node;
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}



