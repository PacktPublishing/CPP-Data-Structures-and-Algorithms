// Project: Binary_Search_Tree.cbp
// File   : Binary_Search_Tree.cpp

#include <iostream>
#include "BSTNode.h"

using namespace std;

//int main()
//{
//    cout << "Binary Search Tree" << endl;
//
//    // Instantiate BST instance
//    BST * tree = new BST;
//
//    // Define key value to be inserted to BST
//    int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};
//
//    // Inserting keys
//    for(const int& key : keys)
//        tree->Insert(key);
//
//    // Traversing tree in order
//    // then print all keys
//    cout << "Tree keys: ";
//    tree->PrintTreeInOrder();
//
//    // Search key 31
//    // it should be found
//    cout << "Search key 31: ";
//    bool b = tree->Search(31);
//    if(b)
//        cout << "found";
//    else
//        cout << "NOT found";
//    cout << endl;
//
//    // Search key 18
//    // it should NOT be found
//    cout << "Search key 18: ";
//    b = tree->Search(18);
//    if(b)
//        cout << "found";
//    else
//        cout << "NOT found";
//    cout << endl;
//
//    // Retrieving minimum and maximum key
//    cout << "Min. Key : " << tree->FindMin();
//    cout << endl;
//    cout << "Max. Key : " << tree->FindMax();
//    cout << endl;
//
//    // Finding successor
//    // Successor(31) should be 53
//    // Successor(15) should be 23
//    // Successor(88) should be -1 or NULL
//    cout << "Successor(31) = ";
//    cout << tree->Successor(31) << endl;
//    cout << "Successor(15) = ";
//    cout << tree->Successor(15) << endl;
//    cout << "Successor(88) = ";
//    cout << tree->Successor(88) << endl;
//
//    // Finding predecessor
//    // Predecessor(12) should be 7
//    // Predecessor(29) should be 23
//    // Predecessor(3) should be -1 or NULL
//    cout << "Predecessor(12) = ";
//    cout << tree->Predecessor(12) << endl;
//    cout << "Predecessor(29) = ";
//    cout << tree->Predecessor(29) << endl;
//    cout << "Predecessor(3) = ";
//    cout << tree->Predecessor(3) << endl;
//
//    // Removing a key
//    cout << "Removing key 15" << endl;
//    tree->Remove(15);
//    cout << "Removing key 53" << endl;
//    tree->Remove(53);
//
//    // Printing all keys again
//    // Key 15 and 53 should be disappeared
//    cout << "Tree keys: ";
//    tree->PrintTreeInOrder();
//
//    return 0;
//}
