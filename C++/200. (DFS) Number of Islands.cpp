class Solution {
    private:
        // Depth-First Search (DFS) function to explore the island
        void dfs(vector<vector<char>>& grid, int r, int c) {
            int nr = grid.size();   // Number of rows in the grid
            int nc = grid[0].size(); // Number of columns in the grid
    
            // Mark the current land cell as '0' (visited) to prevent re-visiting
            grid[r][c] = '0';
    
            // Explore the 4 possible directions (up, down, left, right)
            if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c); // Move up
            if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c); // Move down
            if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1); // Move left
            if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1); // Move right
        }
    
    public:
        // Function to count the number of islands in the given grid
        int numIslands(vector<vector<char>>& grid) {
            int nr = grid.size(); // Number of rows
            if (nr == 0) return 0; // Edge case: If grid is empty, return 0 islands
            int nc = grid[0].size(); // Number of columns
    
            int num_islands = 0; // Variable to store the total number of islands
    
            // Iterate through the entire grid
            for (int r = 0; r < nr; ++r) {
                for (int c = 0; c < nc; ++c) {
                    // If we find land ('1'), start a DFS to mark the entire island
                    if (grid[r][c] == '1') {
                        ++num_islands; // Found a new island, increment count
                        dfs(grid, r, c); // Perform DFS to mark all connected land
                    }
                }
            }
    
            return num_islands; // Return the total count of islands
        }
    };