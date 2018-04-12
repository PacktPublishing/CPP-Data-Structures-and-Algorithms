// Project: Hash_Table_OP_LP.cbp
// File   : HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#define TABLE_SIZE 7

class HashElement
{
    public:
        int Key;
        std::string Value;

        HashElement(int key, std::string value)
        {
            this->Key = key;
            this->Value = value;
        }
};

class HashTable
{
    private:
        int currentSize;
        HashElement * *arr;
        HashElement * deletedElement;

        int HashFunction(int key);

    public:
        HashTable();

        void Insert(int key, std::string value);
        std::string Search(int key);
        void Remove(int key);
        bool IsEmpty();
        void PrintHashTable();
};

#endif // HASHTABLE_H
