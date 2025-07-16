# Introduction to Sliding Window

## About the Pattern

Imagine you have a tray of 10 cookies and want to find the most chocolate chips in any 3 cookies next to each other. Using a naive approach, you'd stand at each cookie and count its chocolate chips along with those of it immediate left and right neightbours to form every possible group of 3. This means repeating the counting process for each cookie, which quickly becomes inefficient as the number of cookies grows.

We can avoid this hassle by using a smarter approach. Instead of recounting the chips for each group from scratch, you start by counting the chips in the first 3 cookies. Then, as you move to the next group, you simply subtract the chips from the cookie you leave behind and add the chips from the new cookie you include.

Consider the following steps:
  1. Count the chips in the first three cookies. This is your starting total $\textemdash$ and your initial "best so far".
  2. Slide the window one cookie to the right:
     - Subtract the chips from the cookie that just slipped out of the window.
     - Add the chips from the fresh cookie that slid into view.
  3. If this new sum tops your current record, replace it with the initial "best so far".
  4. Repeat the above steps for each group of three cookies, all the way to the last one.

By updating the total in constant time with each slide, you find the group of neighbouring cookies with maximum chocolate chips without ever recounting the entire window $\textemdash$ a perfect illustration of the sliding-window technique.

The **sliding window** pattern is a technique for efficiently processing sequential data, such as arrays and strings. It involves maintaining a dynamic window that slides across the data, allowing you to examine a fixed portion at a time. Instead of repeatedly scanning the entire dataset, this approach adjusts the window's boundaries as needed to track relevant elements. It is especially useful for solving problems involving contiguous subarrays or substrings, such as finding the maximum sum of a subarray or detecting repeated patterns in a string. This pattern can be viewed as a variation of the two-pointer approach, where the pointers define the window's start and end.

Depending on the problem, the sliding window can be of a fixed size or dynamic:
  - The _fixed-size_ window is used when the window size is _given_ or _constant_. For example, find the largest sum of any three consecutive numbers.
  - The _dynamic window_ is used when the window size _changes_ based on conditions. For example, find the smallest subarray whose sum exceeds a target.

### How is the Sliding Window Implemented?

The sliding window technique uses _two pointers_ representing the window's boundaries. These pointers move through an array or a string to exmine a portion of the data at a time. The window is then updated by _adding_ new elements and _removing_ old ones as the pointers move.

<img width="556" height="189" alt="image" src="https://github.com/user-attachments/assets/e758a7ca-3350-47ae-9beb-cce5cf932893" />

In a fixed-size window, both pointers move together, keeping the window size constant. For example, if you need to find the largest sum of three consecutive numbers, the window size stays at three while sliding across the array.

In a dynamic window, the window size can grow or shrink based on a condition. One pointer (usually the right one) expands the window, while the other (left) contracts it when the condition is met, like finding the smallest subarray with a sume greater than a target. This two pointer strategy allows the sliding window to process data in a _linear time_, making it a powerful tool for problems involving continuous data sections.

### How does the Sliding Window Technique Reduce Time Complexity?

We have learned that the sliding window helps process sequential data like arrays or strings efficiently. This is the case because:
  - **Avoids nested loops:** Without a sliding window, many problems require checking all subarrays using two or more loops, leading to $O(n^{2})$ time complexity or more. The sliding window allows us to update the window by adjusting pointers, reducing the complexity of traversing and processing the entire array to linear $O(n)$.
  - **Reuse computation:** Instead of recalculating the values for each window from scratch, the sliding window approach reuses previous calculations by adding new elements and removing old ones. In the example we discussed above, where we find the most chocolate chips in any 3 cookies, we only update the sum by adding the next cookie and removing the leftmost one.

## Does Your Problem Match this Pattern?

Yes, if all of these conditions are fulfilled:
  - **Contiguous data:** The input data is stored ina contiguous manner, such as an array or string.
  - **Processing subsets of elements:** The problem requires repeated computations on a contiguous subset of data (a subarray or a substring), such that the window moves across the input array from one end to the other. The size of the window may be fixed or variable, depending on the requirements of the problem.
  - **Efficient computation time complexity:** The computations performed ecvery time the window moves take constant or very small time.
