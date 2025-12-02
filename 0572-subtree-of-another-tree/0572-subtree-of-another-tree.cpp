class Solution {
public:

    // 🌿 Converts tree into a string
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "$#";  // "$#" means there is NO node here
        }

        // "$" marks start of a node, then write node value
        // Then serialize left tree, then right, and join all
        return "$" + to_string(root->val) +
                serialize(root->left) +   // Convert left subtree to string
                serialize(root->right);   // Convert right subtree to string
    }


    // 🔍 Helps find substring matching from each position
    vector<int> z_function(string s) {
        int n = s.length();
        vector<int> z(n); // z[i] will store match length from index i with start of string
        int l = 0, r = 0; // current matching window

        for (int i = 1; i < n; i++) {

            // If i lies inside the current matching window
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
                // We reuse previous match info so we don’t compare again unnecessarily
            }

            // Try to extend matching character by character
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++; // increase match length
            }

            // If we extended beyond r, update window
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }



    // 🌳 Main subtree check using string pattern matching
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        string serialized_root = serialize(root);         // big tree string
        string serialized_subRoot = serialize(subRoot);   // small tree string

        string combined = serialized_subRoot + "|" + serialized_root;
        // "|" is just a separator so strings stay separate

        vector<int> z_values = z_function(combined); // get matching lengths

        int sub_len = serialized_subRoot.length(); // length of small tree string

        // Start from subtree end +1 to skip its own Z-values
        for (int i = sub_len + 1; i < combined.length(); i++) {
            if (z_values[i] == sub_len) {
                return true; // ✅ Found exact match of subtree inside root
            }
        }

        return false; // ❌ No match found
    }
};
