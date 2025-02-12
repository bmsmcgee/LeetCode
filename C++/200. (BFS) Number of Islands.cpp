#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();   // Get the number of rows
        if (nr == 0) return 0;  // Edge case: If the grid is empty, return 0 islands
        int nc = grid[0].size(); // Get the number of columns
        
        int num_islands = 0;  // Counter to keep track of the number of islands
        
        // Direction vectors to move Up, Down, Left, and Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Iterate over every cell in the grid
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                // If we find a land cell ('1'), it means we've found a new island
                if (grid[r][c] == '1') {
                    ++num_islands;  // Increase island count
                    queue<pair<int, int>> q;  // Create a queue for BFS
                    q.push({r, c});  // Start BFS from this land cell
                    grid[r][c] = '0';  // Mark the cell as visited by setting it to '0'
                    
                    // Perform BFS
                    while (!q.empty()) {
                        auto [row, col] = q.front();  // Get the front element from the queue
                        q.pop();  // Remove the processed cell from the queue
                        
                        // Explore all 4 possible directions
                        for (auto [dr, dc] : directions) {
                            int newRow = row + dr;  // Compute new row index
                            int newCol = col + dc;  // Compute new column index
                            
                            // Check if the new position is within grid boundaries and is land ('1')
                            if (newRow >= 0 && newRow < nr && newCol >= 0 && newCol < nc && grid[newRow][newCol] == '1') {
                                q.push({newRow, newCol});  // Add the new land cell to the queue
                                grid[newRow][newCol] = '0';  // Mark it as visited to prevent re-processing
                            }
                        }
                    }
                }
            }
        }
        
        return num_islands;  // Return the total number of islands found
    }
};