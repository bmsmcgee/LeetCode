#include <iostream>
#include <vector>
#include <cmath>

// A function to calculate the next step
int NextStep(int pointer, int value, int size) {
    int result = (pointer + value) % size;
    if (result < 0) {
        result += size;
    }
    return result;
}

// A function to detect a cycle doesn't exist
bool IsNotCycle(std::vector<int>& nums, bool prev_direction, int pointer) {
    int size = nums.size();
    // Set current direction to true if current element is positive, set false otherwise.
    bool curr_direction = nums[pointer] >= 0;
    // If current direction and previous direction are different or moving a pointer takes back to the same value,
    // then the cycle is not possible, we return true, otherwise return false.
    if (prev_direction != curr_direction || nums[pointer] % size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularArrayLoop(std::vector<int>& nums) {
    int size = nums.size();
    // Iterate through each index of the array 'nums'.
    for (int i = 0; i < size; i++) {
        // Set slow and fast pointer at current index value.
        int slow = i, fast = i;
        // Set true in 'forward' if element is positive, set false otherwise.
        bool forward = nums[i] > 0;
        while (true) {
            // Move slow pointer to one step.
            slow = NextStep(slow, nums[slow], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, slow)) {
                break;
            }
            // First move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast)) {
                break;
            }
            // Second move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast)) {
                break;
            }
            // At any point, if fast and slow pointers meet each other,
            // it indicates that loop has been found, return true.
            if (slow == fast) {
                return true;
            }
        }
    }
    return false;
}
// Driver code
int main() {
  std::vector<std::vector<int>> input = {
           {-2, -3, -9}, 
           {-5, -4, -3, -2, -1},
           {-1, -2, -3, -4, -5},
           {2, 1, -1, -2},
           {-1, -2, -3, -4, -5, 6},
           {1, 2, -3, 3, 4, 7, 1},
           {2, 2, 2, 7, 2, -1, 2, -1, -1}
  };
  for(int i=0; i< input.size(); i++){
    std::cout << i + 1 << ".\tGiven arr: " << PrintArray(input[i]) << "\n";
    bool res = CircularArrayLoop(input[i]);
    std::cout << "\n\tFound loop: " << std::boolalpha << res << "\n";
    std::cout << std::string(100, '-') << "\n";
  }
}
