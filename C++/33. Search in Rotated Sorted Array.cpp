class Solution {
    public:
        // Standard binary search function to find target in a given range
        int binarySearch(vector<int>& nums, int leftBoundary, int rightBoundary, int target) {
            int left = leftBoundary;  // Left boundary of search space
            int right = rightBoundary; // Right boundary of search space
    
            while (left <= right) {
                int mid = (left + right) / 2; // Calculate mid index
    
                // If target is found, return index
                if (nums[mid] == target) {
                    return mid;
                } 
                // If target is smaller, search in the left half
                else if (nums[mid] > target) {
                    right = mid - 1;
                } 
                // If target is larger, search in the right half
                else {
                    left = mid + 1;
                }
            }
            return -1; // If not found, return -1
        }
    
        // Function to search for a target in a rotated sorted array
        int search(vector<int>& nums, int target) {
            int n = nums.size();  // Get size of the array
            int left = 0;
            int right = n - 1;
    
            // Step 1: Find the index of the smallest element (pivot)
            while (left <= right) {
                int mid = (left + right) / 2; // Compute mid index
    
                // If mid element is greater than the last element, search in the right half
                if (nums[mid] > nums[n - 1]) {
                    left = mid + 1;
                } 
                // Otherwise, search in the left half
                else {
                    right = mid - 1;
                }
            }
    
            // Step 2: `left` now represents the index of the smallest element (pivot)
            int answer = binarySearch(nums, 0, left - 1, target); // Search in left half
            if (answer != -1) {
                return answer; // If found, return index
            }
    
            // Step 3: Search in the right half if not found in the left half
            return binarySearch(nums, left, n - 1, target);
        }
    };