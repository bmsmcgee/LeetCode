class Solution {
    public:
        // Function to find two numbers in a sorted array that sum to a given target
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left = 0;                        // Left pointer starts at the beginning
            int right = numbers.size() - 1;      // Right pointer starts at the end
    
            // Step 1: Traverse the array using two pointers
            while (left < right) {
                int total = numbers[left] + numbers[right]; // Compute the sum of the two pointers
    
                // Step 2: If we found the target sum, return the 1-based indices
                if (total == target) {
                    return {left + 1, right + 1}; // Convert 0-based to 1-based index
                } 
                // Step 3: If sum is too large, move the right pointer left
                else if (total > target) {
                    right--; 
                } 
                // Step 4: If sum is too small, move the left pointer right
                else {
                    left++; 
                }
            }
    
            return {-1, -1}; // Return {-1, -1} if no valid pair is found
        }
    };