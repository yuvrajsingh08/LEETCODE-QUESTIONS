class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int cntZero = 0;
        int ans = 0;
        while(j<n) {
            if(nums[j] == 0) cntZero++;

            if(i<=j && cntZero > k) {
                if(nums[i] == 0) cntZero--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};