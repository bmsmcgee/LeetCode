/**
 * Definition for singly-linked list.
 * Represents a node in a singly linked list.
 */
struct ListNode {
    int val; // Value of the node
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
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify list operations
        ListNode* dummy = new ListNode(0);

        // Pointer to track the last node in the merged list
        ListNode* cur = dummy;

        // Step 1: Iterate through both lists and merge them in sorted order
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2; // Attach list2's node to merged list
                list2 = list2->next; // Move list2 pointer forward
            } else {
                cur->next = list1; // Attach list1's node to merged list
                list1 = list1->next; // Move list1 pointer forward
            }
            cur = cur->next; // Move merged list pointer forward
        }

        // Step 2: Attach remaining nodes (if any) after one list is exhausted
        cur->next = list1 ? list1 : list2;

        // Step 3: Store the actual head of the merged list
        ListNode* head = dummy->next;

        // Step 4: Clean up dummy node memory
        dummy->next = nullptr;
        delete dummy;

        // Step 5: Return the merged list head
        return head;
    }
};