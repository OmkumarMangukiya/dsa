Given the `root` of a binary tree, determine if it is a _complete binary tree_.

In a **[complete binary tree](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

# Approach 1: Using BFS
- The simple idea is that if we found a element after we found a null then it is not a complete binary tree.
```cpp
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current == nullptr) {
                foundNull = true;
            } else {
                if (foundNull == true) {
                    return false;
                }
                q.push(current->left);
                q.push(current->right); 
            }
        }
        return true;
    }
};
```

# Approach 2: DFS
- The idea is to first count number of nodes in the tree and then do dfs with a index. Whenever a index goes beyond the number of nodes it means that we have encountered a null node.
```cpp
class Solution {
private:
    int countNodes(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        
        return left + right + 1;
    }

    bool dfs(TreeNode* root, int i, int& totalNodes){
        if(root == nullptr){
            return true;
        }
        if(i > totalNodes){
            return false;
        }
        return dfs(root->left, 2 * i, totalNodes) && 
               dfs(root->right, 2 * i + 1, totalNodes);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int totalNode = countNodes(root);
        return dfs(root, 1, totalNode);
    }
};
```
