```cpp
class Solution {
private:
    void mapChildToParent(TreeNode* root , unordered_map<TreeNode*, TreeNode*>& mp){
        if(root==nullptr){
            return;
        }
        if(root->left){
            mp[root->left]=root;
            mapChildToParent(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            mapChildToParent(root->right,mp);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // I can solve this question by doing a bfs considering target as my root but for that I would need to somehow point a child to its parent. By doing that I can easily traverse using level order traversal and stop at kth level and print those number at that level
        // so first I will do a inorder traversal to map all child to its parent
        unordered_map<TreeNode*, TreeNode*> mp;

        mapChildToParent(root,mp);

        // Now I just have to do bfs from target and I will stop when I reach kth level

        queue<TreeNode*> q;
        q.push(target);
        vector<int> ret;

        // Here we will also need a visited set or vector because it might happens that when we travers from child to parent then we calling left and right child of that parent will trigger the already visted node which we don't want. Also here it is given that all node values are unique.

        unordered_set<int> visited;
        visited.insert(target->val);
        while(!q.empty()){
            int n = q.size();
            if(k==0){
                while(!q.empty()){
                    ret.push_back(q.front()->val);
                    q.pop();
                }
                return ret;
            }
            while(n--){
                TreeNode* current = q.front();
                q.pop();
                // check if the parent exist for the current node and it's not visited
                if(mp.count(current) && !visited.count(mp[current]->val)){
                    q.push(mp[current]);
                    visited.insert(mp[current]->val);
                }
                // now push the children if exist
                if(current->left && !visited.count(current->left->val)){
                    q.push(current->left);
                    visited.insert(current->left->val);
                }
                if(current->right && !visited.count(current->right->val)){
                    q.push(current->right);
                    visited.insert(current->right->val);
                }
            }
            k--;
        }
        return ret;
    }
};
```