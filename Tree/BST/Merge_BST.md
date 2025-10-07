[1932. Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst/)
![[Pasted image 20251007210719.png]]
![[Pasted image 20251007210748.png]]

# Approach :

- To merge all the BSTs first we would need the root of the final BST that we are gonna build. Notice the root of the final BST would be the node which does not occur in any tree as leaf node. Hence we will push all the leaf node in the set and then check for each root node of the tree and if the root of that tree is not in the set then we can say that this would be the root of the final BST. Here if we don't find root then we return `nullptr` because we can't create a BST.
- Next part is merging the trees but before that we will map all the `root->val` to `root` for each tree so that we can search with the value and get the `node`. Now for merging what we will do is that we will use recursion. `build_bst` function would build the BST, the base case would be `root==nullptr` or `mp.empty()`. Then we would see if the left and right child of the current root node is leaf, if they are leaf then we will find a root node from the map and map it. And then just using recursion we would map all.
- Finally in the main function we would check that if the map is not empty then we were not able to combine all trees and hence return `nullptr` and then we would check if the generated tree is BST and if yes then we can finally return `root`.

## Code
```cpp
class Solution {
private:
    void build_tree(TreeNode* root, unordered_map<int, TreeNode*>& roots) {

        if (roots.empty() || root == nullptr) {
            return;
        }
        if (root->left && !root->left->left && !root->left->right) {
            int val = root->left->val;
            if (roots.count(val)) {
                root->left = roots[root->left->val];
                roots.erase(val);
            }
        }
        if (root->right && !root->right->left && !root->right->right) {
            int val = root->right->val;
            if (roots.count(val)) {
                root->right = roots[root->right->val];
                roots.erase(val);
            }
        }
        build_tree(root->left, roots);
        build_tree(root->right, roots);
    }
    bool check_bst(TreeNode* root, int lower_bound, int upper_bound) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower_bound || root->val >= upper_bound)
            return false;

        return check_bst(root->left, lower_bound, root->val) &&
               check_bst(root->right, root->val, upper_bound);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // first -> know the root of the final BST
        unordered_set<int> leaves;
        for (TreeNode* root : trees) {
            if (root->left)
                leaves.insert(root->left->val);
            if (root->right)
                leaves.insert(root->right->val);
        }
        TreeNode* root = nullptr;
        for (TreeNode* node : trees) {
            if (!leaves.count(node->val)) {
                root = node;
                break;
            }
        }
        // if no root found
        if (root == nullptr) {
            return nullptr;
        }
        // now i have the root of the final BST
        // now I will create a map which maps node->val => node
        unordered_map<int, TreeNode*> roots;
        for (auto node : trees) {
            if (node->val != root->val) {
                roots[node->val] = node;
            }
        }
        build_tree(root, roots);
        if (!roots.empty())
            return nullptr;
        // check if the tree is bst
        if (!check_bst(root, INT_MIN, INT_MAX)) {
            return nullptr;
        }

        return root;
    }
};
```

### TC : O(N)                            SC : O(N)