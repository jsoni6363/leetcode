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
     Finds the kth smallest element in a BST.
    */
    int kthSmallest(TreeNode* root, int k) {

        // Step 1: Store all node values here
        vector<int> arr;

        // Step 2: Traverse the tree and fill arr
        dfs(root, arr);

        // Step 3: Sort all values
        sort(arr.begin(), arr.end());

        // Step 4: Return kth smallest (1-indexed)
        return arr[k - 1];
    }

    /*
     dfs(node, arr)
     --------------
     Performs Depth First Search to collect
     all node values from the tree.
    */
    void dfs(TreeNode* node, vector<int>& arr) {

        // Base case: if node is null, stop
        if (!node) return;

        // Store current node value
        arr.push_back(node->val);

        // Visit left subtree
        dfs(node->left, arr);

        // Visit right subtree
        dfs(node->right, arr);
    }
};