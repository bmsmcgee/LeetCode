/**
 * Definition for singly-linked list.
 * Represents a node in a singly linked list.
 */
struct ListNode {
    int val;       // Stores the value of the node
    ListNode *next; // Pointer to the next node in the list

    // Default constructor (creates a node with value 0 and no next node)
    ListNode() : val(0), next(nullptr) {}

    // Constructor with a given value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with a given value and pointer to next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to reverse a singly linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode = nullptr;  // Stores the next node temporarily
        ListNode *prevNode = nullptr;  // Stores the previous node (initially NULL)
        ListNode *cur = head;          // Pointer to traverse the list

        // Traverse the list while the current node is not null
        while (cur) {
            nextNode = cur->next;   // Store the next node
            cur->next = prevNode;   // Reverse the current node's pointer
            prevNode = cur;         // Move prevNode forward
            cur = nextNode;         // Move cur forward
        }

        // After the loop, prevNode will be pointing to the new head of the reversed list
        head = prevNode;
        return head;
    }
};