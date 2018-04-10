#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>

class BinaryHeap
{
private:
    std::vector<int> vect;
    int heapSize;

    // three helper navigation function
    int p(int i) { return i>>1; } // i/2
    int l(int i) { return i<<1; } // i*2
    int r(int i) { return (i<<1)+1; } // i*2+1

    void ShiftUp(int index);
    void ShiftDown(int i);

public:
    BinaryHeap();

    bool IsEmpty();
    void Insert(int key);
    int ExtractMax();
    int GetMax();
};

#endif // BINARYHEAP_H
