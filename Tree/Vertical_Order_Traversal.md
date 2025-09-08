### Approach 1:
```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> retp;
        vector<vector<int>> retn;

        if (!root) return {};

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            vector<pair<int, int>> levelNodes;

            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();

                TreeNode* currentNode = temp.first;
                int col = temp.second;

                levelNodes.push_back({col, currentNode->val});

                if (currentNode->left) {
                    q.push({currentNode->left, col - 1});
                }
                if (currentNode->right) {
                    q.push({currentNode->right, col + 1});
                }
            }

            sort(levelNodes.begin(), levelNodes.end());

            for (auto const& [col, val] : levelNodes) {
                if (col < 0) {
                    int n_idx = abs(col) - 1;
                    if (n_idx >= retn.size()) {
                        retn.resize(n_idx + 1);
                    }
                    retn[n_idx].push_back(val);
                } else {
                    if (col >= retp.size()) {
                        retp.resize(col + 1);
                    }
                    retp[col].push_back(val);
                }
            }
        }

        vector<vector<int>> ret;
        reverse(retn.begin(), retn.end());
        for (auto num : retn) {
            if (!num.empty()) ret.push_back(num);
        }
        for (auto num : retp) {
            if (!num.empty()) ret.push_back(num);
        }
        return ret;
    }
};
```

### Approach 2:
```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) {
        return ret;
    }

    map<int, vector<pair<int, int>>> columns; // col -> list of (row, value)
    queue<pair<TreeNode*, pair<int, int>>> q; // node, (row, col)

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;

        columns[col].push_back({row, node->val});

        if (node->left) {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right) {
            q.push({node->right, {row + 1, col + 1}});
        }
    }

    for (auto& col_data : columns) {
        // Sort by row first, then value
        sort(col_data.second.begin(), col_data.second.end());

        vector<int> current_col;
        for (const auto& node_data : col_data.second) {
            current_col.push_back(node_data.second);
        }
        ret.push_back(current_col);
    }

    return ret;
	}
};
```
### TC : O(N log N)    SC:O(N)