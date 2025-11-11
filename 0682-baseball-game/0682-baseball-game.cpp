class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;     // stack to store all valid scores
        int res = 0;       // running total of scores

        for (int i = 0; i < ops.size(); i++) {
            string op = ops[i];

            // Case 1: "+"
            // Add a score equal to the sum of last two scores
            if (op == "+") {
                int last = st.top(); 
                st.pop();                    // temporarily remove last score
                int newScore = last + st.top();  // add last two
                st.push(last);               // push removed back
                st.push(newScore);           // add new calculated score
                res += newScore;             // update running total
            }

            // Case 2: "D"
            // Add double the previous score
            else if (op == "D") {
                int newScore = 2 * st.top();
                st.push(newScore);
                res += newScore;             // update running total
            }

            // Case 3: "C"
            // Remove last score
            else if (op == "C") {
                res -= st.top();             // subtract removed score
                st.pop();                    // remove it
            }

            // Case 4: Integer value
            else {
                int value = stoi(op);        // convert string to integer
                st.push(value);
                res += value;                // add to total
            }
        }

        return res;  // final total score
    }
};
