class Solution {
    public:
        int minimumDifference(vector<int>& nums, int k) {
            cout << "Original nums: ";
            for (int n : nums) {
                cout << n << " ";
            }
            cout << "\nValue of k: " << k << endl << endl;
    
            // Edge Case
            if (k == 1) {
                cout << "Since k = 1, the min difference is 0." << endl;
                return 0;
            }
    
            // Sort Array
            sort(nums.begin(), nums.end());
    
            cout << "Sorted: ";
            for (int n : nums) {
                cout << n << " ";
            }
            cout << endl << endl;
    
            // Initialize minDiff
            int minDiff = INT_MAX;
    
            // Use Sliding Window
            for (int i = 0; i <= nums.size() - k; ++i) {
                int windowStart = nums[i];
                int windowEnd = nums[i + k - 1];
                int diff = windowEnd - windowStart;
    
                cout << "Window [" << i << " to " << i + k - 1 << "] -> (" << windowEnd << " - " << windowStart << ") = " << diff << endl;
    
                if (diff < minDiff) {
                    cout << "--> New minDiff found: " << diff << endl << endl;
                    minDiff = diff;
                }
            }
    
            // Return result
            cout << endl << "Final minimum difference: " << minDiff << endl;
            return minDiff;
    
        }
    };