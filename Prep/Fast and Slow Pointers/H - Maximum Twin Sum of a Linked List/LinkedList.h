#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include "ListNode.cpp"

using namespace std;

class LinkedList {
public:
  ListNode* head;

  // Constructors
  LinkedList();
  LinkedList(const vector<int>& values);

  // Function to create a linked list from a vector of values
  void createLinkedList(const vector<int>& values);

  // Destructor
  ~LinkedList();
};

// Function to display the linked list
void display(ListNode* head);

#endif // LINKEDLIST_H
