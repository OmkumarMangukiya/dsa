- Code  
	[Implentation Traversal](./Codes/Binary_Tree_Implementation_Traversal.cpp)  
	[ZigZag](./ZigZag.md)  
	[Boundary Traversal](./Boundary_Traversal.md)  
	[Vertical Order](./Vertical_Order_Traversal.md)  
	[Top View](./Top_View.md)  
	[Bottom View](./Bottom_View.md)  
	[Right View](./Right_View.md)  
	[CheckSymmetric](./Codes/Symmetric_Tree.cpp)  
	[LCA - Lowest Common Ancestor](./LCA.md)  
	[Max Width of Tree](./Max_Width_of_Tree.md)  
	[Nodes with K distance & Nodes at distance k from leaf](./Nodes_with_K_distance.md)  
	[Construct Binary Tree](./Construct_Binary_Tree.md)  
	[Serialize and Deserialize Binary Tree](Serialize_and_Deserialize_Binary_Tree.md)  
	[Morris Traversal](Morris_Traversal.md)  
### Notes
- If you are given Post Order and Pre Order than you cannot constuct a unique binary tree. You must atleast have In Order to get it.
### Implementation
```cpp
class node{
public:
	int data;
	node* left;
	node* right; 
	
	node(int d){
	// this-> used to tell that we are using object's variable , here it's optional but better to use 
		this -> data = d;
		this -> left = NULL;
		this -> right = NULL;
	}
	node* buildTree(node* root){
		cout<<"Enter the Data"<<endl;
		int data;
		cin >>data;
		root = new node(data);
		
		if(data==-1){
			return NULL;
		}
		
		cout<<"Enter data for inserting left to the "<<data<<endl;
		root->left=buildTree(root->left);
		cout<<"Enter data for insertin right to the "<<data<<endl;
		root->right=buildTree(root->right);
		return root;
	}
};
int main (){
	node* root = NULL;
	root = buildTree(root);
	
	return 0;
}
```

### Level Order Traversal
- Print Tree level wise
```cpp
void levelOrderTraversal(node* root) {
    queue<node *> q;
    q.push(root);
    
    // We push NULL here to act as a separator for the levels of the tree.
    // The first NULL marks the end of the root level (level 0).
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // When we encounter a NULL, it signifies that one level of the tree has been completely traversed.
        if (temp == nullptr) {
            // So, we print a newline to move to the next line for the next level's nodes.
            cout << endl;
            
            // After processing a level, if the queue is not empty, it means there are nodes in the next level.
            // We push another NULL to mark the end of this next level.
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
```

### Reverse Level Order Traversal 
```cpp
void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    stack<int> s;

    // for new line (separator)
    const int NEWLINE_MARKER = INT_MIN;

    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == nullptr) { // A level has finished
            s.push(NEWLINE_MARKER);
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            s.push(temp->data);

            // CRITICAL: Enqueue RIGHT child first, then LEFT.
            // This ensures correct left-to-right order after the stack reverses it.
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
    }

    while (!s.empty()) {
        int val = s.top();
        s.pop();

        if (val == NEWLINE_MARKER) {
            cout << endl;
        } else {
            cout << val << " ";
        }
    }
}
```

### Height of Tree
```cpp
int calHeight(TreeNode* root){
	if(root==nullptr) return 0;

	int left = calHeight(root->left);
	int right = calHeight(root->right);

	return max(left,right)+1;
}

int maxDepth(TreeNode* root) {
	int height = calHeight(root);
	return height;

}
```

```cpp
int heightIterative(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    std::queue<TreeNode*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        // Get the number of nodes at the current level
        int levelSize = q.size();
        
        // Process all nodes of the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        // After processing a full level, increment the height
        height++;
    }
    return height;
}
```

### Diameter of Tree
- It's the maximum distance or length between two nodes in tree
```cpp
int calDiameter(TreeNode* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = calDiameter(root->left, diameter);
    int rightHeight = calDiameter(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calDiameter(root, diameter);
    return diameter;
}
```

### Check if Tree is balanced
#### O(N^2)
```cpp
class Solution {
public:
    // Helper function to calculate the height of a tree. O(N) operation.
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    // Main function to check for balance.
    bool isBalanced(TreeNode* root) {
        // An empty tree is balanced.
        if (root == nullptr) {
            return true;
        }

        // Check the height difference at the current node.
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        // Recursively check if both the left AND right subtrees are also balanced.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
```

#### O(N)
```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the helper function doesn't return -1, the tree is balanced.
        return checkHeight(root) != -1;
    }

private:
    // This function returns the height of a subtree if it's balanced,
    // otherwise it returns -1.
    int checkHeight(TreeNode* root) {
        // Base case: An empty tree has a height of 0 and is balanced.
        if (root == nullptr) {
            return 0;
        }

        // Recursively check the left subtree.
        int leftHeight = checkHeight(root->left);
        // If the left subtree is unbalanced, propagate the failure up.
        if (leftHeight == -1) {
            return -1;
        }

        // Recursively check the right subtree.
        int rightHeight = checkHeight(root->right);
        // If the right subtree is unbalanced, propagate the failure up.
        if (rightHeight == -1) {
            return -1;
        }

        // Check the balance condition at the current node.
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Signal that this node is unbalanced.
        }

        // If balanced, return the actual height of this subtree.
        return 1 + max(leftHeight, rightHeight);
    }
};
```
#### O(N)
```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // The final answer is just the boolean part of the pair returned for the root.
        return isBalancedAndHeight(root).first;
    }

private:
    // Returns a pair: {isBalanced, height}
    pair<bool, int> isBalancedAndHeight(TreeNode* root) {
        // Base case: An empty tree is balanced and has a height of 0.
        if (root == nullptr) {
            return {true, 0};
        }

        // Recursively check left and right subtrees.
        pair<bool, int> leftSubtree = isBalancedAndHeight(root->left);
        pair<bool, int> rightSubtree = isBalancedAndHeight(root->right);

        // Check if subtrees are balanced.
        bool isLeftBalanced = leftSubtree.first;
        bool isRightBalanced = rightSubtree.first;

        // Check the height difference at the current node.
        bool isCurrentBalanced = abs(leftSubtree.second - rightSubtree.second) <= 1;

        // If this node and both subtrees are balanced, the whole subtree is balanced.
        if (isLeftBalanced && isRightBalanced && isCurrentBalanced) {
            // Return true and the new height.
            return {true, 1 + max(leftSubtree.second, rightSubtree.second)};
        } else {
            // Otherwise, return false. The height value doesn't matter anymore.
            return {false, 0};
        }
    }
};
```

### Identical Tree
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

```

### Sum tree
#### O(N^2)
```cpp
class Solution {
public:
    // Helper function to calculate the sum of all nodes in a subtree. O(N) operation.
    int sum(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return sum(node->left) + sum(node->right) + node->data;
    }

    bool isSumTree(Node* root) {
        // An empty tree or a leaf node is a Sum Tree.
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        // Get the sum of the left and right subtrees.
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        // Check the condition for the current node and recurse for the subtrees.
        if ((root->data == leftSum + rightSum) && 
             isSumTree(root->left) && 
             isSumTree(root->right)) {
            return true;
        }

        return false;
    }
};
```

#### O(N)
```cpp
pair<bool,int> SumTree(Node* root){
        if(root==nullptr){
            return {true,0};
        }
        if((root->left==nullptr && root->right==nullptr)){
            return {true,root->data};
        }
        pair<bool,int> leftTree = SumTree(root->left);
        pair<bool,int> rightTree = SumTree(root->right);
        
        bool isLeft = leftTree.first;
        bool isRight = rightTree.first;
        
        bool isCurrent = leftTree.second+rightTree.second == root->data;
        
        if(isLeft && isRight && isCurrent){
            return {true,2*root->data};
        }
        return {false,0};
        
    }
bool isSumTree(Node* root) {
        // Your code here
        return SumTree(root).first;
    }
```

### Max Path Sum
```cpp
int findMaxPath(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }

    // Get the best possible path sum from the left and right children
    int leftPath = findMaxPath(root->left, maxSum);
    int rightPath = findMaxPath(root->right, maxSum);
    
    // A path with a negative sum is not useful to its parent; treat it as 0
    leftPath = max(0, leftPath);
    rightPath = max(0, rightPath);
    
    // This is the path that forms an inverted 'V' at the current node.
    // It's a candidate for the overall maximum, but it cannot be extended upwards.
    int currentPathValue = root->val + leftPath + rightPath;

    // Update the overall maximum sum if the path through the current node is better.
    maxSum = max(maxSum, currentPathValue);
    
    // Return the best path that can be extended upwards to the parent.
    // A path can only go up one side, not both.
    return root->val + max(leftPath, rightPath);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    findMaxPath(root, maxSum);
    return maxSum;
}
```
