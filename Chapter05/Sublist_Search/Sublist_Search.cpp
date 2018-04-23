// Project: Sublist_Search.cbp
// File   : Sublist_Search.cpp

#include <iostream>

using namespace std;

class Node
{
public:
    int Value;
    Node * Next;
};

void PrintNode(Node * node)
{
    // It will print the initial node
    // until it finds NULL for the Next pointer
    // that indicate the end of the Node Chain
    while(node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

bool CompareAllMatchedElements(
    Node * ptr1,
    Node * ptr2)
{
    // ptr2 cannot be NULL
    // since it will be compared
    // to ptr1
	if(ptr1 != NULL && ptr2 == NULL)
		return false;

    // It's the end of the first list element
	if(ptr1 == NULL)
		return true;

	// Compare value of each list
	if(ptr1->Value == ptr2->Value)
	{
        // Compare next element
		return CompareAllMatchedElements(
            ptr1->Next,
            ptr2->Next);
    }
    else
    {
        return false;
    }
}

bool SublistSearch(
    Node * firstList,
    Node * secondList)
{
    // If both are NULL,
    // just return true
	if(firstList == NULL && secondList == NULL)
	{
		return true;
    }

    // If one is NULL but the other is not,
    // just return false
	if((firstList != NULL && secondList == NULL) ||
        (firstList == NULL && secondList != NULL))
    {
		return false;
    }

    // Compare the value, if not match,
    // check next element of second list
	if (firstList->Value == secondList->Value)
	{
        // If matched, check deeper
		if(CompareAllMatchedElements(
            firstList,
            secondList))
		{
			return true;
        }
    }

    // Check next element of the second list
	return SublistSearch(firstList, secondList->Next);
}

int main()
{
    cout << "Sublist Search" << endl;

    // Initialize first list
    // 23 -> 30 -> 41
    Node * node1_c = new Node();
    node1_c->Value = 41;
    Node * node1_b = new Node();
    node1_b->Value = 30;
    node1_b->Next = node1_c;
    Node * node1_a = new Node();
    node1_a->Value = 23;
    node1_a->Next = node1_b;

    // Print the first list
    cout << "First list : ";
    PrintNode(node1_a);

    // Initialize second list
    // 10 -> 15 -> 23 -> 30 -> 41 -> 49
    Node * node2_f = new Node();
    node2_f->Value = 49;
    Node * node2_e = new Node();
    node2_e->Value = 41;
    node2_e->Next = node2_f;
    Node * node2_d = new Node();
    node2_d->Value = 30;
    node2_d->Next = node2_e;
    Node * node2_c = new Node();
    node2_c->Value = 23;
    node2_c->Next = node2_d;
    Node * node2_b = new Node();
    node2_b->Value = 15;
    node2_b->Next = node2_c;
    Node * node2_a = new Node();
    node2_a->Value = 10;
    node2_a->Next = node2_b;

    // Print the second list
    cout << "Second list: ";
    PrintNode(node2_a);

    // Notify user the result
    // if the return is true
    // the searched value is found
    cout << "Result: second list is ";
    if(SublistSearch(node1_a, node2_a))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
    cout << " in first list." << endl;

    return 0;
}
