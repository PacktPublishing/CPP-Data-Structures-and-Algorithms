// Project: Hash_Table_SC.cbp
// File   : HashTable.cpp

#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
      tableList[i].clear();
}

int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    bool isKeyFound = false;

    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Iterate through chaining node (linked list)
    // in selected cell
    for (auto &keyValue : tableList[hashKey])
    {
        // if the key is found
        // update the data
        if (keyValue.first == key)
        {
            isKeyFound = true;
            keyValue.second = value;
        }
    }

    // If key is not found,
    // append at the back
    if (!isKeyFound)
        tableList[hashKey].emplace_back(key, value);
}

string HashTable::Search(int key)
{
    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Iterate through chaining node (linked list)
    // in selected cell
    for (auto &keyValue : tableList[hashKey])
    {
        // if the key is found
        // return the value of name
        if (keyValue.first == key)
        {
            return keyValue.second;
        }
    }

    // If this statement is reached
    // it means that the key is not found
    // so just return empty string
    return "";
}

void HashTable::Remove(int key)
{
    // Get hash key from hash function
    int hashKey = HashFunction(key);

    // Get the cell
    auto &cell = tableList[hashKey];

    // Tranverse the chaining node (linked list)
    for (auto it = cell.begin(); it != cell.end(); ++it)
    {
        // if the key is found
        // then delete the list's element
        if (it->first == key)
        {
            cell.erase(it);
            break;
        }
    }

    // Note: if key is not found just do nothing
}

bool HashTable::IsEmpty()
{
    // Initialize total element
    int totalElement = 0;

    // Count all elements in table hash
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        totalElement += (int)tableList[i].size();

        // If the total element is not zero
        // the hash table must not be empty
        if (totalElement > 0)
            return false;
    }

    // If this statement is reached
    // it means that total element is zero
    return true;
}
