class Solution {
    public:
        // Function to compute trapped rainwater
        int trap(vector<int>& height) {
            int left = 0, right = height.size() - 1; // Two pointers: left and right
            int res = 0; // Stores total trapped water
            int leftMax = 0, rightMax = 0; // Track max heights from left and right
    
            // Iterate while left pointer is to the left of right pointer
            while (left < right) {
                // If left bar is shorter, process the left side
                if (height[left] < height[right]) {
                    // Update leftMax or compute trapped water at `left`
                    if (height[left] >= leftMax) {
                        leftMax = height[left];  // Update leftMax to current height
                    } else {
                        res += (leftMax - height[left]); // Water trapped is (leftMax - current height)
                    }
                    left++; // Move left pointer right
                }
                // Else process the right side
                else {
                    // Update rightMax or compute trapped water at `right`
                    if (height[right] >= rightMax) {
                        rightMax = height[right];  // Update rightMax to current height
                    } else {
                        res += (rightMax - height[right]); // Water trapped is (rightMax - current height)
                    }
                    right--; // Move right pointer left
                }
            }
            return res; // Return the total trapped water
        }
    };