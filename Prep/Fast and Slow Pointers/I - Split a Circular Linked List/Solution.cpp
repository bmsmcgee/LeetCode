#include "LinkedList.h"

std::vector<ListNode*>SplitCircularLinkedList(ListNode* head) {
    // If the list is empty, return a pair of null pointers
    if (head == nullptr) {
        return {nullptr, nullptr};
    }

    // Initialize slow and fast pointers at the head of the list
    ListNode* slow = head;
    ListNode* fast = head;

    // Move slow by one step and fast by two steps to find the middle node
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Start of the first half is the original head
    ListNode* head1 = head;

    // Start of the second half is the node after the slow pointer
    ListNode* head2 = slow->next;

    // Complete the first hald by linking slow's next back to head1
    slow->next = head1;

    // Set fast pointer to the start of the second half to copmlete it
    fast = head2;
    while (fast->next != head) {
        // Move fast to the end of the second half
        fast = fast->next;
    }

    // Link the last node of the second half back to head2 to make it circular
    fast->next = head2;

    // Return the heads of the two split circular linked lists
    return {head1, head2};
}

// Driver code
int main() {
    std::vector<std::vector<int>> lists = {
        {1, 5, 7},
        {2, 6, 1, 5},
        {3, 1, 4, 2, 5},
        {8, 10, 12, 14, 16, 18},
        {9, 10}
    };

    for (size_t index = 0; index < lists.size(); index++) {
        LinkedList inputLinkedList(lists[index]);
        ListNode* current = inputLinkedList.head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = inputLinkedList.head; // Connect last node to head
        std::cout << index + 1 << ". Linked list: ";
        PrintCircularLinkedList(inputLinkedList.head);
        // Split the circular linked list
        std::vector<ListNode*> splitLists = SplitCircularLinkedList(inputLinkedList.head);

        // Convert each split list to an array using a method that accepts the head of each list
        auto arrSplitList1 = ToArray(splitLists[0]);
        auto arrSplitList2 = ToArray(splitLists[1]);

        // Print the split lists in the desired format
        std::cout << "   Split Lists: [[" << arrSplitList1[0];
        for (size_t i = 1; i < arrSplitList1.size(); ++i) {
            std::cout << ", " << arrSplitList1[i];
        }
        std::cout << "], [";
        if (!arrSplitList2.empty()) {
            std::cout << arrSplitList2[0];
            for (size_t i = 1; i < arrSplitList2.size(); ++i) {
                std::cout << ", " << arrSplitList2[i];
            }
        }
        std::cout << "]]" << std::endl;
        std::cout << std::string(100, '-') << std::endl; // Print dashes
    }

    return 0;
}
