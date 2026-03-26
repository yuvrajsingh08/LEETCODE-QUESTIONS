class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        s.insert(nums.begin(), nums.end());
        int unique = 0;
        for(int l=0,r=0; l<n; l++) {
            while(unique < s.size() && r<n) {
                mp[nums[r]]++;
                if(mp[nums[r]] == 1)
                    unique++;
                r++;
            }
            if(unique == s.size())
                ans += (n-r+1);
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) unique--;
        }
        return ans;
    }
    
};