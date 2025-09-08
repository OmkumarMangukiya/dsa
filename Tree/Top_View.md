```cpp
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int,vector<pair<int, int>>>mp;//col,<row,val>
        queue<pair<Node* , pair<int,int>>> q; //val,row,col
        q.push({root,{0,0}});
        while(!q.empty()){
            Node* node = q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            int n = q.size();
            q.pop();
            if(mp.count(col)==0)
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
            sort(num.second.begin(),num.second.end());
            for(auto i : num.second){
                ret.push_back(i.second);
            }
            
        }
        return ret;
    
    }
};
```
### TC : O(N log N)    SC:O(N) for both

### More Simpler 
```cpp
vector<int> topView(Node *root) {
    vector<int> res;
    if (!root) {
        return res;
    }

    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* node = temp.first;
        int col = temp.second;

        if (nodes.find(col) == nodes.end()) {
            nodes[col] = node->data;
        }

        if (node->left) {
            q.push({node->left, col - 1});
        }
        if (node->right) {
            q.push({node->right, col + 1});
        }
    }

    for (auto it : nodes) {
        res.push_back(it.second);
    }
    return res;
}
```