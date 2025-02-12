class Solution {
    public:
        // Function to find the missing number in an array containing numbers from 0 to n
        int missingNumber(vector<int>& nums) {
            int res = nums.size();  // Initialize result with the size of the array (n)
    
            // Iterate through the array and compute the missing number
            for (int i = 0; i < nums.size(); i++) {
                res += i - nums[i];  // Adjust result by adding the index and subtracting the value at that index
            }
    
            return res;  // Return the missing number
        }
    };