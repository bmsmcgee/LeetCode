class Solution {
public:
    // Function to find two numbers in the array that add up to the target
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // Hash map to store the number and its index

        // Iterate through the array
        for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i]; // Calculate the complement needed to reach the target

            // Check if the complement exists in the hash map
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i}; // Return the indices if found
            }

            // Store the current number and its index in the hash map
            hash[nums[i]] = i;
        }

        // Return an empty vector if no solution is found (shouldn't happen based on problem constraints)
        return {};
    }
};