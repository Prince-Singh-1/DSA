class Solution {
public:
    bool check(vector<int>& a, int k) {
        int n = a.size();
        int pm = -1;

        for(int s = 0; s < n; s += k) {
            int mn = a[s];
            int mx = a[s];
            int dc = 0;

            for(int i = s; i < s + k; i++) {
                int j = (i + 1 == s + k ? s : i + 1);

                if(a[i] > a[j])
                    dc++;

                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }

            // block cannot become sorted by rotation
            if(dc > 1)
                return false;

            // previous block must end <= current block
            if(pm != -1 && pm > mn)
                return false;

            pm = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k == 0 && check(nums, k))
                ans += k;
        }

        return ans;
    }
};