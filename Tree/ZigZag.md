Given the `root` of a binary tree, return _the zigzag level order traversal of its nodes' values_. (i.e., from left to right, then right to left for the next level and alternate between).
```cpp
class Solution {
public:
	//TC : O(n)   SC : O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> v;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            if (ret.size() % 2 != 0) {
                reverse(v.begin(), v.end());
            }

            ret.push_back(v);
        }

        return ret;
    }
};
```

#### We can optimize this by not using reverse , the time complexity will be same but it will be a little bit better
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            
            ret.push_back(currentLevel);
            leftToRight = !leftToRight;
        }
        return ret;
    }
};
```