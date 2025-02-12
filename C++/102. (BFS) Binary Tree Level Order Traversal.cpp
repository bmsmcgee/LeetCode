class Solution {
    public:
        // Function to return level-order traversal of a binary tree
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> levels; // Stores the result
            if (!root) return levels;  // Edge case: If tree is empty, return an empty list
    
            queue<TreeNode*> q;  // Queue for BFS traversal
            q.push(root);  // Start with the root node
    
            // Perform level-order traversal
            while (!q.empty()) {
                int levelSize = q.size();  // Number of nodes at the current level
                vector<int> currentLevel;  // Store values of the current level
                
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front(); // Get the front node in the queue
                    q.pop();
                    currentLevel.push_back(node->val); // Store its value
    
                    // Push left and right children into the queue if they exist
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
    
                levels.push_back(currentLevel); // Store the level in the result
            }
    
            return levels; // Return the level-order traversal
        }
    };