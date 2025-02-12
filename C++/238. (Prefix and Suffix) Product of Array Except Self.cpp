class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int length = nums.size();
            vector<int> res(length, 1); // Initialize result array with 1
    
            // Step 1: Compute left products and store them directly in res
            int leftProduct = 1;
            for (int i = 0; i < length; i++) {
                res[i] = leftProduct;
                leftProduct *= nums[i]; // Update leftProduct for the next iteration
            }
    
            // Step 2: Compute right products and multiply with values in res
            int rightProduct = 1;
            for (int i = length - 1; i >= 0; i--) {
                res[i] *= rightProduct; // Multiply by right product
                rightProduct *= nums[i]; // Update rightProduct for the next iteration
            }
    
            return res;
        }
    };