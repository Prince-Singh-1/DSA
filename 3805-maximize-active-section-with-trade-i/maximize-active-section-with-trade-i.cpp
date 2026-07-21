class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one = 0;
        for (char c : s)
            if (c == '1')
                one++;

        string t = "1" + s + "1";
        int n = t.size(), ans = one;

        int i = 0;
        while (i < n) {
            if (t[i] == '0') {
                i++;
                continue;
            }

            int j = i;
            while (j + 1 < n && t[j + 1] == '1')
                j++;

            if (i > 0 && j < n - 1 && t[i - 1] == '0' && t[j + 1] == '0') {
                int l = i - 1;
                while (l >= 0 && t[l] == '0')
                    l--;
                int lf = i - 1 - l;

                int r = j + 1;
                while (r < n && t[r] == '0')
                    r++;
                int rg = r - (j + 1);

                ans = max(ans, one + lf + rg);
            }

            i = j + 1;
        }

        return ans;
    }
};