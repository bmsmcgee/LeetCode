#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;  // An empty tree is a valid BST

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;  // To track the previous node in the in-order traversal

        while (!st.empty() || cur) {
            // Traverse to the leftmost node
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            // Process the top node in the stack
            cur = st.top();
            st.pop();

            // Compare the current node's value with the previous node's value
            if (prev && cur->val <= prev->val) {
                return false;  // BST property violated
            }

            prev = cur;  // Update the previous node
            cur = cur->right;  // Move to the right subtree
        }

        return true;  // If no violations are found, the tree is a valid BST
    }
};