class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: If either p or q is NULL
        // They are the same ONLY IF both are NULL
        if (p == NULL || q == NULL)
            return (p == q);   // true if both null, false if one is null

        // Case 2: Both nodes exist → check their values AND children
        return (p->val == q->val) &&           // values must match
               isSameTree(p->left, q->left) &&  // left subtrees must match
               isSameTree(p->right, q->right);  // right subtrees must match
    }
};
