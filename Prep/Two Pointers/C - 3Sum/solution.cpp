#include <vector>
#include <iostream>


using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // Sort the input array in ascending order
    sort(nums.begin(), nums.end());

    // Create an empty array to store the unique triplets
    vector<vector<int>> result;

    // Store the length of the array in a variable
    int n = nums.size();

    // Iterate over the array till n - 2
    for (int i = 0; i < n - 2; ++i) {
        // If the current number is greater than 0, break the loop
        if (nums[i] > 0)
            break;

        // The current number is either the first element or not a duplicate of the previous element
        if (i == 0 || nums[i] != nums[i - 1]) {
            // Initialize two pointers
            int low = i + 1, high = n - 1;

            // Run a loop as long as low is less than high
            while (low < high) {
                // Calculate the sum of the triplet
                int sum = nums[i] + nums[low] + nums[high];

                // If the sum is less than 0, move the low pointer forward
                if (sum < 0)
                    ++low;

                // If the sum is greater than 0, move the high pointer backward
                else if (sum > 0)
                    --high;
                
                else {
                    // Add the triplet to result as this triplet sums to 0
                    result.push_back({nums[i], nums[low], nums[high]});

                    // Move both pointers to the next distinct values to avoid duplicate triplets
                    ++low;
                    --high;
                    while (low < high && nums[low] == nums[low - 1])
                        ++low;
                    while (low < high && nums[high] == nums[high + 1])
                        --high;
                }
            }
        }
    }

    // Return result, which contains all unique triplets that sum to zero
    return result;
}

// Driver code
int main() {
    vector<vector<int>> nums_arrs = {
        {-1, 0, 1, 2, -1, -4},
        {1, 2, 3, 4, 5},
        {0, 0, 0, 0},
        {-4, -1, -1, 0, 1, 2, 2},
        {-10, -7, -3, -1, 0, 3, 7, 10},
        {-3, -5, -7, -9}
    };

    for (size_t i = 0; i < nums_arrs.size(); ++i) {
        cout << i + 1 << ".\tnums: [";
        for (size_t j = 0; j < nums_arrs[i].size(); ++j) {
            cout << nums_arrs[i][j];
            if (j < nums_arrs[i].size() - 1)
                cout << ", ";
        }
        cout << "]\n";

        vector<vector<int>> triplets = threeSum(nums_arrs[i]);
        cout << "\n\tTriplets: [";
        for (size_t j = 0; j < triplets.size(); ++j) {
            cout << "[" << triplets[j][0] << ", " << triplets[j][1] << ", " << triplets[j][2] << "]";
            if (j < triplets.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
        cout << string(100, '-') << "\n";
    }

    return 0;
}