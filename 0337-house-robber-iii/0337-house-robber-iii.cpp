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
unordered_map<TreeNode*,int> cache;
private:
int dfs(TreeNode* root){
    if(cache.find(root)!=cache.end())
    return cache[root];

    int takeroot=root->val;

    if(root->left){
        takeroot += dfs(root->left->left);
        takeroot += dfs(root->left->right);
    }

    if(root->right){
        takeroot += dfs(root->right->left);
        takeroot += dfs(root->right->right);
    }

    int skiproot= dfs(root->left) + dfs(root->right);

    int best=max(takeroot,skiproot);
    cache[root]=best;
    return best;
}  
public:
    int rob(TreeNode* root) {
        cache[NULL]=0;
        return dfs(root);
    }
};