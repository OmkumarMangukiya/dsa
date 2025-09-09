Given the `root` of a binary tree, return _the **maximum width** of the given tree_.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

### Approach
- If we need to find a width for a particular node we need to get the first and last node's indices.
- Then subtracting them would get the width of that level.
- For this we simply can create a queue which holds the node and the index of that node.
- But remember while submitting the memory might exceed due to the number of possible node and that's why we need to update the index every time(so basically it's just re-basing the index).
- So for all the levels first node will start from 0 and the last node will end at some index and then we can use it to get the answer.
```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            long long levelStart = q.front().second;
            long long levelEnd = q.back().second;
            maxWidth = max(maxWidth, levelEnd - levelStart + 1);

            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto current = q.front();
                TreeNode* node = current.first;
                //re-basing the index to avoid memory overflow
                long long index = current.second - levelStart;
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }
        }
        return maxWidth;
    }
};
```