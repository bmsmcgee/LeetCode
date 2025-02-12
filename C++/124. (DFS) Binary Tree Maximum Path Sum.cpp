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
        int maxSum = INT_MIN;  // Global variable to store the maximum path sum
    
        // Helper function to compute the maximum gain for each subtree
        int maxGain(TreeNode* root) {
            if (!root) {
                return 0;  // If the node is null, return 0 (doesn't contribute to path sum)
            }
    
            // Recursively find the maximum gain from the left and right subtrees
            // If the gain is negative, we discard it by taking max(0, left/right)
            int left = max(maxGain(root->left), 0);
            int right = max(maxGain(root->right), 0);
    
            // Compute the maximum path sum passing through the current node
            int newPrice = root->val + left + right;
    
            // Update the global maxSum if the new path sum is greater
            maxSum = max(maxSum, newPrice);
    
            // Return the maximum path sum **including the current node**
            // But only one of its subtrees (either left or right) can be included in the path
            return root->val + max(left, right);
        }
    
        // Main function to find the maximum path sum in the tree
        int maxPathSum(TreeNode* root) {
            maxGain(root);  // Start recursion to compute max path sum
            return maxSum;  // Return the maximum path sum found
        }
    };