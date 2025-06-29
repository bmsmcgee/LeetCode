#include <iostream>
#include <vector>
#include "EduBinaryTree.cpp"
#include "EduTreeNode.h"

using namespace std;

// Simple pretty print for binary tree (sideways)
void display_tree(EduTreeNode* root, int space = 0, int indent = 6) {
    if (!root) return;
    space += indent;
    display_tree(root->right, space, indent);
    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    display_tree(root->left, space, indent);
}

// Function to find the lowest common ancestor (LCA) of two nodes in a binary tree
// where each node has a parent pointer.
// This approach is similar to finding the intersection point of two linked lists.
EduTreeNode* LowestCommonAncestor(EduTreeNode* p, EduTreeNode* q) {
    EduTreeNode* ptr1 = p; // Start from node p
    EduTreeNode* ptr2 = q; // Start from node q

    // Traverse upwards from both nodes. When a pointer reaches the root (nullptr),
    // redirect it to the other node. This way, both pointers traverse equal number of steps.
    while (ptr1 != ptr2) {
        // If ptr1 reaches the root, redirect to q; otherwise, move up to parent
        ptr1 = ptr1 ? ptr1->parent : q;
        // If ptr2 reaches the root, redirect to p; otherwise, move up to parent
        ptr2 = ptr2 ? ptr2->parent : p;
    }
    // When ptr1 == ptr2, we've found the LCA (or both are nullptr if no common ancestor)
    return ptr1;
}

// Driver code
int main() {
    vector<vector<int>> input_trees = {
        {100, 50, 200, 25, 75, 350},
        {100, 200, 75, 50, 25, 350},
        {350, 100, 75, 50, 200, 25},
        {100, 50, 200, 25, 75, 350},
        {25, 50, 75, 100, 200, 350}
    };
    vector<vector<int>> input_nodes = {
        {25, 75},
        {50, 350},
        {100, 200},
        {50, 25},
        {350, 200}
    };

    for (int i = 0; i < input_trees.size(); i++) {
        EduBinaryTree tree(input_trees[i]);
        cout << (i + 1) << ".\tBinary tree:" << endl;
        display_tree(tree.getRoot());
        cout << "\n\tp = " << input_nodes[i][0] << endl;
        cout << "\tq = " << input_nodes[i][1] << endl;

        EduTreeNode* p = tree.find(input_nodes[i][0]);
        EduTreeNode* q = tree.find(input_nodes[i][1]);

        EduTreeNode* lca = LowestCommonAncestor(p, q);
        if (lca)
            cout << "\n\tLowest common ancestor: " << lca->data << endl;
        else
            cout << "\n\tLowest common ancestor: nullptr" << endl;
        cout << string(100, '-') << endl;
    }

    return 0;
}