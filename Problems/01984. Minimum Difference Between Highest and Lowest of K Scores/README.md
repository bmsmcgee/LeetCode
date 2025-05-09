# 1984. Minimum Difference Between Highest and Lowest of K Scores

## Problem

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the `ith` student. You are also given an integer `k`.

Pick the scores of any `k` students from the array so that the **difference** between the **highest** and the **lowest** of the `k` scores is **minimized**.

*Return the **minimum** possible difference*.

#### Example 1:

> Input: `nums = [90], k = 1`
> Output: `0`
> Explanation: `There is one way to pick score(s) of one student:`
> ` - [`**`90`**`]. The difference between the highest and lowest score is 90 - 90 = 0`
> `The minimum possible difference is 0.`

#### Example 2:

> Input: `nums: [9, 4, 1, 7], k = 2`
> 
> Output: `2`
> 
> Explanation: `There are six ways to pick score(s) of two students:`
> 
> `- 9 & 4. The difference between the highest and lowest score is 9 - 4 = 5.`
> 
> `- 9 & 1. The difference between the highest and lowest score is 9 - 1 = 8.`
> 
> `- 9 & 7. The difference between the highest and lowest score is 9 - 7 = 2.`
> 
> `- 4 & 1. The difference between the highest and lowest score is 4 - 1 = 3.`
> 
> `- 4 & 7. The difference between the highest and lowest score is 7 - 4 = 3.`
> 
> `- 1 & 7. The difference between the highest and lowest score is 7 - 1 = 6.`
> 
> `The minimum possible difference is 2.`

#### Constraints:
 - `1 <= k <= nums.length <= 1000`
 - `0 <= nums[i] <= 10000`

## Guide

### Step 1: Recognize the Problem

Find the **minimum possible difference** among **k numbers** chosen from `nums`. The key operation here is:

>`max(selected_k) - min(selected_k)`

Want the difference to be **as small as possible**.

### Step 2: Reframe Problem

Instead of checking all possible combinations, realize:
 - The **difference between max and min** is minimized when the values are **close together**.
 - Therefore, **sorting** is required. Once sorted, nearby values are more likely to form the optimal group of size `k`.

### Step 3: Sort Array

Sorting transforms `nums` into a sequence where similar values are by each other.

Example:
 - Original: `[9, 4, 1, 7]`
 - Sorted: `[1, 4, 7, 9]`

This lets us find the best group of `k` contiguous elements directly, since any such group is **guarenteed** to have its **min/max** close to each other.

### Step 4: Use Sliding Window of Size `k`

After Sorting:
 - Iterate through the array using a sliding window of length `k`
 - For each windoe of size `k`, calculate:
    >    `difference - nums[i + k - 1] - nums[i]`

This will give the **max-min difference** of the current `k-element` subarray.

Track the **minimum difference** encountered.
 - Since the array is sorted, each window fives `min = nums[i]` and `max = nums[i + k - 1]`, and all other values fall between.

### Step 5: Return the Minimum Difference

After the sliding window completes, all possible groups of `k` adjacent elements in the sorted list have been considered, where the one with the smallest difference is the answer.

