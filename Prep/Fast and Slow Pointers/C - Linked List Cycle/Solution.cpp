bool DetectCycle(ListNode* head){
  if(head == NULL){
    return false;
  }
  // Initialize two pointers, slow and fast, to the head of the linked list
  ListNode* slow = head;
  ListNode* fast = head;
  // Run the loop until we reach the end of the
  // linked list or find a cycle
  while(fast && fast->next){
    // Move the slow pointer one step at a time
    slow = slow->next;
    // Move the fast pointer two steps at a time
    fast = fast->next->next;

    // If there is a cycle, the slow and fast pointers will meet
    if (slow == fast){
      return true;
    } 
    
  }
  // If we reach the end of the linked list and haven't found a cycle, return False          
  return false;
}
// Driver Code
int main() {
  std::vector<std::vector<int>> inputs = {
    {2, 4, 6, 8, 10, 12},
    {1, 3, 5, 7, 9, 11},
    {0, 1, 2, 3, 4, 6},
    {3, 4, 7, 9, 11, 17},
    {5, 1, 4, 9, 2, 3}
  };

  std::vector<int> pos = {0, -1, 1, -1, 2};

  for(int i = 0; i<inputs.size(); i++){
    LinkedList linkedlists(inputs[i]);
    std::cout << i + 1 << ".\tInput:\t";
    if(pos[i] == -1){
      PrintListWithForwardArrow(linkedlists.head);
    }
    else{
      PrintListWithForwardArrowLoop(linkedlists.head);
    }
    std::cout<<"\n\tpos: "<<pos[i];
    if (pos[i] != -1){
      int length = GetLength(linkedlists.head);
      ListNode* lastNode = GetNode(linkedlists.head, length - 1);
      lastNode->next = GetNode(linkedlists.head, pos[i]);
    }
    bool cycle = DetectCycle(linkedlists.head);
    std::cout << "\n\n\tDetected cyle: " << std::boolalpha << cycle << "\n";
    std::cout << std::string(100, '-') << "\n";
  }
}
