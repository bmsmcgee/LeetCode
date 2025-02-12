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
    // Function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Create a dummy node to simplify operations
        ListNode *dummy = new ListNode(0, head);
        
        // Step 2: `before` is the last node before the group to be reversed
        ListNode *before = dummy;
        
        // `after` points to the start of the current group
        ListNode *after = head;
        
        // Temporary pointers for reversal
        ListNode *cur = nullptr;
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;

        // Step 3: Process groups of `k` nodes at a time
        while (1) {
            // Step 3a: Check if there are at least `k` nodes left
            ListNode* cursor = after;
            for (int i = 0; i < k; i++) {
                if (cursor == nullptr) { 
                    // If less than `k` nodes remain, return the modified list
                    ListNode *res = dummy->next;
                    delete dummy;
                    return res;
                }
                cursor = cursor->next;
            }

            // Step 3b: Reverse `k` nodes
            cur = after;  // Current node to process
            prev = before; // Previous node for linking back after reversal
            for (int i = 0; i < k; i++) {
                nxt = cur->next; // Store next node
                cur->next = prev; // Reverse current node
                prev = cur; // Move `prev` forward
                cur = nxt; // Move `cur` to next node
            }

            // Step 3c: Update pointers to maintain correct connections
            after->next = cur;  // Link last node of reversed segment to remaining list
            before->next = prev; // Connect reversed segment to previous part
            
            // Step 3d: Move `before` and `after` pointers for the next group
            before = after;
            after = cur;
        }
    }
};