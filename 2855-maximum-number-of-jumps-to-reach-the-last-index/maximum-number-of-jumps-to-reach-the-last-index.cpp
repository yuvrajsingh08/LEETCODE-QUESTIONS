class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        function<int(int)> dfs = [&](int i){
            if (i == n - 1) {
                return 0;
            }
            if (dp[i] != INT_MIN) {
                return dp[i];
            }
            int res = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    res = max(res, dfs(j) + 1);
                }
            }
            return dp[i] = res;
        };

        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};