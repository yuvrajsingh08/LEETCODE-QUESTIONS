class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxVal = 0;
        int currStep = 0;
        int newMax = maxVal;
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            newMax = max(newMax, nums[i]+i);
            if(i == maxVal) {
                // means you have crossed the limit
                currStep++;
                maxVal = newMax;
            }
        }
        return currStep;
    }
};