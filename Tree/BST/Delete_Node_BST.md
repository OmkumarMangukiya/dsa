Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return _the **root node reference** (possibly updated) of the BST_.[

Link : [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)
## Solution

- To delete a node there can be 3 cases:
	- No child -> in this case where there is no left or right child we just delete the node and return `nullptr`
	- One child -> in this case we just copy the value of the one child which is there.
	- Two child -> This is a bit complex what we need to do here is that we need to put a value for this node from the subtree such that the value is larger than all of the nodes in left subtree and smaller than all the nodes in the right subtree. To do that we can just pick the smallest number in the right subtree and then  delete that. This is called Inorder Successor. Hence we find the smallest element in the right subtree and then replace it with the element to be deleted and then we delete the successor.
```cpp
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
```

TC : O(N)                            SC : O(N)