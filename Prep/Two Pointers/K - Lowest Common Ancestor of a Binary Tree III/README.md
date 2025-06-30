# Lowest Common Ancestor of a Binary Tree III

## Statement

You are given two nodes, `p` and `q`. The tawk is to return their lowest common ancestor (LCA). Both nodes have a reference to their parent node. The tree's root is not provided; you must use the parent pointers to find the nodes' common ancestor.

> **Note:** The lowest common ancestor of two nodes, `p` and `q`, is the lowest node in the binary tree, with both `p` and `q` as descendants.
>
> In a tree, a descendant of a node is any node reachable by following edges downward from that node, including the node itself.

## Approach

1. Initialize two pointers: `ptr1` starting at `p` and `ptr2` starting at `q`.

2. While `ptr1` and `ptr2` are not pointing to the same node:

   I. If `ptr1` has a parent, move `ptr1` to `ptr1->parent`; otherwise, set `ptr1 = q`.

   II.  If `ptr2` has a parent, move `ptr2` to `ptr2->parent`; otherwise, set `ptr2 = p`.

3. When `ptr1 == ptr2`, return `ptr1`. This node is the lowest common ancestor (LCA) of `p` and `q`.

## Visual

1.

![image](https://github.com/user-attachments/assets/361f642b-8cf7-4022-8154-b6e0b8876ab3)

2.

![image](https://github.com/user-attachments/assets/b991caf8-e8ee-47c1-8db6-1c9fd23c665a)

3. 

![image](https://github.com/user-attachments/assets/ecb50d97-4f3b-4b96-9af5-743da10febb0)

4.

![image](https://github.com/user-attachments/assets/d067348f-a164-44f3-8ed7-e3edfb2d0707)

5. 

![image](https://github.com/user-attachments/assets/0d5daddb-c607-4106-a65d-efd297eca0dd)

6.

![image](https://github.com/user-attachments/assets/ffbf32ae-248d-49fa-8d2e-90f2a8737a95)

7. 

![image](https://github.com/user-attachments/assets/971640d6-2d21-415d-bf6a-2d1ac533e164)


## Time Complexity

The time complexity of the solution is $O(h)$, where $h$ is the height of the tree, as in the worst case, each pointer might traverse the entire height of the tree, including $h$ steps.

## Space Complexity

The space complexity of the solution is $O(1)$ as there is no additional space being used. Only two pointers are being maintained requiring constant space.
