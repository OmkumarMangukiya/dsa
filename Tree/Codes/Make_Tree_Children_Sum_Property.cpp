#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void makeTreeChildrenSum(node* root) {
    if (root == nullptr || (!root->left && !root->right)) {
        return;
    }

    // Step 1: Recurse to the bottom first.
    // This ensures children's subtrees are already fixed before we handle the parent.
    makeTreeChildrenSum(root->left);
    makeTreeChildrenSum(root->right);

    // Step 2: Now that we are at the bottom, get their sum.
    int childSum = 0;
    if (root->left) {
        childSum += root->left->data;
    }
    if (root->right) {
        childSum += root->right->data;
    }

    // Step 3: Compare and fix.
    if (childSum >= root->data) {
        // Case 1: Children's sum is bigger. Update the parent.
        root->data = childSum;
    } else {
        // Case 2: Parent is bigger. Increase one child's value by the difference.
        // We only need to do this for one child (conventionally the left one).
        int diff = root->data - childSum;
        if (root->left) {
            root->left->data += diff;
            // Now we must propagate this change down the left subtree.
            makeTreeChildrenSum(root->left);
        } else if (root->right) { // Fallback if no left child
            root->right->data += diff;
            makeTreeChildrenSum(root->right);
        }
    }
}
void changeTree(node* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->data;
        }
        if (root->right) {
            child += root->right->data;
        }

        // Compare the sum of children with
        // the current node's value and update
        if (child >= root->data) {
            root->data = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->data = root->data;
            } else if (root->right) {
                root->right->data = root->data;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->data;
        }
        if (root->right) {
            tot += root->right->data;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->data = tot;
        }
    }


// Builds tree from vector<int> input in level order, -1 means NULL
node* buildTreeFromVector(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        node* curr = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= arr.size()) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// For testing: print tree in level order
void printLevelOrder(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    q.push(new node(-1));
    while (!q.empty())
    {
        node* curr = q.front();
        q.pop();
        if(curr->data==-1){
            cout << endl;
            if(!q.empty())
            q.push(new node(-1));
        }
        else {
            cout << curr->data << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 8, 2, 3, 1, -1, -1, -1, -1, -1, -1};
    node* root = buildTreeFromVector(arr);
    printLevelOrder(root);
    changeTree(root);
    printLevelOrder(root);
    return 0;
}