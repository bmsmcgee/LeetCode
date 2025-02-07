/**
 * Definition for singly-linked list.
 * A linked list node represents a single digit in a number.
 */
struct ListNode {
    int val;  // Stores a single digit of the number
    ListNode *next;  // Pointer to the next digit (node)
    
    // Default constructor (creates a node with value 0 and no next node)
    ListNode() : val(0), next(nullptr) {}

    // Constructor with a given value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with a given value and pointer to next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node to simplify list operations
        ListNode* dummyHead = new ListNode(0);
        
        // `curr` is the pointer to track the new list being built
        ListNode* curr = dummyHead;
        
        // `carry` stores the carry-over when sum >= 10
        int carry = 0;

        // Traverse both linked lists until both are fully processed
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Extract values from the current nodes, or use 0 if the list is exhausted
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            // Compute sum of corresponding digits + carry
            int sum = x + y + carry;

            // Compute new carry for next column (sum >= 10)
            carry = sum / 10;

            // Create a new node with the last digit of `sum` and attach it to the result list
            curr->next = new ListNode(sum % 10);

            // Move `curr` pointer to the newly created node
            curr = curr->next;

            // Move `l1` and `l2` to the next node if they exist, otherwise set to nullptr
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        // The real result starts from `dummyHead->next`, so we delete dummyHead
        ListNode *result = dummyHead->next;
        delete dummyHead; // Free dummy head node memory

        return result; // Return the sum list
    }
};