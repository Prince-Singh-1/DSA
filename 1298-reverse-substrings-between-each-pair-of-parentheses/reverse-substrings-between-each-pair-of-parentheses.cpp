class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;

        for (char c : s) {
            if (c == ')') {
                vector<char> t;

                while (st.back() != '(') {
                    t.push_back(st.back());
                    st.pop_back();
                }

                st.pop_back();

                for (char x : t)
                    st.push_back(x);
            }
            else {
                st.push_back(c);
            }
        }

        return string(st.begin(), st.end());
    }
};