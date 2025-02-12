class Solution {
    public:
        // Function to find the maximum hourglass sum in a 2D grid
        int maxSum(vector<vector<int>>& grid) {
            int maxSum = INT_MIN; // Initialize maxSum to the smallest possible value
    
            // Step 1: Iterate through all possible top-left corners of hourglasses
            for (int i = 0; i < grid.size() - 2; i++) {  // Rows (stop at row size - 2)
                for (int j = 0; j < grid[0].size() - 2; j++) {  // Columns (stop at col size - 2)
    
                    // Step 2: Compute the hourglass sum for the current position
                    int curSum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +  // Top row
                                            grid[i + 1][j + 1] +                // Middle value
                            grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]; // Bottom row
    
                    // Step 3: Update maxSum if the current sum is greater
                    maxSum = max(maxSum, curSum);
                }
            }
    
            return maxSum; // Return the maximum hourglass sum found
        }
    };