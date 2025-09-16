Given the `root` of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
- The "linked list" should be in the same order as a [**pre-order** **traversal**](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) of the binary tree.
```cpp
class Solution {
private:
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& preorder) {
        if (root == nullptr) {
            return;
        }
        preorder.push_back(root);
        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);
    }

public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorder;
        preorderTraversal(root, preorder);
        int n = preorder.size();
        if (n <= 1) return;
        for (int i = 0; i < n - 1; i++) {
            preorder[i]->right = preorder[i + 1];
            preorder[i]->left = nullptr;
        }
    }
};
```
- TC : O(N)           SC:(N)

## Optimal space complexity
This is done using Morris Traversal getting O(1) space.
```cpp
    void flatten(TreeNode* root) {
        TreeNode* currentNode = root;
        while (currentNode != nullptr) {
            if (currentNode->left != nullptr) {
                TreeNode* predecessor = currentNode->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }

                predecessor->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = nullptr;
            }
            currentNode = currentNode->right;
        }
    }
```
