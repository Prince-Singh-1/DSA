#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        if (n < 3) return 0; // Impossible to have length 3
        
        // Step 1: Build a standard 0-based Prefix Sum array
        vector<long long> prefix(n);
        prefix[0] = capacity[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + capacity[i];
        }
        
        // Step 2: Map to store {Value, PrefixSum} -> Frequency
        // (We use std::map because we are hashing a pair of values)
        map<pair<long long, long long>, int> mp;
        
        long long stable_count = 0;
        
        // Step 3: Iterate through possible right boundaries 'r'
        // We start at r = 2 because length must be at least 3
        for (int r = 2; r < n; r++) {
            
            // THE SLIDING WINDOW:
            // Add the left boundary that is exactly 2 steps behind us.
            // This guarantees every 'l' in our map forms a length >= 3.
            int l = r - 2;
            mp[{capacity[l], prefix[l]}]++;
            
            // THE MATH FORMULA:
            long long target_val = capacity[r];
            long long target_prefix = prefix[r - 1] - capacity[r];
            
            // Count how many past boundaries perfectly match our requirements
            stable_count += mp[{target_val, target_prefix}];
        }
        
        return stable_count;
    }
};