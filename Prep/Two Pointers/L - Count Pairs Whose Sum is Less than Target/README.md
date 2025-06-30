
# Count Pairs Whose Sum is Less than Target

## Statement

You are given a 0-indexed integer array, `nums`, of length $n$, and an integer `target`. Your task is to determine the number of distinct pairs of indexes $(i,j)$ such that:
 - $0 \le i \lt j \lt n$ (i.e., $i$ comes before $j$ in the array)
 - The sum of the elements of the indexes $(i,j)$, (i.e., nums[ $i$ ] $+$ nums[ $j$ ]), is strictly less than the `target`.

## Approach

1. Sort the input array, `nums`, in an ascending order.
2. Initialize a variable `count` to $0$ to keep track of the total number of valid paris. Also, initialize two pointers, `low` and `high`, with `low` at the beginning of the array and `high` at the end.
3. Use the pointers to traverse the array until `low < high`, and check the sum of `nums[low] + nums[high]`:
   - If the sum is less than the `target`, all `low` and `high` (inclusive of `high`) pairs are valid because the array is sorted. Add `high - low` to `count`. Increment `low` to explore additional valid pairs with a larger first element.
   - Otherwise, decrement `high` to reduce the sum.
4. Once the pointers meet or cross, the iteration ends.
5. Return the value of `count` as the total number of valid pairs.

## Visual

![image](https://github.com/user-attachments/assets/514833f9-5079-440b-92da-a0c0ebb9b50a)

![image](https://github.com/user-attachments/assets/3dbca4c1-1139-4269-b2cc-dbd5a2c71809)

![image](https://github.com/user-attachments/assets/57bec8f7-75f1-4f97-a183-c22dca029874)

![image](https://github.com/user-attachments/assets/96a67b6e-d4e9-4a4e-83fd-93b1695a9128)

![image](https://github.com/user-attachments/assets/39fda862-58f0-4d80-9663-6965e97f8310)

![image](https://github.com/user-attachments/assets/bc244305-9458-40ee-a756-efa467c6629d)

![image](https://github.com/user-attachments/assets/88295873-467d-4a82-a319-ee2b1032a17f)

![image](https://github.com/user-attachments/assets/2d1c72b0-d52f-407c-b90d-2c2133e02208)

![image](https://github.com/user-attachments/assets/5ba7878e-d3c6-4600-8e10-585806718315)

![image](https://github.com/user-attachments/assets/58e45ed3-ef77-4233-bb73-95f28bc5033b)

## Time Complexity

The time complexity analysis is as follows:
 - **Sorting the array:** The array is sorted at the beginning, which takes $O(n\cdot log(n))$, where $n$ is the number of elements in the array.
 - **Two pointer traversal:** The algorithm uses a single loop for the two pointer approach, which runs in $O(n)$.

Adding the complexities gives an overall time complexity of $O(n\cdot log(n))$.

## Space Complexity

The algorithm's space complexity is $O(1)$ because it only uses a constant amount of extra space for the pointers and the `count` variable.
