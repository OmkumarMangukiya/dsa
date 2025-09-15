# Inorder Traversal
- In normal recursion, we go from root to the leaf node and then go back to the root. But without recursion it's not possible.
- So what we do here that we go to left child of the root then we go to the right most child and connect it with the root. Why? It's because when we will be over with the left subtree we can go back to root.
### Algorithm:
- **If there is no left child:** This is simple. We "visit" and then move to its right child.
- If there is a left child
	- Find the **inorder predecessor** (the rightmost node in the left subtree).
	- If the predecessor's right child is `nullptr`
		- Create the temporary link: `predecessor->right = current`.
		- Move to the left: `current = current->left`. (We do **not** visit the node yet).
	- If the predecessor's right child is already linked to `current`:
		- This means we have finished traversing the entire left subtree and have returned via our temporary link.
		- **Break the link** to restore the tree: `predecessor->right = nullptr`.
		-  **Visit the `current` node**.
		- Move to the right: `current = current->right`.
```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* predecessor = curr->left;
            while (predecessor->right != nullptr && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = curr; // Create the temporary link
                curr = curr->left;
            } else {
                predecessor->right = nullptr; // Break the link
                inorder.push_back(curr->val); // Visit the node
                curr = curr->right;
            }
        }
    }
    return inorder;
}
```

# Preorder Traversal
- Here we just need to change one line. The only difference is that we need to push the `current->val` before we visit the left node because in preorder we do `root->left->right`. 
```cpp
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                preorder.push_back(curr->val); // Visit the node
                curr = curr->right;
            } else {
                TreeNode* predecessor = curr->left;
                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = curr;     // Create the temporary link
                    preorder.push_back(curr->val); // Visit the node before going to the left
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr; // Break the link
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
```
