Given the `root` of a binary search tree and an integer `k`, return `true` _if there exist two elements in the BST such that their sum is equal to_ `k`, _or_ `false` _otherwise_.
Link : [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

# Approach 1:

- Here we create a simple hash set and push all nodes and check if we find `target - node->val` if yes then we return true.
## Code:
```cpp
class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) 
            return false;
        if(st.count(k - root->val)) 
            return true;
        st.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
```

#### TC : O(N)                            SC : O(N)
# Approach 2:

- We maintain two stacks left and right (which acts as the two pointer) initially we push left children to left stack and similarly for right.
- Then we see the top of both the stacks and then decide where we should go, left's rightsubtree or right's leftsubtree.
## Code:
```cpp
class Solution {
public:
    void pushRight(TreeNode* temp , stack<TreeNode*>& large){
        while(temp != nullptr){
            large.push(temp);
            temp = temp->right;
        }
        return;
    }

    void pushLeft(TreeNode* temp , stack<TreeNode*>& small){
        while(temp != nullptr){
            small.push(temp);
            temp = temp->left;
        }
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> small;
        stack<TreeNode*> large;
        pushLeft(root, small);
        pushRight(root, large);

        while(!small.empty() && !large.empty() && (small.top() != large.top())){
            TreeNode* leftChild = small.top();
            TreeNode* rightChild = large.top();
            int sum = leftChild->val + rightChild->val;
            if(sum == k){
                return true;
            }
            else if (sum > k){
                large.pop();
                pushRight(rightChild->left , large);
            } else {
                small.pop();
                pushLeft(leftChild->right , small);
            }
        }
        return false;
    }
};
```
#### TC : O(N)                            SC : O(H)
- This is little more optimal than previous one because here we don't push all elements into the stack. 