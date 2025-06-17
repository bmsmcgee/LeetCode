#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int val = 0, ListNode* next = nullptr);
};

#endif // LISTNODE_H