class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> l(26, n);
        vector<int> r(26, -1);

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            l[x] = min(l[x], i);
            r[x] = i;
        }

        vector<pair<int, int>> v;

        for (int c = 0; c < 26; c++) {
            if (r[c] == -1)
                continue;

            int le = l[c];
            int ri = r[c];
            bool ok = true;

            for (int i = le; i <= ri; i++) {
                int x = s[i] - 'a';

                if (l[x] < le) {
                    ok = false;
                    break;
                }

                ri = max(ri, r[x]);
            }

            if (ok)
                v.push_back({ri, le});
        }

        sort(v.begin(), v.end());

        vector<string> ans;
        int pre = -1;

        for (auto [ri, le] : v) {
            if (le <= pre)
                continue;

            ans.push_back(s.substr(le, ri - le + 1));
            pre = ri;
        }

        return ans;
    }
};