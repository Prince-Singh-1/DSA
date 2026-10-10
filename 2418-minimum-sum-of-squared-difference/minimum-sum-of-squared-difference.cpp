class Solution {
public:
    typedef long long ll;

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;

        vector<ll> cnt(100001,0);
        int mx=0;

        for(int i=0;i<n;i++) {
            int d=abs(nums1[i]-nums2[i]);
            cnt[d]++;
            mx=max(mx,d);
        }

        for(int d=mx;d>0 && k>0;d--) {
            ll x=min(cnt[d],(ll)k);

            cnt[d]-=x;
            cnt[d-1]+=x;
            k-=x;
        }

        ll ans=0;

        for(int d=1;d<=mx;d++)
            ans+=cnt[d]*d*d;

        return ans;
    }
};