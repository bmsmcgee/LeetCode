class Solution {
    public:
        // Function to rotate an NxN matrix by 90 degrees clockwise
        void rotate(vector<vector<int>>& matrix) {
            int row = matrix.size();   // Number of rows (also number of columns for an NxN matrix)
            int column = matrix[0].size();  // Number of columns (assumes square matrix)
    
            // Step 1: Transpose the matrix (convert rows to columns and vice versa)
            for (int i = 0; i < row; i++) {
                for (int j = i + 1; j < column; j++) {
                    swap(matrix[i][j], matrix[j][i]);  // Swap elements symmetrically across the diagonal
                }
            }
    
            // Step 2: Reverse each row to get the 90-degree rotated matrix
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column / 2; j++) {
                    swap(matrix[i][j], matrix[i][column - 1 - j]);  // Swap elements from left to right
                }
            }
        }
    };