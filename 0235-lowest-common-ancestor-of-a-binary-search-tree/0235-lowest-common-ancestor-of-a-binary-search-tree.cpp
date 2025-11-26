class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Traverse the BST starting from the root
        while (root != nullptr) {

            // CASE 1:
            // If BOTH p and q have values smaller than the current root,
            // they both lie in the LEFT subtree.
            if (p->val < root->val && q->val < root->val)
                root = root->left;

            // CASE 2:
            // If BOTH p and q have values bigger than the current root,
            // they both lie in the RIGHT subtree.
            else if (p->val > root->val && q->val > root->val)
                root = root->right;

            // CASE 3:
            // If the above two conditions do NOT match:
            // It means p and q lie on DIFFERENT sides of root,
            // OR root is equal to one of p or q.
            // Therefore, root is the SPLIT POINT → LCA found.
            else
                return root;
        }

        // If somehow the tree is empty
        return nullptr;
    }
};
