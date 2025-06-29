#include <vector>
#include <queue>

#include "EduTreeNode.h"

using namespace std;

class EduBinaryTree {
private:
    EduTreeNode* root;

    EduTreeNode* createBinaryTree(const vector<int>& nodes) {
        if (nodes.empty() || nodes[0] == 0) {
            return nullptr;
        }
        EduTreeNode* root = new EduTreeNode(nodes[0]);
        queue<EduTreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < nodes.size()) {
            EduTreeNode* curr = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != 0) {
                curr->left = new EduTreeNode(nodes[i]);
                curr->left->parent = curr;
                q.push(curr->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != 0) {
                curr->right = new EduTreeNode(nodes[i]);
                curr->right->parent = curr;
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

public:
    EduBinaryTree(const vector<int>& nodes) : root(createBinaryTree(nodes)) {}

    EduTreeNode* find(int value) {
        if (!root) {
            return nullptr;
        }
        queue<EduTreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            EduTreeNode* currentNode = q.front();
            q.pop();
            if (currentNode->data == value) {
                return currentNode;
            }
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        return nullptr;
    }

    EduTreeNode* getRoot() const {
        return root;
    }
};