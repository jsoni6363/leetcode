/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    /**
     * =========================================================
     * SERIALIZE
     * =========================================================
     * Converts a binary tree into ONE string.
     *
     * Idea:
     * - Traverse the tree using preorder DFS (root → left → right)
     * - Store values as strings
     * - Store "N" for NULL nodes
     * - Join everything using commas
     */
    string serialize(TreeNode* root) {

        // This vector will store all node values + "N" for nulls
        vector<string> result;

        // Perform preorder DFS and fill 'result'
        dfsSerialize(root, result);

        // Join all elements into one comma-separated string
        // Example:
        // ["1","2","N","N","3"] → "1,2,N,N,3"
        return join(result, ",");
    }

    /**
     * =========================================================
     * DESERIALIZE
     * =========================================================
     * Converts the serialized string back into the SAME tree.
     *
     * Idea:
     * - Split the string by commas
     * - Use DFS to rebuild tree in preorder
     * - Use an index to track where we are in the list
     */
    TreeNode* deserialize(string data) {

        // Split the string into individual values
        // Example:
        // "1,2,N,N,3" → ["1","2","N","N","3"]
        vector<string> values = split(data, ',');

        // This index moves forward as we rebuild the tree
        int index = 0;

        // Rebuild the tree using DFS
        return dfsDeserialize(values, index);
    }

private:

    /**
     * =========================================================
     * DFS SERIALIZATION (Preorder Traversal)
     * =========================================================
     * This function converts the tree into a list of strings.
     *
     * Rules:
     * - If node is NULL → push "N"
     * - Otherwise:
     *     1. Push node value
     *     2. Serialize left subtree
     *     3. Serialize right subtree
     */
    void dfsSerialize(TreeNode* node, vector<string>& result) {

        // Base case: if node is NULL
        if (!node) {
            // Store "N" to represent NULL
            result.push_back("N");
            return;
        }

        // Convert node value (int) to string and store it
        result.push_back(to_string(node->val));

        // Recursively serialize left child
        dfsSerialize(node->left, result);

        // Recursively serialize right child
        dfsSerialize(node->right, result);
    }

    /**
     * =========================================================
     * DFS DESERIALIZATION
     * =========================================================
     * This function rebuilds the tree from the list of values.
     *
     * 'index' is passed by reference so all recursive calls
     * move forward in the SAME list.
     */
    TreeNode* dfsDeserialize(vector<string>& values, int& index) {

        // If current value is "N", this represents a NULL node
        if (values[index] == "N") {
            index++;        // Move to next value
            return NULL;
        }

        // Convert string to integer and create new node
        TreeNode* node = new TreeNode(stoi(values[index]));
        index++;            // Move index forward

        // Recursively rebuild left subtree
        node->left = dfsDeserialize(values, index);

        // Recursively rebuild right subtree
        node->right = dfsDeserialize(values, index);

        // Return the constructed node
        return node;
    }

    /**
     * =========================================================
     * SPLIT FUNCTION
     * =========================================================
     * Purpose:
     * Break ONE long string into MANY smaller strings
     * using a delimiter.
     *
     * Example:
     * s = "1,2,N,N,3"
     * delim = ','
     *
     * Output:
     * ["1", "2", "N", "N", "3"]
     */
    vector<string> split(const string &s, char delim) {

        // This vector will store split parts
        vector<string> elems;

        // Treat the string like a readable stream
        stringstream ss(s);

        // Temporary variable to store each extracted piece
        string item;

        /**
         * getline():
         * - Reads characters from 'ss'
         * - Stops when it finds 'delim'
         * - Stores the read part into 'item'
         */
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }

        return elems;
    }

    /**
     * =========================================================
     * JOIN FUNCTION
     * =========================================================
     * Purpose:
     * Combine MANY strings into ONE string using a delimiter.
     *
     * Example:
     * v = ["1","2","N","N","3"]
     * delim = ","
     *
     * Output:
     * "1,2,N,N,3"
     */
    string join(const vector<string> &v, const string &delim) {

        // Used to build strings efficiently
        ostringstream ss;

        for (int i = 0; i < v.size(); i++) {

            // Add delimiter before every element except the first
            if (i > 0)
                ss << delim;

            // Add current value
            ss << v[i];
        }

        // Convert stream to string and return
        return ss.str();
    }
};
