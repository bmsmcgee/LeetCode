# Count Subarrays With Fixed Bounds

## Statement

Given an integer arrays, `nums`, and two integers `minK` and `maxK`, return the number of fixed-bound subarrays.
A subarray in `nums` is called a **fixed-bound** subarray if it satisfies the following conditions:
  1. The smallest value in the subarray equals `minK`.
  2. The largest value in the subarray equals `maxK`.

> **Note:** A **subarray** is a contiguous sequence of elements within an array.

## Approach

1. Initialize the variables:
   - `min_pos`, `max_pos`, and `left_bound` to `-1` to indicate invalid positions initially.
   - `count` to `0` to keep track of the total number of valid subarrrays

2. Iterate through each element in the arrays `nums` using an index `i`:
    - If `nums[i]` is outside the range `[minK, maxK]`, set `left_bound` to `i` and reset `min_pos` and `max_pos` to `-1`. This invalidates any subarray ending at or beyond this position.
    - If `nums[i]` equals `minK`, update `min_pos` to the current index `i`.
    - If `nums[i]` equals `maxK`, update `max_pos` to the current index `i`.
    - For each position `i`, if both `min_pos` and `max_pos` are valid (i.e., not `-1`), calculate the number of valid subarrays ending at `i`:
      - The earliest valid starting point for such a subarray is `min(min_pos, max_pos) + 1`.
      - Subtract `left_bound` from this value to get the number of valid subarrays.
      - Accumulate this count into `count`.
3. Return `count` after finishing the iteration.

## Visual

![image](https://github.com/user-attachments/assets/65092373-3cfb-41ff-bf0a-b1ea807e1fad)

![image](https://github.com/user-attachments/assets/57e6539e-ab89-4641-838e-729b107952da)

![image](https://github.com/user-attachments/assets/62438999-93af-48ba-8419-0141fb115fec)

![image](https://github.com/user-attachments/assets/e30dd258-b255-4cc5-aa99-abcd208a52df)

![image](https://github.com/user-attachments/assets/457c8c9d-92a6-4210-a9ce-e3733b75b7a7)

![image](https://github.com/user-attachments/assets/c0516d79-dd3a-4380-b467-f73bee74b9ba)

![image](https://github.com/user-attachments/assets/d9795938-8f89-4163-a7af-0643fc1a64d2)

![image](https://github.com/user-attachments/assets/9df80fb4-f54b-403c-a660-1ae0090ea420)

![image](https://github.com/user-attachments/assets/168bcf05-6523-4b31-bdd1-887739155563)

![image](https://github.com/user-attachments/assets/7fe76a79-1016-4daa-b9de-b620d7a2249e)

![image](https://github.com/user-attachments/assets/31e7fd75-9d4d-4194-a42e-54f67576fb91)

![image](https://github.com/user-attachments/assets/4926ba6f-7295-431e-93e4-5b46c8760ef8)

## Time Complexity

Traverse `nums` exactly once, performing constant time operations at each step. Therefore, the overall time complexity of this solution is $O(n)$, where $n$ is the length of `nums`.

## Space Complexity

Using a fixed number of extra variables and no additional arrays or data structures. Therefore, the space complexity is $O(1)$.
