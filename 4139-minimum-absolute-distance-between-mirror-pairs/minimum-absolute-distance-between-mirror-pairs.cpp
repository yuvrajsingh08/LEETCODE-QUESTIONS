class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) {
            if(mp.count(nums[i])) ans = min(ans, i - mp[nums[i]]);
            string x = to_string(nums[i]);
            reverse(x.begin(), x.end());
            int mirror = stoi(x);
            mp[mirror] = i;
        }
        return ans == n ? -1 : ans;
    }
};