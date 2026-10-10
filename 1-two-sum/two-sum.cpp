class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int,int> mp;
        int i=-1,j=-1;
        for(int k=0;k<a.size();k++) {
            if(mp.count(target-a[k])) {
                i=mp[target-a[k]];
                j=k;
                break;
            }
            mp[a[k]]=k;
        }
        return {i,j};
    }
};