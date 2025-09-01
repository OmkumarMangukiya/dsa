- Code
[Implentation Traversal](./Codes/Binary_Tree_Implementation_Traversal.cpp)
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
