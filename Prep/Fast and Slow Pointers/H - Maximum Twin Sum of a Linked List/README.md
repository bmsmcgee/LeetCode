# Maximum Twin Sum of a Linked List

## Statement

In a linked list with an even number of nodes ($n$), each node at position $i$ (using $0$-based indexing) is paired with the node at posisiont ($n-1-i$). These pairs are called twins for all $0\le i\lt\frac{n}{2}$.

For example, if $n=4$, the twin pairs are:
- The node at index $0$ pairs with the node at index $3$.
- The node at index $1$ pairs with the node at index $2$.

The twin sum is the sum of a node's value and its twin's value. Given the head of a linked list with an even number of nodes, return the maximum twin sum among all pairs.

## Approach

1. The first step is to find the middle node of the linked list:
   - Initialize two pointers, `slow` and `fast`, at the head of the linked list. The `slow` pointer will move one node at a time, while the `fast` pointer will move two nodes at a time.
   - Iterate through the linked list using these pointers as long as the `fast` pointer and its next node are _not_ NULL. the `slow` pointer moves one step, and the `fast` pointer moves two steps. By the time the `fast` pointer reaches the end, the `slow` pointer will be in the middle of the list.
2. The next step is to reverse the second half of the linked list:
   - Start iterating the linked list from the middle by initializing a pointer, `curr`, at the node where `slow` points.
   - Initialize another pointer `prev` with NULL.
   - Continue the loop as long as the `curr` is not NULL.
   - Inside the loop, modify the pointers as follows:
       - First, save `curr.next` to `temp` for later use.
       - Update `curr.next` to `prev`.
       - Update `prev` to `curr`.
       - Update `curr` to `temp`.
3. The final step is to find the twin sum for all twin nodes in the linked list:
   - Initialize `maxSum` with $0$ to keep track of the maximum twin sum found so far.
   - Initialize the `curr` pointer at the head of the linked list. Due to the reversing algorithm, the `prev` pointer would already be pointing at the head of the reversed second half.
   - Iterate through the list until `prev` reaches NULL.
   - Find the twin sum inside the loop by adding the data of the `curr` node and the `prev` node.
   - If this sum is freater than `maxSum`, update `maxSum` with this sum.
   - Move both `prev` and `curr` pointers forward.
4. Finally, return `maxSum` as the maximum twin sum of the given linked list.

## Visualization

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/b1899b1e-8b73-4d0b-babf-6952ac24b277" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/e8e10da5-e02c-4647-8b84-30e513270a2b" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/5cd1c958-81b7-4fe0-ad2f-7e8d29dab7f5" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/920fa3f7-d86d-46d7-80c7-d54469279694" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/a4b62761-e899-4f29-92f3-641d57772cbd" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/bf8f600f-7edc-4e1c-bab7-1c4d2b4aef46" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/a0cdc6ec-9e53-4307-b90e-820370eddc53" />

<img width="933" height="510" alt="image" src="https://github.com/user-attachments/assets/b6a1e8cf-30b0-4a4e-9f90-693424d8cd56" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/7747bc31-7509-46f2-9ac1-91808f52880d" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/39a2e99e-dd2b-43b0-868b-2c6252078460" />

<img width="934" height="511" alt="image" src="https://github.com/user-attachments/assets/9b67d73f-a0c5-4544-9598-75271505b009" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/1293982b-d46a-486b-9e54-f19448fae95c" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/1e822737-7aaf-4582-bbcc-70dbfaa69bb1" />

<img width="931" height="511" alt="image" src="https://github.com/user-attachments/assets/22b588c9-f718-4619-a61f-438cf386db68" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/034a7845-6d08-4fe7-a7d4-1fc9589cc569" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/3887f8d5-fe2b-4dfc-9073-be0b61f50ef1" />

<img width="934" height="513" alt="image" src="https://github.com/user-attachments/assets/44ec0c17-d9c9-4e92-91e1-98c0d963536a" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/488733a8-6467-4cbc-9f68-e7182208e49f" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/f27162ce-c5ab-44a3-a803-22436cc19d5f" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/468ad4eb-dd0d-42c5-b1f0-9a2ea25576cc" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/bd8716c4-6785-4de5-86f7-b657afbbd399" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/f6ac7606-e257-47eb-973d-6d48836cfe6d" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/002d8118-7ba8-4d44-82a8-06f5cbe0f524" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/ed874b1e-0a84-417e-a2d3-4de112b2bceb" />

<img width="932" height="511" alt="image" src="https://github.com/user-attachments/assets/fcc92bb3-08c8-48c3-926a-09f8143589b7" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/d71ef582-2a63-4f48-8c2d-942677e8470d" />

## Time Complexity

The algorithm's time complexity is $O(n)$, where $n$ is the length of the input linked list.This is because each part of the algorithm $\textemdash$ finding the middle node, reversing the second half of the linked list, and calculating the twin sums $\textemdash$ takes $O(n)$ time.

## Space Complexity

The algorithm's space complexity is $O(1)$.
