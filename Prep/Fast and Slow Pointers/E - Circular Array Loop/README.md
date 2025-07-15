# Circular Array Loop

## Statement

There is a circular list of non-zero integers called `nums`. Each number in the list tells you how many steps to move forward or backward from you current position:
 - If `nums[i]` is positive, move `nums[i]` steps forward.
 - If `nums[i]` is negative, move `nums[i]` steps backward.

As the list is circular:
 - Moving forward from the last element takes you back to the first element.
 - Moving backward from the first element takes you to the last element.

A **cycle** in this list means:
 1. You keep moving according to the numbers, and you end up repeating a sequence of indexes.
 2. All numbers in the cycle have the same sign (either all positive or all negative).
 3. The cycle length is greater than 1 (it incolces at least two indexes).

## Approach

1. Initialize `fast` and `slow` pointers to the current index `i`.
2. Move the `slow` pointers, either forward or backward, depending on the current value it is pointing to, `nums[i]`. For example, if the value is `-3`, the `slow` pointer is moved three indexes backward. Similarly, if the value is `2`, the `slow` pointer is moved two indexes forward.
3. Check if a valid cycle can be formed. There a two primary checks:
   - If the index of the new value pointed to by `slow` is the same as the index of the previous value pointed to be `slow` (the pointer is forming a self-loop), then the next iteration starts.
   - Observe the sign of the previous value pointed to by `slow`and the sign of the new value it points to. If both values have different signs (the pointer is not moving in a single direction), then the next iteration starts.
4. Move the `fast` pointer twice in a similar fasion, and after every move, check for the validuty of the cycle using the same checks as the last step. If a valid cycle can't be formed, moved to the next index of `nums`.
5. Check for the existence of a cycle. If the slow and fast pointers meet at the same index, a cycle is detected. Return TRUE in this case. Otherwise, continue moving the pointers until we determine whether or not a cycle exists.

## Visual

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/8ba87a9b-260d-49b4-bde8-32a9a2b71098" />

<img width="931" height="511" alt="image" src="https://github.com/user-attachments/assets/d06593d3-113a-4bc0-9e70-4f90bd44a0f7" />

<img width="931" height="510" alt="image" src="https://github.com/user-attachments/assets/2ff201da-44e1-43df-85c3-194d31e6f2da" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/c014e5e9-ce41-4bd2-9aa7-bddaafbb701a" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/54f43b59-36ca-44d1-949f-aecc560f11e7" />

<img width="932" height="513" alt="image" src="https://github.com/user-attachments/assets/d03d3a7a-8dc4-45db-b5a1-d5b1d55efbb0" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/f25aeebc-66e7-42b1-8a43-592eca2d6436" />

<img width="934" height="510" alt="image" src="https://github.com/user-attachments/assets/782802f3-6511-41e1-a29d-f2ee4ca7345e" />

<img width="932" height="510" alt="image" src="https://github.com/user-attachments/assets/e5f3b1a3-2f1c-4a12-9a3e-2e95bae99106" />

<img width="933" height="512" alt="image" src="https://github.com/user-attachments/assets/b422ecb8-cd60-45b5-89ed-2a9993872bcd" />

<img width="934" height="511" alt="image" src="https://github.com/user-attachments/assets/b15f22b3-f1f9-47b0-aed4-d63f09dc1c0b" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/b5558360-d885-4708-9db2-e39838a6ccf0" />

<img width="933" height="513" alt="image" src="https://github.com/user-attachments/assets/9abeeef8-73d2-41ff-8a00-6e9ed31aa874" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/c10cc022-4134-4671-b876-d4329eefbf52" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/1e938d02-507c-4305-9bb7-45776c64c5e3" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/5d4228a1-6aaa-44c5-b163-8cd9d0f65ad3" />
