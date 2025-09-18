Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

# Approach :

- The approach is that we first go to the bottom most node on left side and then see if that node is the node which is to be deleted.
- If it is then we simply add the child of those nodes to a `result` vector where we are storing all the roots of the new trees after we delete the nodes.
- After pushing the children we return `nullptr` to its parent so that it's parent knows that it has no child (say left or right).
- If the node is not to be deleted then we simply return `root` to the parent.
- Lastly we need to check if the given root node is to be deleted or not because it won't be checked for the condition so we need to do it manually if we the root node is not in the `to_delete` then we can simply add the root to the `result` .
```cpp
class Solution {
private:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& toDelete, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = deleteHelper(root->left, toDelete, result);
        root->right = deleteHelper(root->right, toDelete, result);

        if (toDelete.count(root->val)) {
            if (root->left != nullptr) {
                result.push_back(root->left);
            }
            if (root->right != nullptr) {
                result.push_back(root->right);
            }
            return nullptr;
        } else {
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        deleteHelper(root, toDelete, result);
        if (toDelete.count(root->val) == 0) {
            result.push_back(root);
        }
        return result;
    }
};
```

### TC : O(N)       SC : O(N)