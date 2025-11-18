#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<int> numberStack;      // stores repeat numbers
        stack<string> stringStack;   // stores previous strings

        string current = "";         // current decoded substring
        int number = 0;              // current number being built

        for (char c : s) {

            // If digit → build the full number
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            }
            // When we see '[', push number and current string into stacks
            else if (c == '[') {
                numberStack.push(number);  // save the repeat count
                stringStack.push(current); // save the string built till now

                number = 0;                // reset for next part
                current = "";              // start a fresh string
            }
            // When we see ']', we must repeat the current string
            else if (c == ']') {
                // how many times to repeat
                int repeat = numberStack.top();
                numberStack.pop();
                // previous string
                string prev = stringStack.top();
                stringStack.pop();

                string repeated = "";
                for (int i = 0; i < repeat; i++) {
                    repeated += current;             // repeat current substring
                }

                current = prev + repeated;            // attach to previous
            }
            // Normal characters → add to current string
            else {
                current += c;
            }
        }

        return current;
    }
};
