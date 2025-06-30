# Introduction to Fast and Slow Pointers

## About the Pattern

Similar to the two pointers pattern the **fast and slow pointers** pattern uses two pointers to traverse an iterable data structure, but at different speeds, often to identify cycles or find a specific target. The speeds of the pointers can be adjusted according to the problem statement. The **two pointers** pattern focuses on comparing data values, whereas the fast and slow pointers method is typically used to analyze the structure or properties of the data.

The key idea is that the pointers start at the same location and the start movinf at different speeds. The _slow_ pointer moves one step at a time, while the _fast_ pointer moves by two steps. Die to the different speeds of the pointers, this pattern is also commonly known as the **Hare and Tortoise** algorithm, where the _Hare_ is the fast pointer while the _Tortoise_ is the slow pointer. If a cycle exists, the two pointers will eventually meet during traversal. This approach enables the algorithm to detect specific properties within the data structure, such as cycles, midpoints, or intersections.

To visualize this, imagine two runners on a circular track starting at the same point. With different running speeds, the faster runner will eventually overtake the slower one, illustrating how this method works to detect cycles.

Here is a basic pseudocode template that can be adapted to fit specific needs:

```
FUNCTION fastAndSlow(dataStructure) 
  // Initialize pointers (or indices)
  fast = dataStructure.start  // or 0 if the data structure is an array
  slow = dataStructure.start  // or 0 if the data structure is an array

  WHILE fast != null AND fas.next != null:
  // For arrays: WHILE fast < dataStructure.length AND (fast + 1) < dataStructure.length:

    slow = slow.next
    // For arrays: slow = slow + 1

    fast = fast.next.next
    // For arrays: fast = fast + 2

    IF fast != null AND someCondition(fast, slow):
    // For arrays: use someCondition(dataStructure[fast], dataStructure[slow]) if needed
      handleCondition(fast, slow)
      BREAK

  // Process the result
  processResult(slow)
  // For arrays: processResult(slow) might process dataStructure[slow]

```

In the template above, the `fast` pointer moves at twice the speed of the `slow` pointer, allowing efficient traversal and detection of specific conditions. The `fast` pointer advances two steps at a time(`fast.next.next` for linked list or `fast + 2` for arrays). while the `slow` pointer moves one step at a time (`slow.next` or `slow + 1`). The loop continues until the `fast` pointer reaches the end of the structure or a condition (`someCondition`) is met, triggering `handleCondition`. Finally, the result is processed using the `slow` pointer, which often points to a meaningful position, such as the middle of the structure or the start of a cycle.

## Does your Problem Match this Pattern?

Yes, if the following condition is fulfilled:
 - **Linear Data Structure:** The input data can be traversed in a linear fashion, such as an array, linked list, or string.

In addition, if either of these conditions is fulfilled:
 - **Cycle or Intersection Detection:** The problem involves detecting a loop within a linked list or an array or involves finding an intersection between two linked lists or arrays.
 - **Find the Starting Element of the Second Quantile:** This means identifying the element where the second part of a divided dataset begins - like the second hald, second third (tertile), or second quarter (quartile). For example, the task might ask you to find the middle element of an array or a linked list, which marks the start of the second half.
