#include "LinkedList.h"

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
    ListNode* current = head;
    while (current) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Function to display the linked list
void display(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "None" << endl;
}