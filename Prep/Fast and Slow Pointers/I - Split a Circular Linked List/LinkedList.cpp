#include "LinkedList.h"
#include <unordered_set>
// Default constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Constructor to initialize from a vector of values
LinkedList::LinkedList(const vector<int>& values) {
    head = nullptr;
    createLinkedList(values);
}

// Function to create a linked list from a vector of values
void LinkedList::createLinkedList(const vector<int>& values) {
    if (values.empty()) {
        head = nullptr;
        return;
    }

    head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
}

// Destructor to free memory
LinkedList::~LinkedList() {
    std::unordered_set<ListNode*> visited;
    ListNode* current = head;
    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Method for printing the linked list
void PrintCircularLinkedList(ListNode* linkedListNode) {
    if (linkedListNode == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    ListNode* temp = linkedListNode;
    std::unordered_set<ListNode*> seenNodes;

    do {
        std::cout << temp->val << " → ";
        seenNodes.insert(temp);
        temp = temp->next;
    } while (temp != linkedListNode && seenNodes.find(temp) == seenNodes.end());

    std::cout << "(head)" << std::endl;
}

// Method to convert the circular linked list to a vector
std::vector<int> ToArray(ListNode* node) {
    std::vector<int> result;
    if (node == nullptr) {
        return result;
    }

    std::unordered_set<ListNode*> seenNodes;
    ListNode* current = node;

    do {
        result.push_back(current->val);
        seenNodes.insert(current);
        current = current->next;
    } while (current != node && seenNodes.find(current) == seenNodes.end());

    return result;
}


