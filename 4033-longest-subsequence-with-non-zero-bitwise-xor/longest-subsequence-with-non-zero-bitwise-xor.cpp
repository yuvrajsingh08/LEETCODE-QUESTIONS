class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool isZero = true;
        for(auto c: nums) {
            ans ^= c;
            if(c != 0) isZero = false;
        }
        if(isZero) return 0;
        return ans == 0 ? n-1: n;
    }
};