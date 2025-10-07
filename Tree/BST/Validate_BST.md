Given the `root` of a binary tree, _determine if it is a valid binary search tree (BST)_.

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **strictly less than** the node's key.
- The right subtree of a node contains only nodes with keys **strictly greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

Link : [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

```cpp
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }
```
#### TC : O(N)                            SC : O(N)