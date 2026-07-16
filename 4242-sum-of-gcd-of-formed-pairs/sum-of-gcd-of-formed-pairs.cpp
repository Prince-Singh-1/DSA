class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       int mx = nums[0];
        vector<int>lily(nums.size());
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i],mx);
            lily[i]=gcd(nums[i],mx);
        }
        int i=0,j=nums.size()-1;
        long long p=0;
        sort(lily.begin(),lily.end());
        while(i<j){
            p+=gcd(lily[i],lily[j]);
            i++;j--;
        }
        return p;
    }
};