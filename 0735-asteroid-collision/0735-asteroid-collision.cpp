class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;  // stack to store surviving asteroids

        for (int a : asteroids) {

            // Case: a might collide only when a < 0 and st.back() > 0
            while (!st.empty() && a < 0 && st.back() > 0) {

                int right = st.back();   // last asteroid (moving right)
                int left = -a;           // abs value of left-moving asteroid

                // The right asteroid is smaller → destroy right one
                if (right < left) {
                    st.pop_back();
                    // continue checking because new asteroid may hit more
                }

                // The right asteroid is bigger → destroy new asteroid
                else if (right > left) {
                    a = 0; // new asteroid dies
                }

                // Both equal → destroy both
                else { // right == left
                    st.pop_back();  // remove right asteroid
                    a = 0;          // new asteroid also dies
                }

                // if new asteroid dies → stop checking
                if (a == 0) break;
            }

            // If asteroid still survives after all collisions → push it
            if (a != 0) st.push_back(a);
        }

        return st; // survivors
    }
};
