#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count pairs with sum less than the target
int CountPairs(vector<int>& nums, int target) {
    // Sort the array to enable the two-pointer approach
    sort(nums.begin(), nums.end());
    int count = 0; // Initialize the count of valid pairs
    int low = 0, high = nums.size() - 1; // Initialize two pointers

    // Loop until the two pointers meet
    while (low < high) {
        // Check if the sum of the current pair is less than the target
        if (nums[low] + nums[high] < target) {
            // All pairs between low and high are valid
            count += (high - low);
            // Move the low pointer to explore more pairs
            low++;
        } else {
            // If the sum is not less than the target, move the high pointer
            high--;
        }
    }

    // Return the total count of pairs
    return count;
}

int main() {
    vector<pair<vector<int>, int>> test_cases = {
        {{10, 1, 6, 2, 3, 8}, 9},
        {{1, 3, 5, 7}, 8},
        {{1, 2, 3, 6}, 6},
        {{2, 4, 6, 8, 10}, 12},
        {{5, 1, 9, 2}, 10}
    };

    for (size_t i = 0; i < test_cases.size(); ++i) {
        vector<int> nums = test_cases[i].first;
        int target = test_cases[i].second;

        cout << i + 1 << "\tnums: [";
        for (size_t j = 0; j < nums.size(); ++j) {
            cout << nums[j];
            if (j < nums.size() - 1) cout << ", ";
        }
        cout << "]\n\ttarget: " << target << endl;

        int result = CountPairs(nums, target);
        cout << "\n\tNumber of valid pairs: " << result << endl;
        cout << string(100, '-') << endl;
    }

    return 0;
}
