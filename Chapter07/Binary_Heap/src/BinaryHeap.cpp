#include "BinaryHeap.h"

BinaryHeap::BinaryHeap()
{
    // Clear the vector
    vect.clear();

    // Root will be index 1
    // so we set index 0 to be 'dummy'
    vect.push_back(-1);

    // An empty Binary Heap
    // contains no element
    heapSize = 0;
}

bool BinaryHeap::IsEmpty()
{
    // Heap is empty if only
    // heapSize = 0
    return heapSize == 0;
}

void BinaryHeap::ShiftUp(int index)
{
    // Do nothing in root
    if (index == 1)
        return;

    if (vect[index] > vect[p(index)])
    {
        // Swap Upwards
        std::swap(vect[index], vect[p(index)]);

        // Recurse until root
        ShiftUp(p(index));
    }
}

void BinaryHeap::Insert(int key)
{
    // Add a new element in vector
    if (heapSize + 1 >= (int)vect.size())
        vect.push_back(0);

    // Store the key in the vector last position
    vect[++heapSize] = key;

    // Shift upwards
    ShiftUp(heapSize);
}

void BinaryHeap::ShiftDown(int i)
{
    // For non-existing index
    // just do nothing
    if(i > heapSize)
        return;

    // Initialize swapId
    int swapId = i;

    // Compare with left child, if exists
    if (l(i) <= heapSize && vect[i] < vect[l(i)])
        swapId = l(i);

    // Compare with right child, if exists
    if (r(i) <= heapSize && vect[swapId] < vect[r(i)])
        swapId = r(i);

    // Swap with the larger of the two children
    if (swapId != i)
    {
        // Swap downwards with the larger
        // of the two children
        std::swap(vect[i], vect[swapId]);

        // Recurse until the index
        ShiftDown(swapId);
    }
}

int BinaryHeap::ExtractMax()
{
    // Maximum value is in root
    int maxVal = vect[1];

    // Swap with the last existing leaf
    std::swap(vect[1], vect[heapSize--]);

    // Fix heap property downwards
    ShiftDown(1);

    // Return the maximum value
    return maxVal;
}

int BinaryHeap::GetMax()
{
    // Return root's key
    return vect[1];
}
