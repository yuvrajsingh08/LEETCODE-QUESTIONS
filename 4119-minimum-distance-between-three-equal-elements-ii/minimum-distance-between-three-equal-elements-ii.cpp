class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto c: mp) {
            int x = c.first;
            // for(auto b: c.second) cout<<b<<" ";
            // cout<<endl;
            if(c.second.size() >= 3) {
                vector<int> a = c.second;
                
                int val = abs(a[1] - a[0]) + abs(a[2] - a[1]) + abs(a[2] - a[0]);
                // cout<<val<<" "<<c.second.size()<<" | "<<a.size();
                ans = min(val, ans);
                for(int i=3; i<a.size(); i++) {
                    val -= abs(a[i-3] - a[i-2]);
                    val -= abs(a[i-3] - a[i-1]);
                    val += abs(a[i] - a[i-1]);
                    val += abs(a[i] - a[i-2]);
                    ans = min(ans, val);
                }
                // cout<<val<<" ";
                
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};