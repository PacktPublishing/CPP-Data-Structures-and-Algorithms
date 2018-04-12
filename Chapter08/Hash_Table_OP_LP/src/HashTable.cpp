// Project: Hash_Table_OP_LP.cbp
// File   : HashTable.cpp

#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    // Initialize current size as 0
    currentSize = 0;

    // Initialize table
    arr = new HashElement * [TABLE_SIZE];
    for(int i = 0 ; i < TABLE_SIZE ; ++i)
        arr[i] = NULL;

    // Specify deleted node content
    deletedElement = new HashElement(-1, "");
}

int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    // It's impossible to store a new element
    // if hash table doesn't have free space
    if (currentSize >= TABLE_SIZE)
        return;

    // Create a temporary element
    // to be inserted to hash table
    HashElement * temp =
        new HashElement(key, value);

    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // Find next free space
    // using linear probing
    while(arr[hashIndex] != NULL &&
        arr[hashIndex]->Key != key &&
        arr[hashIndex]->Key != -1)
    {
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    // If there's new element to be inserted
    // then increase the current size
    if(arr[hashIndex] == NULL ||
        arr[hashIndex]->Key == -1)
    {
        ++currentSize;
        arr[hashIndex] = temp;
    }
}

string HashTable::Search(int key)
{
    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // Find the element with given key
    while(arr[hashIndex] != NULL &&
        arr[hashIndex]->Key != deletedElement->Key)
    {
        // If element is found
        // then return its value
        if(arr[hashIndex]->Key == key)
            return arr[hashIndex]->Value;

        // Keep looking for the key
        // using linear probing
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    //If not found return null
    return "";
}

void HashTable::Remove(int key)
{
    // Get hash key from hash function
    int hashIndex = HashFunction(key);

    // Find the element with given key
    while(arr[hashIndex] != NULL)
    {
        // If element is found
        // then mark the cell as deletedElement
        if(arr[hashIndex]->Key == key)
        {
            arr[hashIndex] = deletedElement;

            // Reduce size
            --currentSize;

            // No need to search anymore
            return;
        }

        // Keep looking for the key
        // using linear probing
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    // Note: if key is not found just do nothing
}

bool HashTable::IsEmpty()
{
    return currentSize == 0;
}

void HashTable::PrintHashTable()
{
    // Iterate through array
    for(int i = 0 ; i < currentSize; ++i)
    {
        // Just print the element
        // if it exist
        if(arr[i] != NULL && arr[i]->Key != -1)
        {
            cout << "Cell: " << i;
            cout << " Key: " << arr[i]->Key;
            cout << " Value: " << arr[i]->Value;
            cout << std::endl;
        }
    }
}
