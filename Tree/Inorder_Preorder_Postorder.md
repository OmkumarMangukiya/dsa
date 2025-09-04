---
Inorder: LNR -> left to node to right
Preorder: NLR -> node to left to right
Postorder: " LRN -> left to right to node"
---
### Code
[Inorder_Preorder_Postorder](./Codes/Inorder_Preorder_Postorder.cpp)

## Recursive Traversals (DFS)

### Inorder Traversal (Recursive)


```
void inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

### Preorder Traversal (Recursive)

```
void preorder(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

### Postorder Traversal (Recursive)

```
void postorder(node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

## Iterative Traversals (DFS)

### Preorder Traversal (Iterative)

**Logic:** Use one stack. Push root, then pop, print, and push right child then left child.

```
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

        // Push right child first so that left child is processed first
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
}
```

### Inorder Traversal (Iterative)

**Logic:** Use one stack. Go as far left as possible, pushing nodes. Then pop, print, and move to the right.

```
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
```

### Postorder Traversal (Iterative - Two Stacks)

**Logic:** Use two stacks. The first stack generates a "reversed" postorder (Root->Right->Left), which is pushed to the second stack. Printing from the second stack gives the correct order.

```
void postorderIterative(node* root) {
    if (root == nullptr) {
        return;
    }
    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        node* current = s1.top();
        s1.pop();
        s2.push(current);

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
```

### Postorder Traversal (Iterative - One Stack)

**Logic:** A more complex but space-efficient version that uses a `lastVisited` pointer to decide when it's safe to process a node.

```
void postorderIterativeOneStack(node* root) {
    if (root == nullptr) {
        return;
    }
    stack<node*> st;
    node* temp = root;
    node* lastVisited = nullptr;

    while (temp != nullptr || !st.empty()) {
        if (temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        } else {
            node* peekNode = st.top();
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                temp = peekNode->right;
            } else {
                cout << peekNode->data << " ";
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}
```
### All Traversals in One Pass

**Logic:** This method uses a single stack with a `pair` to track the state of each node. The integer in the pair (1, 2, or 3) represents which "visit" we are on for a given node, simulating the recursive call stack.

- **State 1:** First visit. Add to preorder, then move left.
- **State 2:** Second visit (returned from left). Add to inorder, then move right.
- **State 3:** Third visit (returned from right). Add to postorder.
```cpp
vector<vector<int>> allTraversalsInOne(node* root) {
    vector<int> pre, in, post;
    if (root == NULL) {
        return {};
    }

    stack<pair<node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        node* currentNode = it.first;
        int visitNum = it.second;

        if (visitNum == 1) {
            pre.push_back(currentNode->data);
            st.push({currentNode, 2}); 
            if (currentNode->left != NULL) {
                st.push({currentNode->left, 1});
            }
        }
        else if (visitNum == 2) {
            in.push_back(currentNode->data);
            st.push({currentNode, 3}); 
            if (currentNode->right != NULL) {
                st.push({currentNode->right, 1});
            }
        }
        else { // visitNum == 3
            post.push_back(currentNode->data);
        }
    }

    return {pre, in, post};
}
```
