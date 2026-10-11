class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
         int ans = 0;

        for(int x : a)
            ans ^= x;

        return ans;
    }
};