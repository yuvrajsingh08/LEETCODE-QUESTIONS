class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        int j=1;
        int curr = nums[0];
        int ans = 1;
        while(j<n) {
            while(i<j && 1LL*(nums[j] - curr)*(j-i) > k*1LL) {
                k += (curr - nums[i]);
                i++;
            }
            k -= (nums[j] - curr)*(j-i);
            ans = max(ans, j-i+1);
            curr = nums[j];
            j++;
        }
        return ans;
    }
};