```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if (leftAns != nullptr && rightAns != nullptr) {
            return root;
        } else if (leftAns != nullptr) {
            return leftAns;
        } else {
            return rightAns;
        }
    }
};
```
