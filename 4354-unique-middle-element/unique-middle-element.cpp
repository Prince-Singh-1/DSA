class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int x = nums[nums.size() / 2];
        int cnt = 0;

        for (int v : nums)
            if (v == x)
                cnt++;

        return cnt == 1;
    }
};