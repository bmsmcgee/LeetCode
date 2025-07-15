#include "LinkedList.cpp"

// Revert the second half of the linked_list to 
// compare it with the first half
ListNode* ReversedList(ListNode* slowPtr){
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
  ListNode* curr = slowPtr;
  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
