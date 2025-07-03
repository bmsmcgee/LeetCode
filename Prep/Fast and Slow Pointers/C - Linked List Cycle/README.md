# Linked List Cycle

## Statement

Given the `head` of a linked list, determine whether the list contains a cycla. A cycle exists if a node in the list can be revisited by continuously following the `next` pointers. Return TRUE if a cycle is present; otherwise, return FALSE.

## Approach

1. Initialize two pointers, `fast` and `slow`, which point to the head of the linked list.
2. Traverse the linked list using these two pointers. They move in the following way:
   - The `slow` pointer moves only one node forward in each iteration.
   - The `fast` pointer moves two nodes forward in each iteration, which means that it skips a node.
3. If the `fast` pointer becomes NULL, we have reached the end of the linked list. Since no cycle exists, return FALSE.
4. If both `slow` and `fast` pointers become equal to each other, return TRUE, since a cycle exists in the linked list.

## Visualization

![image](https://github.com/user-attachments/assets/42c597bf-ad38-4b25-999a-c620ee7e7629)

![image](https://github.com/user-attachments/assets/49a8a8d5-6222-433f-8375-844f8fc37e17)

![image](https://github.com/user-attachments/assets/1d95b636-65a8-4e73-a58e-6f1f499e0ed8)

![image](https://github.com/user-attachments/assets/dbc5106e-b66d-4a96-bd40-14bcfc8a4be1)

![image](https://github.com/user-attachments/assets/99328626-b7bc-4390-9b83-c147c37df597)

![image](https://github.com/user-attachments/assets/7c0891ef-b8ae-40c7-b07e-fa9c824b207b)

## Time Complexity

The time complexity of the algorithm is $O(n)$, where $n$ is the number of nodes in the linked list.

## Space Complexity

The space complexity of the algorithm is $O(1)$.
