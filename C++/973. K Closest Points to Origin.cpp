class Solution {
    public:
        // Function to find the k closest points to the origin (0,0)
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            vector<vector<int>> result(k);  // Vector to store the final k closest points
            
            priority_queue<vector<int>> maxHeap; // Max-heap to store the k closest points
    
            // Step 1: Iterate through all points
            for (auto& p : points) {
                int x = p[0], y = p[1]; // Extract x and y coordinates
                int distance = x * x + y * y; // Compute squared Euclidean distance (no need for sqrt)
                
                // Step 2: Push the current point into the max-heap
                maxHeap.push({distance, x, y}); // Heap stores (distance, x, y) to prioritize larger distances
                
                // Step 3: Maintain only k closest points
                if (maxHeap.size() > k) {
                    maxHeap.pop(); // Remove the farthest point
                }
            }
            
            // Step 4: Extract k closest points from the max-heap
            for (int i = 0; i < k; ++i) {
                vector<int> top = maxHeap.top(); // Get the closest point
                maxHeap.pop();
                result[i] = {top[1], top[2]}; // Store only the x and y coordinates
            }
            
            return result; // Return k closest points
        }
    };