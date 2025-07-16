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

// returns the number of nodes in the linked list
int GetLength(ListNode* h){
    ListNode *temp = h;
    int length = 0;
    while(temp!=nullptr){
        length+=1;
        temp = temp->next;
	}	
    return length;
}

// returns the node at the specified position(index) of the linked list
ListNode* GetNode(ListNode* h, int pos){
    if (pos != -1){
        int p = 0;
        ListNode* ptr = h;
        while (p < pos){
            ptr = ptr->next;
            p += 1;
        }
        return ptr;
    }
    return h;
}

void PrintListWithForwardArrow(ListNode *linkedListNode)
{
    ListNode *temp = linkedListNode;
    while (temp)
    {
        std::cout << temp->val << " "; // print node value
        temp = temp->next;
        if (temp)
        {
            std::cout << "→ ";
        }
        else
        {
            // if this is the last node, print null at the end
            std::cout << "→ NULL ";
        }
    }
}

void PrintListWithForwardArrowLoop(ListNode *linkedListNode)
{
    ListNode *temp = linkedListNode;
    while (temp)
    {
        std::cout << temp->val << " "; // print node value
        temp = temp->next;
        if (temp)
        {
            std::cout << "→ ";
        }
        
    }
}
