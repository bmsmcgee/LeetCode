# Happy Numbers

## Statement

Write an algorithm to determine if a number $n$ is a happy number.

We use the following process to check if a given number is a happy number:
 - Starting with the given number $n$, replace the number with the sum of the squares of its digits.
 - Repeat the process until:
   - The number equals $1$, which will depict that the given number $n$ is a happy number.
   - The number enters a cycle, which will depict that the given number $n$ is not a happy number.

Return **TRUE** if $n$ is a happy number, and **FALSE** if not.

## Approach

1. Isolate the digits in number to calculate squared sum using a helper function
  - Find the last digit of the given number by taking its modulus with $10$
  - Store this in variable `digit`.
  - Get remaining digits by dividing the number by $10$.
  - Store the squared sum of `digit` in variable `totalSum`.
2. Initialize pointers:
  - `slowPointer` with the input number.
  - `fastPointer` with the sum of its digits.
3. Iterate `slowPointer` one step and `fastPointer` two steps:
  - `slowPointer = SumOfSquaredDigits(slow)`
  - `fastPointer = SumOfSquaredDigits(SumOfSquaredDigits(fastPointer))`
4. If at any point `fastPointer` becomes $1$, a Happy Number is found, return TRUE. Otherwise, if `fastPointer` equals `slowPointer`, there is a loop and return FALSE.

## Visual

![image](https://github.com/user-attachments/assets/7375d6df-da1d-4ec2-9747-6fcf02b49b20)

![image](https://github.com/user-attachments/assets/266f6c33-23b3-417f-acc8-26a962bec2d3)

![image](https://github.com/user-attachments/assets/072d586f-c6f5-4ae8-a06b-5c5262afa6a9)

![image](https://github.com/user-attachments/assets/32c210d7-dff2-497f-80fa-6cfb969f36d2)

![image](https://github.com/user-attachments/assets/88704c4d-8449-42e3-8520-bce946af6089)

![image](https://github.com/user-attachments/assets/c0c8ff1f-9cfb-4b99-8977-b4a511c2f734)

![image](https://github.com/user-attachments/assets/c28fb0a7-d8f3-4735-bb64-25c6ca83c7fa)

![image](https://github.com/user-attachments/assets/28c34e77-f532-483a-b09e-2ed3534dd8f3)

## Time Complexity

The time complexity for this algorithm is $O(log(n))$, where $n$ is the input number.

## Space Complexity

The space complexity for this algorithm is $O(1)$.
