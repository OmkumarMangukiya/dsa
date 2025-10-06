### Ceil(x) is a number that is either equal to x or is immediately greater than x.

```cpp
int findCeil(Node* root, int x) {
        int ceil =-1;
        if(root==nullptr) return ceil;
        while(root!=nullptr){
            if(root->data == x){
                return x;
            }
            else if(root->data < x){
                root = root->right;
            }
            else{
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
```
### find the greatest value node of the BST which is smaller than or equal to x.
```cpp
int floor(Node* root, int x) {
        int floor = -1 ;
        while(root!=nullptr){
            if(root->data == x){
                return x;
            }
            else if(root->data < x){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    }
```


### TC : O(N)                            SC : O(1)