class Solution {
    public:
        // Function to find the k-th largest element in an array
        int findKthLargest(std::vector<int>& nums, int k) {
            // Step 1: Create a min-heap of size k using the first k elements
            priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
    
            // Step 2: Iterate through the remaining elements
            for (int i = k; i < nums.size(); i++) {
                // If the current element is greater than the smallest element in the heap
                if (nums[i] > min_heap.top()) {
                    min_heap.pop();       // Remove the smallest element
                    min_heap.push(nums[i]); // Insert the new element
                }
            }
    
            // Step 3: Return the top of the min-heap, which is the k-th largest element
            return min_heap.top();
        }
    };