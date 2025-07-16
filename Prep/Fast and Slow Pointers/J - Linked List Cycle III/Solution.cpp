#include "LinkedList.h"

int CountCycleLength(ListNode* head) {
    // Initialize fast and slow pointers
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list to detect a cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;

        // If the pointers meet, there is a cycle
        if (slow == fast) {
            // Initialize cycle counter
            int length = 1;

            // Move slow pointer by one step to start counting
            slow = slow->next;

            // Continue moving the slow pointer until it meets the fast pointer
            while (slow != fast) {
                length++;
                slow = slow->next;
            }

            return length;
        }
    }

    // If no cycle found return 0
    return 0;
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
    int cycle = CountCycleLength(linkedlists.head);
    std::cout << "\n\n\tCycle length = " << cycle << "\n";
    std::cout << std::string(100, '-') << "\n";
  }
}
