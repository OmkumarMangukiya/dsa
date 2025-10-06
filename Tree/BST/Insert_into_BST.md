You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return _the root node of the BST after the insertion_. It is **guaranteed** that the new value does not exist in the original BST.

**Notice** that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return **any of them**.

Link :  [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* temp = root;
    if (temp == nullptr) {
        return new TreeNode(val);
    }
    while (temp != nullptr) {
        if (temp->val < val) {
            if (temp->right == nullptr) {
                temp->right = new TreeNode(val);
                break;
            }
            temp = temp->right;
        }
        else if (temp->val > val) {
            if (temp->left == nullptr) {
                temp->left = new TreeNode(val);
                break;
            }
            temp = temp->left;
        }
    }
    return root;
}
```

#### TC : O(N)                            SC : O(1)