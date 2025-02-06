class Solution {
    public:
        // Function to find the sum of three integers closest to the target
        int threeSumClosest(vector<int>& nums, int target) {
            // Sort the array to facilitate two-pointer approach
            sort(nums.begin(), nums.end());
    
            // Initialize the closest sum to a large value (avoiding overflow)
            int closest_sum = INT_MAX / 2;  
    
            // Iterate through the array, treating each number as the first element of a triplet
            for (int i = 0; i < nums.size() - 2; ++i) {
                int left = i + 1;  // Second pointer starts just after 'i'
                int right = nums.size() - 1;  // Third pointer starts at the last index
    
                // Two-pointer approach to find the sum closest to the target
                while (left < right) {
                    int current_sum = nums[i] + nums[left] + nums[right];  // Compute current triplet sum
    
                    // If the current sum is closer to the target than the closest recorded sum, update it
                    if (abs(current_sum - target) < abs(closest_sum - target)) {
                        closest_sum = current_sum;
                    }
    
                    // Move pointers based on the sum comparison with the target
                    if (current_sum < target) {
                        ++left;  // Increase sum by moving left pointer right
                    } else if (current_sum > target) {
                        --right;  // Decrease sum by moving right pointer left
                    } else {
                        // If exactly equal to the target, return immediately as it's the best possible case
                        return current_sum;
                    }
                }
            }
    
            // Return the closest sum found
            return closest_sum;
        }
    };