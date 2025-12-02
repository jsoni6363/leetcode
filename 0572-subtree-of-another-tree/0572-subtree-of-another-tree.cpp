class Solution {
public:

    // Function 1 → scans through big tree
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // ✅ Base Case 1: If subtree is empty, it always matches
        if (!subRoot) {
            return true;
        }

        // ✅ Base Case 2: If big tree ends but subRoot is still there → impossible
        if (!root) {
            return false;
        }

        // 🧠 Main logic:
        // "Is the big tree from THIS node exactly same as subtree?"
        if (sameTree(root, subRoot)) {
            return true;  // ✅ Match found!
        }

        // Otherwise:
        // "Search that subtree somewhere in the left OR somewhere in the right"
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }


    // Function 2 → checks if 2 trees are IDENTICAL from given nodes
    bool sameTree(TreeNode* root, TreeNode* subRoot) {

        // ✅ If both trees end together → identical
        if (!root && !subRoot) {
            return true;
        }

        // 🔎 If both nodes exist AND have equal values → check children
        if (root && subRoot && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) &&  // Left must match
                   sameTree(root->right, subRoot->right);   // Right must also match
        }

        // ❌ All other conditions = mismatch
        return false;
    }
};
