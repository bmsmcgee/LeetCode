#include "LinkedList.h"

ListNode* RemoveNthLastNode(ListNode *head, int n)
{
	// Point two pointers, right and left, at head.
	ListNode *right = head;
	ListNode *left = head;

	// Move right pointer n elements away from the left pointer.
	for (int i = 0; i < n; i++)
	{
		right = right->next;
	}

	// Removal of the head node.
	if (!right)
	{
		return head->next;
	}

	// Move both pointers until right pointer reaches the last node.
	while (right->next)
	{
		right = right->next;
		left = left->next;
	}

	// At this point, left pointer points to (n-1)th element.
	// So link it to next to next element of left.
	left->next = left->next->next;

	return head;
}

// Driver Code
int main()
{
	std::vector<std::vector < int>> inputs = {
		{ 23, 89, 10, 5, 67, 39, 70, 28 },
		{ 34, 53, 6, 95, 38, 28, 17, 63, 16, 76 },
		{ 288, 224, 275, 390, 4, 383, 330, 60, 193 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 69, 8, 49, 106, 116, 112, 104, 129, 39, 14, 27, 12 }
	};

	std::vector<int> n = { 4, 1, 6, 9, 11 };

	for (int i = 0; i < inputs.size(); ++i) {
		LinkedList inputLinkedList(inputs[i]);
		std::cout << i + 1 << ".\tLinked List:\t\t";
		display(inputLinkedList.head);
		std::cout << "\n\tn = " << n[i] << std::endl;
		std::cout << "\tUpdated Linked List:\t";
		ListNode* updatedHead = RemoveNthLastNode(inputLinkedList.head, n[i]);
		display(updatedHead);
		std::cout << "\n" << std::string(100, '-') << "\n";
	}
}