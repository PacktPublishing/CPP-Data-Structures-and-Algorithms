#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MinHeapNode
{
    public:
        // Input character
        char Data;

        // Frequency of the character
        unsigned Frequency;

        // Left and right child
        MinHeapNode * LeftChild, * RightChild;

        // Constructor
        MinHeapNode(char data, unsigned freq)
        {
            // Initialize left and right child
            LeftChild = NULL;
            RightChild = NULL;

            this->Data = data;
            this->Frequency = freq;
        }
};

class compare
{
    public:
        bool operator()(
            MinHeapNode * left,
            MinHeapNode * right)
        {
            return(
                left->Frequency > right->Frequency);
        }
};

void PrintCodes(MinHeapNode * root, string str)
{
    if (!root)
        return;

    if (root->Data != '$')
    {
        cout << root->Data << ": ";
        cout << str << endl;
    }

    PrintCodes(root->LeftChild, str + "0");
    PrintCodes(root->RightChild, str + "1");
}

void HuffmanCodes(char data[], int freq[], int dataSize)
{
    MinHeapNode * left, * right, * top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < dataSize; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode(
            '$', left->Frequency + right->Frequency);

        top->LeftChild = left;
        top->RightChild = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    PrintCodes(minHeap.top(), "");
}

int main()
{
//    char arr[] = { 'a', 'e', 'i', 's', 't', ' ', 'n' };
//    int freq[] = { 10, 15, 12, 3, 4, 13, 1 };
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
