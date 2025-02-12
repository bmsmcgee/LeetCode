#include <vector>
using namespace std;

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify operations
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        // Merge the two lists
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // Attach the remaining nodes from the non-empty list
        cur->next = l1 ? l1 : l2;

        // Return the merged list, skipping the dummy node
        return dummy->next;
    }

    // Function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Perform pairwise merging of lists until only one list remains
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            // Merge lists in pairs
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }

            // Update the lists with the merged lists
            lists = mergedLists;
        }

        // Return the final merged list
        return lists[0];
    }
};