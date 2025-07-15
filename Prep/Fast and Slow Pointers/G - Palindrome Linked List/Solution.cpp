#include "LinkedListReverse.cpp"

bool CompareTwoHalves(ListNode* firstHalf, ListNode* secondHalf){
  // Compare the corresponding nodes of the first and second halves of the linked list
  while(firstHalf != nullptr && secondHalf != nullptr){
    if (firstHalf->val != secondHalf->val){
      return false;
    }
    else{
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }
    
  }
  return true;
}

bool Palindrome(ListNode* head){
  // Initialize slow and fast pointers to the head of the linked list
  ListNode* slow = head;
  ListNode* fast = head;

  // Find the middle of the linked list using the slow and fast pointers
  while(fast != nullptr and fast->next != nullptr){
    // move slow one step forward
    slow = slow->next;
    // move fast two steps forward
    fast = fast->next->next;
  }

  // Reverse the second half of the linked list starting from the middle node		
  ListNode* revertData = ReversedList(slow);

  // Compare the first half of the linked list with the reversed second half of the linked list
  bool check = CompareTwoHalves(head, revertData);
  // Re-reverse the second half of the linked list to restore the original linked list
  ReversedList(revertData);
  // Return True if the linked list is a palindrome, else False
  if(check){
    return true; }
  
  return false;
}
// Driver code
int main() {
  std::vector<std::vector<int>> inputs = {
    {2, 4, 6, 4, 2},
    {0, 3, 5, 5, 0},
    {9, 7, 4, 4, 7, 9},
    {5, 4, 7, 9, 4, 5},
    {5, 9, 8, 3, 8, 9, 5}
  };

  for(int i = 0; i<inputs.size(); i++){
    LinkedList inputLinkedList(inputs[i]);

    std::cout << i + 1 << ".\tLinked List: ";
    display(inputLinkedList.head);

    std::cout << "\n\tIs it a palindrome?: " << (Palindrome(inputLinkedList.head) == true ? "Yes" : "No") << "\n";
    std::cout << std::string(100, '-') << "\n";
  }
}
