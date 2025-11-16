class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // Continue evaluating until only one final result remains
        while (tokens.size() > 1) {

            // Scan tokens from left to right to find the first operator
            for (int i = 0; i < tokens.size(); i++) {

                // Check if the current token is an operator
                if (tokens[i] == "+" ||
                    tokens[i] == "-" ||
                    tokens[i] == "*" ||
                    tokens[i] == "/")
                {
                    // ---------------------------------------------
                    // IMPORTANT: RPN means:
                    // tokens[i-2] = LEFT operand
                    // tokens[i-1] = RIGHT operand
                    //
                    // Example: ["2","3","-"] means 2 - 3
                    // So evaluate LEFT op RIGHT
                    // ---------------------------------------------

                    int left  = stoi(tokens[i - 2]);  // left operand
                    int right = stoi(tokens[i - 1]);  // right operand

                    int result = 0;

                    // Apply the operator
                    if (tokens[i] == "+")      result = left + right;
                    else if (tokens[i] == "-") result = left - right;
                    else if (tokens[i] == "*") result = left * right;
                    else                       result = left / right;

                    // ---------------------------------------------
                    // Remove the sequence: [left, right, operator]
                    //
                    // erase(from, to) removes:
                    //     tokens[from] ... tokens[to-1]
                    //
                    // So erase(i-2 ... i) correctly deletes all 3.
                    // ---------------------------------------------
                    tokens.erase(tokens.begin() + (i - 2),
                                 tokens.begin() + (i + 1));

                    // Insert the computed result where the left operand was
                    tokens.insert(tokens.begin() + (i - 2),
                                  to_string(result));

                    // Break because vector has changed — restart the loop
                    break;
                }
            }
        }

        // Remaining token is the final answer
        return stoi(tokens[0]);
    }
};
