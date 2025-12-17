class Codec {
public:

    /**
     * =====================================================
     * SERIALIZATION (BFS / LEVEL ORDER)
     * =====================================================
     * Converts a binary tree into a string using level order.
     */
    string serialize(TreeNode* root) {

        // If tree is empty, return just "N"
        if (!root) return "N";

        // This string will store the serialized result
        string res;

        // Queue for BFS traversal
        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);

        // Process nodes level by level
        while (!q.empty()) {

            // Take the front node
            TreeNode* node = q.front();
            q.pop();

            // If node is NULL, record "N"
            if (!node) {
                res += "N,";
            }
            else {
                // Store current node value
                res += to_string(node->val) + ",";

                // Push left and right children
                // (even if they are NULL)
                q.push(node->left);
                q.push(node->right);
            }
        }

        // Return final serialized string
        return res;
    }

    /**
     * =====================================================
     * DESERIALIZATION (BFS / LEVEL ORDER)
     * =====================================================
     * Rebuilds the binary tree from the serialized string.
     */
    TreeNode* deserialize(string data) {

        // Use stringstream to read comma-separated values
        stringstream ss(data);
        string val;

        // Read the first value (root)
        getline(ss, val, ',');

        // If root is NULL
        if (val == "N") return nullptr;

        // Create root node
        TreeNode* root = new TreeNode(stoi(val));

        // Queue to rebuild tree level by level
        queue<TreeNode*> q;
        q.push(root);

        // Process remaining values
        while (!q.empty()) {

            // Get the current parent node
            TreeNode* node = q.front();
            q.pop();

            // Read LEFT child value
            if (!getline(ss, val, ',')) break;
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Read RIGHT child value
            if (!getline(ss, val, ',')) break;
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};
