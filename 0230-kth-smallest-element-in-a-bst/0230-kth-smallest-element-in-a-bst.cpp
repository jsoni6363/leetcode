/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    /*
     kthSmallest(...)
     ----------------
     Finds the kth smallest value in a BST
     using inorder traversal.
    */
    int kthSmallest(TreeNode* root, int k) {

        /*
         tmp[0] → remaining k
         tmp[1] → stores the answer
        */
        vector<int> tmp(2);

        // Initialize remaining count
        tmp[0] = k;

        // Start inorder traversal
        dfs(root, tmp);

        // After traversal, tmp[1] holds the answer
        return tmp[1];
    }

    /*
     dfs(node, tmp)
     --------------
     Performs inorder traversal:
     Left → Node → Right
    */
    void dfs(TreeNode* node, vector<int>& tmp) {

        // Base case: empty node
        if (!node) return;

        // 1️⃣ Visit left subtree
        dfs(node->left, tmp);

        /*
         2️⃣ Process current node
         Since inorder traversal visits nodes
         in sorted order, we decrement k.
        */
        tmp[0]--;

        /*
         If tmp[0] becomes 0,
         this means we have reached
         the kth smallest element.
        */
        if (tmp[0] == 0) {
            tmp[1] = node->val; // store answer
            return;             // stop further work
        }

        // 3️⃣ Visit right subtree
        dfs(node->right, tmp);
    }
};
