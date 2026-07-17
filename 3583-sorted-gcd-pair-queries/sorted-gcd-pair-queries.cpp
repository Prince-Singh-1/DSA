class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1);
        for (int x : nums)
            cnt[x]++;

        vector<long long> div(mx + 1);

        for (int g = 1; g <= mx; g++)
            for (int j = g; j <= mx; j += g)
                div[g] += cnt[j];

        vector<long long> exact(mx + 1);

        for (int g = mx; g >= 1; g--) {
            exact[g] = div[g] * (div[g] - 1) / 2;
            for (int j = g + g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        vector<long long> pre(mx + 1);
        for (int i = 1; i <= mx; i++)
            pre[i] = pre[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pre.begin() + 1, pre.end(), q + 1) - pre.begin();
            ans.push_back(g);
        }

        return ans;
    }
};