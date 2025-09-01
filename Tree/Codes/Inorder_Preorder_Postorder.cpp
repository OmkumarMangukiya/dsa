#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right; 
	
	node(int d){
		this -> data = d;
		this -> left = NULL;
		this -> right = NULL;
	}
};
node* buildTree(node* root){
	cout<<"Enter Data"<<endl;
	int data;
	cin >>data;
	root = new node(data);

	if(data==-1){
		return NULL;
	}

	cout<<"Enter data for inserting left to the "<<data<<endl;
	root->left=buildTree(root->left);
	cout<<"Enter data for inserting right to the "<<data<<endl;
	root->right=buildTree(root->right);
	return root;
}

void inorder(node *root){
    if(root==nullptr){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data<<" ";
}
void preorderIterative(node* root) {
    if (root == nullptr) {
        return;
    }
    stack<node*> s;
    s.push(root);

    while (!s.empty()) {
        node* current = s.top();
        s.pop();
        cout << current->data << " ";

        // Push right child first so that left child is processed first33
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
}

void inorderIterative(node* root) {
    stack<node*> s;
    node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        current = current->right;
    }
}

void postorderIterative(node* root) {
    if (root == nullptr) {
        return;
    }
    stack<node*> s1, s2;
    s1.push(root);

    // Run while first stack is not empty
    while (!s1.empty()) {
        node* current = s1.top();
        s1.pop();
        s2.push(current);

        // Push left and right children of removed item to s1
        if (current->left) {
            s1.push(current->left);
        }
        if (current->right) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
	node *root = nullptr;
	root = buildTree(root);
	//1 2 -1 -1 3 -1 -1
	inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    cout << "\n--- Iterative Traversals ---\n";
    cout << "Inorder: ";
    inorderIterative(root);
    cout << endl;
    
    cout << "Preorder: ";
    preorderIterative(root);
    cout << endl;

    cout << "Postorder: ";
    postorderIterative(root);
    cout << endl;

    return 0;
}