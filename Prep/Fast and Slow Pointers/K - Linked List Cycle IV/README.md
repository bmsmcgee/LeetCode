# Linked List Cycle IV

## Statement

Given the head of a singly linked list, implement a function to detect and remove any cycle present in the list. A cucle occurs when a nodes `next` pointer links back to a previous node, forming a loop within the list.

The function must modify the linked list in place, ensuring it remains acyclic while preserving the orginal node order. If no cycle is found, return the linked list as is.

## Approach

1. Initialize two pointers, `slow` and `fast`, to the `head` node.
2. Traverse the linked list using `slow` and `fast` pointers to detect a cycle:
   - Move `slow` one step forward.
   - Move `fast` two steps forward.
   - If `slow == fast`, a cycle is detected and break out of the loop.
3. if `fast` reaches `NULL`, the list is cycle-free and return `head`.
4. Once a cycle is detected, determine where it begins:
   - Reset `slow` to `head`.
   - Move both `slow` and `fast` one step at a time until they meet again. The meeting point is the starting node of the cycle.
5. To break the cycle, locate the last node in the loop:
   - Start from `fast`, which is now at the cycle's starting node.
   - Move forward through the cycle until `fast->next == slow` (this identifies the last node in the cyclke).
6. Set `fast->next = nullptr` to break the cycle and restore the linked list to a linear structure.
7. Return the `head` of the modified linked list.

## Visualization

<img width="934" height="513" alt="image" src="https://github.com/user-attachments/assets/c4dd2c10-291a-4867-9b17-f77131cb336a" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/82077020-9a56-4136-bc98-1f51136045f4" />

<img width="934" height="511" alt="image" src="https://github.com/user-attachments/assets/1171e52d-65fe-4380-9165-cf62dbe18b23" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/59b3d041-f1e8-4c7b-9ba1-8013d8f2df5b" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/08af70ad-9ffa-4d9f-a5b7-481487fefd8b" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/597971b6-dca5-4511-b642-49d6d83a7d6d" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/31de811f-28b9-4004-9709-bea7abbfcb31" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/29d0ffd2-ffb6-48ce-9bdb-7b52a182088d" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/d26bd4f3-cbe8-41f9-8110-2eea6199265c" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/ba48d21b-ba11-45e7-8936-9451a6ad10be" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/62273fa4-2d64-40dc-91bf-98b326fef0e8" />

<img width="934" height="513" alt="image" src="https://github.com/user-attachments/assets/ab97c4e7-a455-4a29-a040-2cbaf0689e79" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/b93f5b03-799d-4213-8b91-0251b0797149" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/7ce664c7-dd91-4313-b348-90755f4623b0" />

## Time Complexity

The time complexity is $O(n)$, where $n$ is the number of nodes in the linked list.

## Space Complexity

The space complexity is $O(1)$.
