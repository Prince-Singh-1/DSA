class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lst(26), vis(26);

        for (int i = 0; i < s.size(); i++)
            lst[s[i] - 'a'] = i;

        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (vis[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   lst[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = 1;
        }

        return st;
    }
};