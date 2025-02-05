class Solution {
public:
    // Function to find the maximum area of water that can be contained
    int maxArea(vector<int>& height) {
        int maxArea = 0;  // Variable to store the maximum area found
        int left = 0;  // Left pointer starting at the beginning of the array
        int right = height.size() - 1;  // Right pointer starting at the end of the array

        // Iterate while left pointer is before the right pointer
        while (left < right) {
            int width = right - left;  // Calculate the width between the two bars

            // Calculate the area using the smaller height of the two bars
            maxArea = max(maxArea, min(height[left], height[right]) * width);

            // Move the pointer pointing to the shorter height to try and find a taller one
            if (height[left] <= height[right]) {
                left++;  // Move the left pointer to the right
            } else {
                right--;  // Move the right pointer to the left
            }
        }

        return maxArea;  // Return the maximum area found
    }
};