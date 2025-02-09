/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
    public:
        // Function to return zigzag level order traversal of a binary tree
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;  // Stores the final zigzag level order traversal
            if (!root) {
                return result;  // Edge case: If tree is empty, return an empty vector
            }
    
            deque<TreeNode*> nodeQueue;  // Queue for BFS traversal using double-ended queue (deque)
            nodeQueue.push_back(root);  // Start with the root node
            nodeQueue.push_back(nullptr);  // Use `nullptr` as a level separator
    
            deque<int> treeLevel;  // Stores nodes at the current level in zigzag order
    
            bool orderLeft = true;  // Flag to track the order of insertion (left-to-right or right-to-left)
    
            // Perform level order traversal with zigzag ordering
            while (!nodeQueue.empty()) {
                TreeNode *temp = nodeQueue.front();  // Get the front node from the queue
                nodeQueue.pop_front();
    
                if (temp != nullptr) {
                    // Insert normally (left to right) or in reverse (right to left)
                    if (orderLeft) {
                        treeLevel.push_back(temp->val);  // Append at the end (left-to-right)
                    } else {
                        treeLevel.push_front(temp->val);  // Insert at the front (right-to-left)
                    }
    
                    // Push child nodes into the queue
                    if (temp->left) {
                        nodeQueue.push_back(temp->left);
                    }
                    if (temp->right) {
                        nodeQueue.push_back(temp->right);
                    }
                } else {
                    // End of the current level, add the values to the result
                    result.push_back(vector<int>(treeLevel.begin(), treeLevel.end()));
    
                    treeLevel.clear();  // Clear the deque for the next level
    
                    // If there are still nodes left in the queue, push a new `nullptr` separator
                    if (!nodeQueue.empty()) {
                        nodeQueue.push_back(nullptr);
                    }
    
                    // Toggle the order for the next level
                    orderLeft = !orderLeft;
                }
            }
    
            return result;  // Return the zigzag level order traversal
        }
    };