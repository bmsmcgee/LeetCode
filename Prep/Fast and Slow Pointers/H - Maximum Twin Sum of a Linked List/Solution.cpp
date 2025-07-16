#include "LinkedList.h"

int TwinSum(ListNode* head) {
    // Initialize fast and slow pointers at the head of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    // Find the middle node of the linked list using fast and slow pointers
    while (fast && fast->next) {
        // Move slow pointer one step forward
        slow = slow->next;
        // Move fast pointer two steps forward
        fast = fast->next->next;
    }

    // Set curr at the middle node (slow) to reverse the second half of the linked list
    ListNode* curr = slow;
    ListNode* prev = nullptr;

    // Iterate through the list until curr reaches NULL
    while (curr) {
        // Save curr->next for later use
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // Initialize maxSum with 0 to keep track of the maximum twin sum found so far
    int maxSum = 0;

    // Set curr at the head of the linked list
    curr = head;

    // Iterate through the list until prev reaches NULL
    while (prev) {
        // Update maxSum if the current twin sum is greater than maxSum
        maxSum = std::max(maxSum, curr->val + prev->val);

        // Move both prev and curr pointers forward
        curr = curr->next;
        prev = prev->next;
    }

    // Return maxSum as the maximum twin sum of the given linked list
    return maxSum;
}

// Driver code
int main() {
    std::vector<std::vector<int>> lists = {
        {2, 3, 5, 7},
        {81, 144, 64, 121, 25, 49},
        {4, 5, 6, 7},
        {1, 1000},
        {11, 77, 44, 99, 22, 66, 55, 88}
    };

    for (int i = 0; i < lists.size(); ++i) {
        LinkedList inputLinkedList(lists[i]);
        std::cout << i + 1 << ".\tLinked list: ";
        display(inputLinkedList.head);
        std::cout << "\n\tMaximum twin sum: " << TwinSum(inputLinkedList.head);
        std::cout << "\n" << std::string(100, '-') << "\n";
    }

    return 0;
}
