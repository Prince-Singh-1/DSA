class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;

        for(int x:st) {
            if(!st.count(x-1)) {
                int y=x;
                while(st.count(y))
                    y++;
                ans=max(ans,y-x);
            }
        }

        return ans;
    }
};