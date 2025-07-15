# Find the Duplicate Number

## Statement

Given an array of positive numbers, `nums`, such that the values lie in the range $[1,n]$, inclusive, and that there are $n + 1$ numbers in the array, find and return the duplicate number present in `nums`. There is only one repeated number in `nums`, but it may appear more than once in the array.

> **Note:** You cannot modify the given array `nums`. You have to solve the problem using only constant extra space.

## Approach

1. The `slow` pointer moves once, while the `fast` pointer moves twice as fast as the `slow` pointer until both of the pointers meet each other. Since the `fast` pointer is moving twize as fast as the `slow` pointer, it will be the first one to enter and move around the cycle. At some point after, the `slow` pointer also enters and moves in the cycle, the `fast` pointer will meet the `slow` pointer. This will be the intersection point.

   > **Note:** The _intersection_ point of the the two pointers is, in the general case, not the _entry_ point of the cycle.

2. Start moving again in the cycle, but this time, slow down the `fast` pointer so that it moves with the same speed as the `slow` pointer.
    - The `slow` pointer will start from the $0^{th}$ position.
    - The `fast` pointer will start from the intersection point.
    - After a certain number of steps, $F$, the `slow` pointer meets the `fast` pointer. This is the ending point for both pointers.
    - This common ending position will be the entry point of the cycle.

## Visual

<img width="942" height="511" alt="image" src="https://github.com/user-attachments/assets/ad8c7095-683d-45dd-8988-ab614da0c8ab" />

<img width="942" height="512" alt="image" src="https://github.com/user-attachments/assets/d904317a-e908-4bea-9c5b-f5190e44dd86" />

<img width="941" height="512" alt="image" src="https://github.com/user-attachments/assets/58462abf-ecfa-49ee-a049-8b3e2895be97" />

<img width="941" height="513" alt="image" src="https://github.com/user-attachments/assets/1f0b5891-6085-436d-8c49-456260b2a856" />

<img width="942" height="511" alt="image" src="https://github.com/user-attachments/assets/bd748c81-8aea-47e1-9097-441cf85227d2" />

<img width="943" height="512" alt="image" src="https://github.com/user-attachments/assets/8a8567e6-7522-443b-aac1-7b6810457a1f" />

<img width="941" height="513" alt="image" src="https://github.com/user-attachments/assets/90b1620b-501c-453e-957a-584d946ff69d" />

<img width="942" height="513" alt="image" src="https://github.com/user-attachments/assets/0b5f4771-5383-4745-844a-41bf0073e7f5" />

<img width="942" height="512" alt="image" src="https://github.com/user-attachments/assets/ad62404c-7112-48c9-85f9-a832971ce185" />

<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/f5786b0a-dfbf-49b9-b3ec-3dc9991e906d" />

<img width="942" height="512" alt="image" src="https://github.com/user-attachments/assets/779ee414-fa1d-4c29-bb26-47f8f7bdd883" />

<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/a5bef6a0-74ef-4d1a-b406-c598354e30b6" />

<img width="941" height="513" alt="image" src="https://github.com/user-attachments/assets/102c050c-06b6-4202-8517-d1c95405f071" />

<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/e0c00db5-c121-4a41-8478-4a59b2d40085" />

<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/f75dfd68-9171-48a3-a242-188b18e66f30" />

<img width="939" height="511" alt="image" src="https://github.com/user-attachments/assets/d3015d64-828e-4d7a-b45a-5bd9b0410cd2" />

<img width="940" height="510" alt="image" src="https://github.com/user-attachments/assets/6dbbbf8d-144e-4b45-9ab3-f32551a98366" />

<img width="940" height="511" alt="image" src="https://github.com/user-attachments/assets/6a503742-3bbb-42d6-bbce-bc97dea30aab" />

<img width="942" height="512" alt="image" src="https://github.com/user-attachments/assets/7a15fb49-b47a-4755-b3af-7bb6a98119b7" />

<img width="939" height="510" alt="image" src="https://github.com/user-attachments/assets/c801e704-82d1-4914-b50a-b0f09c8af76b" />

<img width="940" height="512" alt="image" src="https://github.com/user-attachments/assets/5e165487-8abc-4753-bfca-3cb726c0b2c5" />

<img width="941" height="511" alt="image" src="https://github.com/user-attachments/assets/960b5a0f-bb17-40e7-af7b-8f764fcc6f69" />

<img width="939" height="510" alt="image" src="https://github.com/user-attachments/assets/9eae02e0-b68d-4eb5-8bca-b25252e57df4" />

## Time Complexity

The time complexity is $O(n)$, where $n$ is the length og `nums`. This is because the `slow` pointer traverses `nums` just once.

## Space Complexity

The space complexity is $O(1)$, since constant space is used to store the `fast` and `slow` pointers.
