
Given a **binary tree** `root`, return _the maximum sum of all keys of **any** sub-tree which is also a Binary Search Tree (BST)_.

Link : [1373. Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)

# Approach

```cpp
class ds{
    public:
        bool isbst;
        int min;
        int max;
        int sum;
};

class Solution {
public:
    ds bst_sum(TreeNode* root , int &ans){
        if(root == nullptr){
            return {true, INT_MAX, INT_MIN, 0};
        }
        ds left = bst_sum(root->left,ans);
        ds right = bst_sum(root->right, ans);
        ds curr;
        curr.sum = left.sum + right.sum + root->val;
        curr.min = min (root->val , left.min);
        curr.max = max(root->val , right.max);
        curr.isbst = left.isbst && right.isbst && (root->val > left.max && root->val < right.min);
        if(curr.isbst){
            ans = max(ans , curr.sum);
        }
        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int ret = 0;
        bst_sum(root,ret);
        return ret;
    }
};
```