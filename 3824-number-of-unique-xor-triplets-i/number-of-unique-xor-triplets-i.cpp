class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)
            return n;

        int x = 1;
        while(x <= n)
            x <<= 1;

        return x;
    }
};