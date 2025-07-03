# Middle of the Linked List

## Statement

Given the `head` of a singly linked list, return the middle node of the linked list. If the number of nodes in the linked list is even, there will be two middle nodes, so return the second one.

## Approach

1. Initialize two pointers, `slow` and `fast`, at the head of the linked list.
2. Traverse the linked list by moving the `slow` pointer one step forward, `slow = slow->next`, and the `fast` pointer two steps forward, `fast = fast->next->next`.
3. When the `fast` pointer reaches the last element of the linked list, or becomes equal to NULL, the `slow` pointer will point to the middle node. Return the node that the `slow` pointer points to.

## Visualization

![image](https://github.com/user-attachments/assets/6f6287ce-886a-4f04-8ff5-83b529bb4e54)

![image](https://github.com/user-attachments/assets/913fdeac-18a3-4f0f-9dda-d8757bf9999c)

![image](https://github.com/user-attachments/assets/f2c0e3fd-db28-4930-9d87-4b7c4c53de8f)

![image](https://github.com/user-attachments/assets/09342fac-e199-416a-99af-5bb5673af0a3)

![image](https://github.com/user-attachments/assets/a0ecba7a-b6e5-403e-83ee-9e880626dcc6)

![image](https://github.com/user-attachments/assets/af6d8715-20f9-4065-87e6-0cdc4ba84044)

## Time Complexity

The time complexity of the solution is $O(n)$, where $n$ is the number of nodes in the linked list.

## Space Complexity

The space complexity of the solution is $O(1)$.
