class Solution {
    public:
        // Function to find all unique triplets in the array that sum to zero
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result; // Stores the final list of triplets
    
            // Sort the input array to enable two-pointer approach and avoid duplicates
            sort(nums.begin(), nums.end());
    
            // Iterate through the array, selecting each number as a potential first element of a triplet
            for (int i = 0; i < nums.size(); i++) {
                // Skip duplicate elements to avoid redundant triplets
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue; // Ensures only unique triplets are considered
                }
    
                int j = i + 1;            // Second pointer starts just after 'i'
                int k = nums.size() - 1;  // Third pointer starts at the end of the array
    
                // Two-pointer approach to find pairs that sum with nums[i] to zero
                while (j < k) {
                    int total = nums[i] + nums[j] + nums[k]; // Calculate the sum of three numbers
    
                    if (total > 0) {
                        k--; // If sum is too large, move right pointer left to reduce sum
                    } else if (total < 0) {
                        j++; // If sum is too small, move left pointer right to increase sum
                    } else {
                        // Found a valid triplet
                        result.push_back({nums[i], nums[j], nums[k]});
                        j++; // Move left pointer to avoid using the same number
    
                        // Skip duplicate elements to avoid duplicate triplets
                        while (nums[j] == nums[j - 1] && j < k) {
                            j++;
                        }
                    }
                }
            }
    
            return result; // Return all unique triplets found
        }
    };