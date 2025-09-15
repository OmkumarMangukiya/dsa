```cpp
class Codec {
private:
    // Recursively builds a string from the tree using preorder traversal
    void buildString(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "N,";
            return;
        }
        
        s += to_string(root->val) + ",";
        buildString(root->left, s);
        buildString(root->right, s);
    }

    // Recursively builds a tree from the vector of tokens
    TreeNode* buildTree(vector<string>& tokens, int& index) {
        if (index >= tokens.size() || tokens[index] == "N") {
            index++;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(tokens[index]));
        index++;
        
        root->left = buildTree(tokens, index);
        root->right = buildTree(tokens, index);
        
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        string s = ""; 
        buildString(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string serializedData) {
        if (serializedData.empty()) {
            return nullptr;
        }
        
        stringstream ss(serializedData);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        int index = 0;
        return buildTree(tokens, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```