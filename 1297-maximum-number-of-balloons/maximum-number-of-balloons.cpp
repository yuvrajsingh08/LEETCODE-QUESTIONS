class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> mp;
        for(auto c: text) {
            mp[c]++;
        }
        string temp = "balloon";
        int ans = INT_MAX;
        for(auto c: temp) {
            if(c == 'l' || c == 'o')
             ans = min(ans, mp[c]/2);
            else ans = min(ans, mp[c]);
        }
        return ans;
    }
};