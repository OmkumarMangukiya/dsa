https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/7184158/c-bfs-solution-map-child-to-parent-level-order-from-target-clean-easy-beats-100/
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

# Count the nodes at distance K from leaf

Given a binary tree with **n** nodes and a non-negative integer **k**, the task is to count the number of **special nodes**. A node is considered **special** if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly **k**.

## Approach 1: Brute Force
- For every node check if there is a leaf node at k distance.

## Approach 2:
- Store all root to leaf path then pick all n-k-1 nodes from each if n>k.
### Store all root to leaf path
```cpp
class Solution {
  private:
    void rootToLeaf(Node* root , vector<vector<Node*>>& path , vector<Node*>& current){
        if(root==nullptr){
            return;
        }
         current.push_back(root);
        if(root->left == nullptr && root->right==nullptr){
            path.push_back(current);
        }
       
        rootToLeaf(root->left , path , current);
        rootToLeaf(root->right ,path , current);
        current.pop_back();
    }
  public:
  
    int kthFromLeaf(Node* root, int k) {
        // code here.
        vector<vector<Node*>> path;
        vector<Node*> current;
        set<Node*> res;
        rootToLeaf(root, path , current);
        for(auto paths : path){
            if(paths.size()>k){
                res.insert(paths[paths.size()-k-1]);
            }
        }
        return res.size();
    }
};
```
### TC : O(N)    SC:O(N* H)
- In a tree there can be maximum N/2 leaf nodes hence for every N/2 leaf nodes we would at max travel to the top which gives use the O(N * H) space complexity.
## Approach 3:
- Here we will try to reduce space complexity
- the idea would be - when we store the root to leaf why we are storing it instead we can just check if the current vector size is greater than k. If yes then we can get our node.
```cpp
private:
    void rootToLeaf(Node* root , vector<Node*>& current, set<Node*>& res , int k){
        if(root==nullptr){
            return;
        }
         current.push_back(root);
        if(root->left == nullptr && root->right==nullptr){
            if(current.size() >  k){
                res.insert(current[current.size()-k-1]);
            }
        }
       
        rootToLeaf(root->left  , current, res, k);
        rootToLeaf(root->right  , current , res , k);
        current.pop_back();
    }
  public:
  
    int kthFromLeaf(Node* root, int k) {
        // code here.
        vector<Node*> current;
        set<Node*> res;
        rootToLeaf(root , current, res , k);
        return res.size();
    }
```