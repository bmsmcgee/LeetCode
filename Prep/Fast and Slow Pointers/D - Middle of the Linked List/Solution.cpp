ListNode* GetMiddleNode(ListNode* head){

  // Create two pointers, slow and fast ,initially pointing to the head
  ListNode* slow = head;
  ListNode* fast = head;

  // Traverse the linked list until fast reaches at the last node or NULL
  while(fast != nullptr && fast->next != nullptr){

    // Move the slow pointer one step ahead
    slow = slow->next;

    // Move the fast pointer two steps ahead
    fast = fast->next->next;
  }
  
  // Return the slow pointer
  return slow;
}

// Driver code
int main() {
  std::vector<std::vector<int>> inputs = {
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5, 6},
    {3, 2, 1},
    {10},
    {1, 2}
  };

  for(int i = 0; i<inputs.size(); i++){
    LinkedList inputLinkedList(inputs[i]);

    std::cout << i + 1 << ".\tLinked list: ";
    display(inputLinkedList.head);

    ListNode* middle = GetMiddleNode(inputLinkedList.head);
    std::cout << "\n\tMiddle of the linked list: " << middle->val << "\n";
    std::cout << std::string(100, '-') << "\n";
  }
}
