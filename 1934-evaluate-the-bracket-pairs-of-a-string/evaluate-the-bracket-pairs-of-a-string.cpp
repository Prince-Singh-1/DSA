class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;

        for (auto &x : knowledge)
            mp[x[0]] = x[1];

        string ans;

        for (int i = 0; i < s.size();) {
            if (s[i] != '(') {
                ans += s[i++];
                continue;
            }

            int j = i + 1;
            string key;

            while (s[j] != ')')
                key += s[j++];

            if (mp.count(key))
                ans += mp[key];
            else
                ans += "?";

            i = j + 1;
        }

        return ans;
    }
};