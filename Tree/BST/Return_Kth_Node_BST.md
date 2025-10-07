Given the `root` of a binary search tree, and an integer `k`, return _the_ `kth` _smallest value (**1-indexed**) of all the values of the nodes in the tree_.
[Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Approach:

- We know that the smallest number would be the left most child and then just after that it's parent is large and inorder traversal gives us the ascending order of the tree.
- Alternative to this approach we can also create a vector and store all inorder elements in the vector using recursive inorder and then return Kth number.
```cpp
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal, iterative
        TreeNode* current = root;
        stack<TreeNode*> st;
        int target = 0;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            target++;
            if (k == target) {
                return current->val;
            }
            current = current->right;
        }
        return 0;
    }
```
### TC : O(N)                            SC : O(N)