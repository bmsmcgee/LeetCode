/*
// Definition for a Node.
class Node {
public:
    int val;       // Stores the value of the node
    Node* next;    // Pointer to the next node
    Node* random;  // Pointer to any node in the list (or nullptr)
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution {
    public:
        // Function to create a deep copy of the linked list with random pointers
        Node* copyRandomList(Node* head) {
            if (!head) {
                return nullptr; // If the input list is empty, return nullptr
            }
    
            // Step 1: Clone each node and insert the clone immediately after the original node
            Node* cur = head;
            while (cur) {
                Node* newNode = new Node(cur->val); // Create a new node with the same value
                newNode->next = cur->next; // Link the new node's next to the original node's next
                cur->next = newNode; // Insert the new node after the original node
                cur = newNode->next; // Move to the next original node
            }
    
            // Step 2: Assign random pointers to the copied nodes
            cur = head;
            while (cur) {
                if (cur->random) {
                    cur->next->random = cur->random->next; // Assign random pointer to copied node
                }
                cur = cur->next->next; // Move to the next original node
            }
    
            // Step 3: Separate the original and copied lists
            Node* oldHead = head; // Pointer to the original list
            Node* newHead = head->next; // Pointer to the new copied list
            Node* curOld = oldHead; // Pointer for traversing the original list
            Node* curNew = newHead; // Pointer for traversing the new list
    
            while (curOld) {
                curOld->next = curOld->next->next; // Restore the original list
                curNew->next = curNew->next ? curNew->next->next : nullptr; // Fix next pointers in new list
                curOld = curOld->next; // Move forward in the original list
                curNew = curNew->next; // Move forward in the copied list
            }
    
            return newHead; // Return the deep copied list
        }
    };