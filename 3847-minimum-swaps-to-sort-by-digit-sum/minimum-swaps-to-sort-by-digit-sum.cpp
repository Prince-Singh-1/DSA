class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (auto x : nums) {
            int s = 0;
            int y = x;
            while (x > 0) {
                s += (x % 10);
                x /= 10;
            }
            arr.push_back({s, y});
        }
        
        auto comp = [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };
        sort(arr.begin(), arr.end(), comp);
        
        unordered_map<int, int> mp;
        int c = 0;
        for (auto x : arr) {
            mp[x.second] = c++;
        }
            
        int n = arr.size();
        vector<int> vis(n, 0);
        int ans = 0;
        
        // FIXED LOGIC: Detect cycles of any length
        for (int i = 0; i < n; i++) {
            // Skip if already visited or in the correct position
            if (vis[i] || mp[nums[i]] == i)
                continue;
            
            int cycle_size = 0;
            int j = i;
            
            // Traverse the cycle
            while (!vis[j]) {
                vis[j] = 1;
                j = mp[nums[j]];
                cycle_size++;
            }
            
            // A cycle of size L takes L - 1 swaps to resolve
            if (cycle_size > 1) {
                ans += (cycle_size - 1);
            }
        }
        
        return ans;
    }
};