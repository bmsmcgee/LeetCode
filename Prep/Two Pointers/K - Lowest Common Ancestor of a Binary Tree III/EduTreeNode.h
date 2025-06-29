class EduTreeNode {
public:
    int data;
    EduTreeNode* left;
    EduTreeNode* right;
    EduTreeNode* parent;

    EduTreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};