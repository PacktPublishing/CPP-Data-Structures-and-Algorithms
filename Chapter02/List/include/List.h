// Project: List.cbp
// File   : List.h
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
    private:
        int m_count;
        int * m_items;

    public:
        List();
        ~List();
        int Get(int index);
        void Insert(int index, int val);
        int Search(int val);
        void Remove(int index);
        int Count();
};
#endif // LIST_H
