```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* temp = nullptr;
            for(int i = 0; i < n; i++){
                temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ret.push_back(temp->val);
        }
        return ret;
    }
};

```
### TC : O(N)    SC:O(N)