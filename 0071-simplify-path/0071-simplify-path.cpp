class Solution {
public:
    string simplifyPath(string path) {

        // Stack to store valid directory names
        vector<string> stack;

        // Temporary string to build the current token
        string cur = "";

        // Add an extra '/' to ensure the last token gets processed
        for (char c : path + "/") {

            // When we see a slash, we have reached the end of a token
            if (c == '/') {

                // Case 1: cur == ".." → go to parent directory
                if (cur == "..") {
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                }

                // Case 2: cur is a valid directory name
                // Ignore:
                //   - empty string ""  → happens with "//"
                //   - "."              → current directory
                else if (!cur.empty() && cur != ".") {
                    stack.push_back(cur);
                }

                // Clear cur to start building the next token
                cur.clear();
            }

            // If it's not a slash, add to current token
            else {
                cur += c;
            }
        }

        // Build the final simplified path
        string result = "/";

        for (int i = 0; i < stack.size(); i++) {
            if (i > 0) result += "/";
            result += stack[i];
        }

        return result;
    }
};
