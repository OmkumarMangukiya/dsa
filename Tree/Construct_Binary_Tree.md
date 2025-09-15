# Preorder and Inorder

- From the preorder we can see the root and then we know that in inorder we go left ,root, right. 
- Hence I will find the node in the inorder and then I can just say that left part of the inorder is the left child and the right part is the right child.
![[Pasted image 20250913224532.png]]
### Approach 1:
```cpp
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
    if (start > end) {
        return NULL;
    }

    int i = start;
    for (; i <= end; i++) {
        if (inorder[i] == preorder[idx]) {
            break;
        }
    }

    idx++;
    TreeNode* root = new TreeNode(inorder[i]);
    root->left = solve(preorder, inorder, start, i - 1, idx);
    root->right = solve(preorder, inorder, i + 1, end, idx);

    return root;
}

public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    int idx = 0;
    int start = 0;
    int end = n - 1;
    return solve(preorder, inorder, start, end, idx); 
}
```
TC : **O($N^2$)**

- In the worst case (e.g., skewed tree), the `for` loop to find `inorder[i] == preorder[idx]` runs up to `n` times for each of `n` nodes.

Hence to optimise this we can use a unordered_map to put all the inorder nodes into the map and then use it for lookup.

## Approach 2:
```cpp
class Solution {
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx, unordered_map<int, int>& mp) {
        if (start > end) {
            return NULL;
        }

        int i = mp[preorder[idx]];
        idx++;

        TreeNode* root = new TreeNode(inorder[i]);
        root->left = solve(preorder, inorder, start, i - 1, idx, mp);
        root->right = solve(preorder, inorder, i + 1, end, idx, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int idx = 0;
        int start = 0;
        int end = n - 1;

        return solve(preorder, inorder, start, end, idx, mp);
    }
};
```
TC : O(N)
- Because now we are using map for accessing 

# Postorder and Inorder

- The logic is the same just see that the in the postorder we have left->right->root
- This means we can just start traversing from the last index of the post order and then right then left.
- Remember here we **first solve for right** then left because we are traversing from back.
```cpp
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx, unordered_map<int, int>& mp) {
        if (start > end) {
            return nullptr;
        }

        int i = mp[postorder[idx]];
        idx--;

        TreeNode* root = new TreeNode(inorder[i]);
        root->right = solve(inorder, postorder, i + 1, end, idx, mp);
        root->left = solve(inorder, postorder, start, i - 1, idx, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int idx = n - 1;
        return solve(inorder, postorder, 0, n - 1, idx, mp);
    }
};
```
TC:O(N)

# From Description
You are given a 2D integer array `descriptions` where `descriptions[i] = [parent[i], child[i], isLeft[i]]` indicates that `parenti` is the **parent** of `childi` in a **binary** tree of **unique** values. Furthermore,

- If `isLeft[i] == 1`, then `child[i]` is the left child of `parent[i]`.
- If `isLeft[i] == 0`, then `child[i]` is the right child of `parent[i]`.

Construct the binary tree described by `descriptions` and return _its **root**_.

### Approach
- we will keep a map where we will store all the value,TreeNode pair to keep track of nodes.
- Then we will keep a `childSet` where we will push all the child nodes , later we will use it to find the root of the tree.
- Now for every vector in the descriptions we will get the `parent` `child` `isLeft` and then we will check if it is in the `mp` if not then we will create it and then we will map the parent to it's child based on the `isLeft` and also we will keep pushing the child in the `childSet`
- After we have mapped all parents and children, we will see which parent is not in the `childSet` and we will return the node of that parent cause it will the root of the tree.
```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // for storing value : node
        unordered_map<int, TreeNode*> mp;
        // list of nodes which can never be the root of the tree
        unordered_set<int> childSet;

        for (vector<int>& vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if (isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }

        // finding the root
        for (vector<int>& vec : descriptions) {
            int parent = vec[0];
            if (childSet.find(parent) == childSet.end()) {
                return mp[parent];
            }
        }

        return nullptr;
    }
};
```

