You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

Link : https://leetcode.com/problems/search-in-a-binary-search-tree/description/

## Using Recursion

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (root->val == val) {
        return root;
    }
    if (root->val < val) {
        return searchBST(root->right, val);
    }
    if (root->val > val) {
        return searchBST(root->left, val);
    }
    return nullptr;
}
```

#### TC : O(N)                            SC : O(N)

## Iterative method
```cpp
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* temp = root;
        while (temp != nullptr) {
            if (temp->val == val) {
                return temp;
            } else if (temp->val < val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return nullptr;
    }
```
#### TC : O(N)                            SC : O(1)