class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i+fl<=n;i++) {
            int s1=0;
            for(int j=i;j<i+fl;j++) s1+=nums[j];

            int s2=0;

            for(int k=0;k+sl<=i;k++) {
                int s=0;
                for(int j=k;j<k+sl;j++) s+=nums[j];
                s2=max(s2,s);
            }

            for(int k=i+fl;k+sl<=n;k++) {
                int s=0;
                for(int j=k;j<k+sl;j++) s+=nums[j];
                s2=max(s2,s);
            }

            ans=max(ans,s1+s2);
        }

        return ans;
    }
};