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
	cout<<"Enter data for insertin right to the "<<data<<endl;
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
    return 0;
}