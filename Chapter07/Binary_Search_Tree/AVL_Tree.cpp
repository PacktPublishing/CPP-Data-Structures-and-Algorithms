// Project: Binary_Search_Tree.cbp
// File   : AVL_Tree.cpp

#include <iostream>
#include "AVLNode.h"

using namespace std;

int main()
{
    cout << "AVL Tree" << endl;

    // Instantiate BST instance
    AVL * avlTree = new AVL;

    // Insert first key
    avlTree->Insert(69);

    /*
        Add key 62
              69
             /
           62
    */
    avlTree->Insert(62);

    /*
        Add key 46
        it will rotate right since
        the balance = 2
              62
             /  \
           46    69
    */
    avlTree->Insert(46);

    /*
        Add key 32
              62
             /  \
           46    69
          /
        32
    */
    avlTree->Insert(32);

    /*
        Add key 24
        it will rotate right since
        the balance = 2
              62
             /  \
           32    69
          /  \
        24    46
    */
    avlTree->Insert(24);

    /*
        Add key 13
        it will rotate right since
        the balance = 2
              32
             /  \
           24    62
          /     /  \
        13    46    69
    */
    avlTree->Insert(13);

    // Prove the avlTree
    // Successor(32) should be 46
    // Successor(13) should be 24
    // Successor(69) should be -1 or NULL
    cout << "Successor(32) = ";
    cout << avlTree->Successor(24) << endl;
    cout << "Successor(13) = ";
    cout << avlTree->Successor(13) << endl;
    cout << "Successor(69) = ";
    cout << avlTree->Successor(69) << endl;

    return 0;
}
