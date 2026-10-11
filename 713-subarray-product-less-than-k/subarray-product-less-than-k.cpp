class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int l = 0;
        long long pr = 1;
        int ans = 0;

        for(int r = 0; r < n; r++) {
            pr *= a[r];

            while(l <= r && pr >= k) {
                pr /= a[l];
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};