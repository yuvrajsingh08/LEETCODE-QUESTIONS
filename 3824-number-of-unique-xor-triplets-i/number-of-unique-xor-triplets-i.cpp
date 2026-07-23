class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int i = 23;
        while(i >= 0 && ((maxi >> i) & 1) == 0) {
            i--;
        }
        int val = i+1;
        return 1 << val;
    }
};