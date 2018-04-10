#ifndef AVLNODE_H
#define AVLNODE_H

#include "BSTNode.h"

class AVL : public BST
{
private:
    BSTNode * root;

    int GetHeight(BSTNode * node);
    BSTNode * RotateLeft(BSTNode * node);
    BSTNode * RotateRight(BSTNode * node);
    BSTNode * Insert(BSTNode * node, int key);
    BSTNode * Remove(BSTNode * node, int key);

public:
    AVL();

    void Insert(int v);
    void Remove(int v);
};

#endif // AVLNODE_H
