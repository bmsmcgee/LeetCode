#include <iostream>
#include <vector>
#include <algorithm>   
#include <iomanip>   

using namespace std;

long long countSubarrays(const vector<int>$ nums, int minK, int maxK) {
  // Initialize pointers:
  // minPos      last index where minK was seen
  // maxPos      last index where maxK was seen
  // leftBound   last index where an out-of-range element was seen
  // Initialize total count of valid subarrays
  int minPos = -1;
  int maxPos = -1;
  int leftBound = -1;
  long long count = 0;

  // Iterate through the array
  for (int i = 0; i < static_cast<int>(nums.size()); i++) {
    // If the current number is out of range, reset the window
    //    - leftBound becomes the new invalid boundary
    //    - reset positions of minK and maxK
    if (nums[i] < minK || nums[i] > maxK) {
      leftBound = i;
      minPos = maxPos = -1;
    }

    // Update minPos if current number equals minK
    if (nums[i] == minK) {
      minPos = i;
    }

    // Update maxPos if current number equals maxK
    if (nums[i] == maxK) {
      maxPos = i;
    }

    // If both minK and maxK have been seen since the last
    // invalid element, calculate the number of valid
    // subarrays ending at index i.

    // Valid start indices range from (leftBound +1)
    // to min(minPos, maxPos). Each start index in this
    // range yields a valid subarray ending at i.
    if (minPos != -1 && maxPos != -1) {
      count += max(0, min(minPos, maxPos) - leftBound);
    }
  }

  // Return the total number of valid subarrays
  return count; 
}

// Driver code
int main() {
    struct TestCase {
        std::vector<int> nums;
        int minK;
        int maxK;
    };

    std::vector<TestCase> testCases = {
        {{1, 3, 5, 2, 7, 5}, 1, 5},
        {{1, 5},             1, 5},
        {{1,1,1,1,1,1,1,1,1,1}, 1, 1},         
        {{1, 2, 3, 4},       2, 5},
        {{1, 5, 1, 5, 1, 5}, 1, 5}
    };

    int idx = 1;
    for (const auto& tc : testCases) {
        std::cout << idx++ << ".\tnums = [";
        for (size_t i = 0; i < tc.nums.size(); ++i) {
            std::cout << tc.nums[i] << (i + 1 == tc.nums.size() ? "" : ", ");
        }
        std::cout << "]\n\tminK = " << tc.minK
                  << "\n\tmaxK = " << tc.maxK << '\n';

        long long result = countSubarrays(tc.nums, tc.minK, tc.maxK);
        std::cout << "\n\tOutput: " << result << "\n";
        std::cout << std::string(100, '-') << std::endl;
    }
    return 0;
}
