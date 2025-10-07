Given an array of integers preorder, which represents the **preorder traversal** of a BST (i.e., **binary search tree**), construct the tree and return _its root_.
Link : [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

```cpp
TreeNode* buildBST(vector<int>& preorder, int& idx, int lower_bound, int upper_bound) {
    if (idx == preorder.size() || preorder[idx] < lower_bound || preorder[idx] > upper_bound) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = buildBST(preorder, idx, lower_bound, preorder[idx - 1]);
    root->right = buildBST(preorder, idx, preorder[idx - 1], upper_bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;
    return buildBST(preorder, idx, INT_MIN, INT_MAX);
}
```

### TC : O(N)                            SC : O(N)