class Solution {
public:
    string simplifyPath(string path) {

        // This vector acts like a stack to store valid folder names
        // Example: "/a/b/../c" -> stack becomes ["a", "c"]
        vector<string> stack;

        // This will temporarily store each part of the path
        // For example, cur becomes:
        // "" , "a", "", "b", "..", "c", ""
        string cur;

        // stringstream allows us to break the path using '/' as a separator
        stringstream ss(path);

        // Extract every substring between slashes '/'
        // Example: "/a//b/../c/"
        // getline → "" , "a" , "" , "b" , ".." , "c" , ""
        while (getline(ss, cur, '/')) {

            // CASE 1: Ignore empty tokens ("") and "." 
            // "" comes from '//' (multiple slashes)
            // "." means "current directory", so skip it
            if (cur == "" || cur == ".") {
                continue;
            }

            // CASE 2: ".." means "go to parent directory"
            // So remove the last stored folder from stack (if any)
            else if (cur == "..") {
                if (!stack.empty()) {
                    stack.pop_back();  // go back one folder
                }
            }

            // CASE 3: A regular folder name
            // Example: "a", "b", "folder", "_home", "...", etc.
            // Add it to the stack because it is part of the valid path
            else {
                stack.push_back(cur);
            }
        }

        // Now rebuild the final simplified path from stack contents
        // Start with root slash
        string result = "/";

        // Join all folder names with a single slash between them
        for (int i = 0; i < stack.size(); i++) {

            // Add slash before every folder except the first one
            if (i > 0) {
                result += "/";
            }

            // Add the folder name
            result += stack[i];
        }

        // Return the simplified canonical path
        // If stack is empty, result will stay "/", which is correct
        return result;
    }
};
