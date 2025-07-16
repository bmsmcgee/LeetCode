#include "LinkedList.h"

ListNode* RemoveCycle(ListNode* head) {
    // No cycle in an empty list
    if (!head) {
        return nullptr;
    }

    // Initialize fast and slow pointers
    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle
    while (true) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected, break out of loop
        if (slow == fast) {
            break;
        }

        // No cycle detected, return head
        if (!fast || !fast->next) {
            return head;
        }
    }

    // Find starting node of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find the last node in the cycle
    while (fast->next != slow) {
        fast = fast->next;
    }

    // Break the cycle
    fast->next = nullptr;

    // Return modified linked list with cycle removed
    return head;
}

// Driver code
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
    
    std::cout << "\n\n\tAfter Cyle Removed = ";
    PrintListWithForwardArrow(RemoveCycle(linkedlists.head));
    std::cout << "\n" << std::string(100, '-') << "\n";
  }
}
