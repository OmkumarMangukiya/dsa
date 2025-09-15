```cpp
class Solution {
public:
    bool isLeaf(Node* node) {
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }
        return false;
    }

    void addLeftBoundary(Node* root, vector<int>& boundaryNodes) {
        Node* currentNode = root->left;
        while (currentNode) {
            if (!isLeaf(currentNode)) {
                boundaryNodes.push_back(currentNode->data);
            }
            if (currentNode->left) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
    }

    void addLeaves(Node* root, vector<int>& boundaryNodes) {
        if (root == nullptr) {
            return;
        }
        if (isLeaf(root)) {
            boundaryNodes.push_back(root->data);
            return;
        }
        addLeaves(root->left, boundaryNodes);
        addLeaves(root->right, boundaryNodes);
    }

    void addRightBoundary(Node* root, vector<int>& boundaryNodes) {
        Node* currentNode = root->right;
        stack<int> rightPath;
        while (currentNode) {
            if (!isLeaf(currentNode)) {
                rightPath.push(currentNode->data);
            }
            if (currentNode->right) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }
        while (!rightPath.empty()) {
            boundaryNodes.push_back(rightPath.top());
            rightPath.pop();
        }
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> boundaryNodes;
        if (root == nullptr) {
            return boundaryNodes;
        }
        
        if (!isLeaf(root)) {
            boundaryNodes.push_back(root->data);
        }
        
        addLeftBoundary(root, boundaryNodes);
        addLeaves(root, boundaryNodes);
        addRightBoundary(root, boundaryNodes);
        
        return boundaryNodes;
    }
};
```
**Time Complexity: O(N)** where N is the number of nodes in the Binary Tree.

1. Adding the left boundary of the Binary Tree results in the traversal of the left side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
2. For the bottom traversal of the Binary Tree, traversing the leaves is proportional to O(N) as preorder traversal visits every node once.
3. Adding the right boundary of the Binary Tree results in the traversal of the right side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).

Since all these operations are performed sequentially, the overall time complexity is dominated by the most expensive operation, which is O(N).

**Space Complexity: O(N)** where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, resulting in an O(N) auxiliary space complexity.