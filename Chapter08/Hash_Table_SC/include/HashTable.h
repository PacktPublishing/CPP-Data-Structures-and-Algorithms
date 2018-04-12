// Project: Hash_Table_SC.cbp
// File   : HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>

#define TABLE_SIZE 7

class HashTable
{
    private:
        std::list<std::pair<int, std::string>>
            tableList[TABLE_SIZE];

        int HashFunction(int key);

    public:
        HashTable();

        void Insert(int key, std::string value);
        std::string Search(int key);
        void Remove(int key);
        bool IsEmpty();
};

#endif // HASHTABLE_H
