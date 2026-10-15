class Solution {
public:
    typedef long long ll;

    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;

        vector<ll> mp(26, 0);

        for(char c : s)
            mp[c - 'a']++;

        while(t--) {
            vector<ll> nm(26, 0);

            for(int i = 0; i < 25; i++)
                nm[i + 1] = mp[i];

            nm[0] = mp[25];
            nm[1] = (nm[1] + mp[25]) % mod;

            mp = nm;
        }

        ll ans = 0;

        for(int i = 0; i < 26; i++)
            ans = (ans + mp[i]) % mod;

        return ans;
    }
};