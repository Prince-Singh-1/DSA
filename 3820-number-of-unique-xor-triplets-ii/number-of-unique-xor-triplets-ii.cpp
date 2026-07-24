class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;
        vector<vector<int>> dp(4, vector<int>(M, 0));

        dp[0][0] = 1;

        for (int x : nums) {
            for (int k = 2; k >= 0; k--) {
                for (int v = 0; v < M; v++) {
                    if (dp[k][v])
                        dp[k + 1][v ^ x] = 1;
                }
            }
        }

        int ans = 0;
        for (int v = 0; v < M; v++)
            if (dp[1][v] || dp[3][v])
                ans++;

        return ans;
    }
};