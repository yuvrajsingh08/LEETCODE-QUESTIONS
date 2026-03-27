class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        unordered_map<int, long long> minPrefix;
        long long ans = LLONG_MIN;

        // Initialize remainder 0
        minPrefix[0] = prefix[0];

        for (int i = 1; i <= n; i++) {
            int rem = i % k;

            if (minPrefix.count(rem)) {
                ans = max(ans, prefix[i] - minPrefix[rem]);
            }

            // store minimum prefix for remainder
            if (!minPrefix.count(rem))
                minPrefix[rem] = prefix[i];
            else
                minPrefix[rem] = min(minPrefix[rem], prefix[i]);
        }

        return ans;
    }
};
