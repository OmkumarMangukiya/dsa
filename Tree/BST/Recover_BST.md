You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. _Recover the tree without changing its structure_.

Link : [99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

# Approach 

- the approach is that we keep three nodes `first` misplaced `second` misplaced and `prev` node. 
- We do inorder traversal and when at current root we check if there was a previous (`left of the root`) and if it was `greater than root` then we say we got pair of misplaced and we store those nodes and after the inorder is finished we simply swap them.

```cpp
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
```