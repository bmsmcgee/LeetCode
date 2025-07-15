# Palindrome Linked List

## Statement

Given the head of a linked list, your task is to check whether the linked list is a palindrome or not. Return TRUE if the linked list is a palindrome; otherwise, return FALSE.

  > **Note:** The original structure of the linked list must remain unchanged before and after the checking process.

## Approach

1. First, find the middle node of the linked list. To do this, traverse the linked list using two pointers, where the `slow` pointer will move one step forward, and the `fast` pointer will move two steps forward. Do this until the `fast` pointer reaches the end of the list or a null node. At this point, the `slow` pointer will be pointing at the middle node of the list.
2. Next, reverse the `secondHalf` of the linked list, starting from the node after the middle node. To reverse the list, call the function `ReverseLinkedList`, passing the `slow` node as a parameter, representing the head of the `secondHalf` of the linked list. The following steps are in the `ReverseLinkedList` function:
    - Initialize three pointers: `prev`, `next`, and `curr`. The `prev` and `next` pointers are initialized as NULL, while `curr` is initialized to the head of the linked list.
    - Iterate over the linked list. Perform the following steps while iterating:
        - Before changing the next of `curr`, store the next node using the following line of code: `next = curr.next`.
        - Update the `next` pointer of `curr` with the `prev` pointer. This will reverse the pointer of the current node from forward to backward, eventually aiding the reversal of the linked list.
        - After reversing the pointer, update `prev` as `curr` and `curr` as `next`, using the following lines of code: `prev = curr` and `curr = next`.
3. Now, compare every element of the `firstHalf` of the linked list with the corresponding element in the `secondHalf` of the reversed linked list. To do this, call the helper function `CompareTwoHalves`, passing the heads of the two linked lists:
    - Compare the nodes of each list from start to end. The list is a palindrome if they are the same, and return TRUE. Otherwise, return FALSE.
4. Finally, reverse the `secondHalf` of the list again to restore its original structure, ensuring the linked list remains unchanged after the palindrome check.

## Visual

<img width="931" height="510" alt="image" src="https://github.com/user-attachments/assets/2d38eb18-2227-414b-9c60-cd88444ce057" />

<img width="934" height="510" alt="image" src="https://github.com/user-attachments/assets/0cd8c5b5-e2ac-415d-add6-7e7793210cfa" />

<img width="933" height="513" alt="image" src="https://github.com/user-attachments/assets/cbf29e64-8399-45cb-8a37-da9664053211" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/d5cdb0c4-deab-48b5-8a2c-bb71d60424e0" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/60e89341-41fc-49e0-bd11-09a21a53217e" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/b3caa787-6421-4c63-8a42-c500df145505" />

<img width="934" height="513" alt="image" src="https://github.com/user-attachments/assets/6656bb07-6a0a-4c25-881a-c3d227f59c56" />

<img width="934" height="511" alt="image" src="https://github.com/user-attachments/assets/29c87ac7-c618-498b-bfe0-e61f6b322f23" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/8182a6ca-017d-46c4-9299-7b7d5e1b48b6" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/ee9ec931-2150-48f7-b00e-6c6f61f9f02e" />

<img width="932" height="510" alt="image" src="https://github.com/user-attachments/assets/3a30865c-5c0a-4dc0-9bdf-6fe632744761" />

<img width="934" height="511" alt="image" src="https://github.com/user-attachments/assets/f2dc341e-b5f4-46c1-a8c5-4049a215427d" />

<img width="932" height="513" alt="image" src="https://github.com/user-attachments/assets/f646c0e3-6e35-4121-8df6-0a37fd466a9e" />

## Time Complexity

The time complexity is $O(n)$, where $n$ is the total number of nodes in the linked list.

## Space Complexity

The space complexity is $O(1)$, because it does not use any extra space in memory.
