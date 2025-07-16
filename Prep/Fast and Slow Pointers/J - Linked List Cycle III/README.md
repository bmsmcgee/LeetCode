# Linked List Cycle III

## Statement

Given the `head` of a linked list, determing the length of the cycle present in the linked list. If there is no cycle, return `0`.

A _cycle exists_ in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.

## Approach

1. Initialize two pointers, `fast` and `slow`, pointing at the linked list's `head`.
2. To detect a cycle in the linked list:
   - Move the `slow` pointer one step forward.
   - Move the `fast` pointer two steps forward.
   - If the `fast` pointer reaches `NULL` or `fast->next` is `NULL`, no cycle exists in the list.
   - If the `slow` and `fast` pointers meet, a cycle has been detected.
3. After finding the cycle, determine the length of the cycle by performing the following steps:
   - When a cycle is detected, fix on pointer at the meeting point (`fast`).
   - The `slow` pointer moves one step forward, initializing `length = 1` to count the first step.
   - The `slow` pointer continues, moving within the cycle one step at a time. The loop continues until `slow` reaches the meeting point (`fast`) again. Each step increments the `length` counter.
   - Once the loop copmletes, `length` contains the total number of node in the cycle. Return this value.
4. If no cycle is found, return `0`.

## Visualization

<img width="933" height="513" alt="image" src="https://github.com/user-attachments/assets/a50aa7b2-3803-4dcc-b15e-b4bd18247569" />

<img width="933" height="513" alt="image" src="https://github.com/user-attachments/assets/2e999abd-980b-498e-8e13-1efce23f4de6" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/63d9cbaa-c140-4b64-845c-22729f779fa1" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/f65bfcdf-c97e-42ed-ad19-cc38c648483a" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/3593d087-adff-4218-83a3-ae34589a7b72" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/ebed37ca-1445-43ab-b319-8a6f9db0b424" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/649003b3-4a58-4502-993b-bd50473245a8" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/1d8947d6-b25d-4fdd-b34d-c3a77d898999" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/620d9d09-d4ac-4dba-b78a-9ab539199e29" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/bf380ef4-8d04-4d00-9194-d1d404de4dc6" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/9b5d2a9d-c8a3-405b-b8da-3f64f19e26de" />

<img width="932" height="510" alt="image" src="https://github.com/user-attachments/assets/5784f476-6f67-448e-8b39-333273a30961" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/c25207a3-eb99-4084-b951-7a423f3e743a" />

<img width="932" height="513" alt="image" src="https://github.com/user-attachments/assets/f69cec9b-9013-476f-a88f-23589e70be75" />

## Time Complexity

The time copmlexity is $O(n)$, where $n$ is the number of nodes in the linked list.

## Space Complexity

The space complexity is $O(1)$.
