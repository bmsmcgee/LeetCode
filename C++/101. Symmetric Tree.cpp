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
        // Function to check if a binary tree is symmetric (mirror of itself)
        bool isSymmetric(TreeNode* root) {
            queue<TreeNode*> q;  // Queue for BFS (Breadth-First Search) traversal
    
            // Push root twice (to compare the tree with itself)
            q.push(root);
            q.push(root);
    
            // BFS traversal using a queue
            while (!q.empty()) {
                TreeNode *tree1 = q.front(); // Extract first node
                q.pop();
                TreeNode *tree2 = q.front(); // Extract second node
                q.pop();
    
                // If both nodes are null, continue to the next pair
                if (tree1 == nullptr && tree2 == nullptr) {
                    continue;
                }
    
                // If only one node is null or values are different, the tree is not symmetric
                if (tree1 == nullptr || tree2 == nullptr || tree1->val != tree2->val) {
                    return false;
                }
    
                // Push corresponding nodes in the correct mirrored order
                q.push(tree1->left);
                q.push(tree2->right);
                q.push(tree1->right);
                q.push(tree2->left);
            }
    
            return true;  // If all pairs match, the tree is symmetric
        }
    };