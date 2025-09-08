### Approach one: subtle change in vertical order
```cpp
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int,vector<pair<int, int>>>mp;//col,<row,val>
        queue<pair<Node* , pair<int,int>>> q; //val,row,col
        q.push({root,{0,0}});
        while(!q.empty()){
            Node* node = q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            int n = q.size();
            q.pop();
            mp[col].push_back({row, node->data}); 
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }
        vector<int> ret;
        for(auto num : mp){
            // sort(num.second.begin(),num.second.end());
            int x;
            for(auto i : num.second){
                x=i.second;
            }
            ret.push_back(x);
        }
        return ret;
    }
};
```
### Approach two: Better and more readable
```cpp
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        
        // Simplified map: We only need to store one value per column.
        map<int, int> mp; // col -> node_data
        
        // Simplified queue: We only need the node and its column.
        queue<pair<Node*, int>> q; // node, col
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int col = temp.second;
            // Always update the value for the current column.
            // Since we traverse top-to-bottom, the last node we visit
            // in any column will be the bottom-most one.
            mp[col] = node->data;
            
            if (node->left) {
                q.push({node->left, col - 1});
            }
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }
        
        // The map's keys (columns) are automatically sorted.
        for (auto it : mp) {
            ret.push_back(it.second);
        }
        return ret;
    }
};
```
#### TC : O(N)    SC:O(N)