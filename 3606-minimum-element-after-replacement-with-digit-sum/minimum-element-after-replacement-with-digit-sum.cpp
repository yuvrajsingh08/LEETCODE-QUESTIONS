class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto num: nums) {
            string s = to_string(num);
            int val = 0;
            for(auto c: s) {
                val += (c - '0');
            }
            mini = min(mini, val);
        }
        return mini;
    }
};