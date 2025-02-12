#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0) return 0;
        int nc = grid[0].size();
        
        int num_islands = 0;
        
        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands; // Found a new island
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = '0'; // Mark as visited
                    
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        
                        // Explore all 4 directions
                        for (auto [dr, dc] : directions) {
                            int newRow = row + dr;
                            int newCol = col + dc;
                            
                            // Check if within bounds and is land ('1')
                            if (newRow >= 0 && newRow < nr && newCol >= 0 && newCol < nc && grid[newRow][newCol] == '1') {
                                q.push({newRow, newCol});
                                grid[newRow][newCol] = '0'; // Mark as visited
                            }
                        }
                    }
                }
            }
        }
        
        return num_islands;
    }
};