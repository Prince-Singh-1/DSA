class Solution {
public:

    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n,false));

        for(int center=0; center<n; center++){

            int l=center, r=center;
            while(l>=0 && r<n && s[l]==s[r]){
                pal[l][r] = true;
                l--; r++;
            }

            l=center; r=center+1;
            while(l>=0 && r<n && s[l]==s[r]){
                pal[l][r] = true;
                l--; r++;
            }
        }

        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){

            dp[i] = dp[i+1];

            if(i+k-1 < n && pal[i][i+k-1])
                dp[i] = max(dp[i], 1 + dp[i+k]);

            if(i+k < n && pal[i][i+k])
                dp[i] = max(dp[i], 1 + dp[i+k+1]);
        }

        return dp[0];
    }
};