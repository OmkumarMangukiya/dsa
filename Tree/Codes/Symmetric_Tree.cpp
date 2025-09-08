#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool checkSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val == root2->val &&
            checkSameTree(root1->left, root2->right) &&
            checkSameTree(root1->right, root2->left))
            return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return checkSameTree(root->left, root->right);
    }
};

// Example usage
int main() {
    // Construct a symmetric tree:
    //      1
    //     / \
    //    2   2
    //   / \ / \
    //  3  4 4  3
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3))
    );

    Solution sol;
    cout << (sol.isSymmetric(root) ? "Symmetric" : "Not symmetric") << endl;

    // Clean up memory (not strictly necessary for small test cases)
    // ... (delete nodes if needed)

    return 0;
}