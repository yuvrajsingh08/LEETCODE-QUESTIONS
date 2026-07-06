class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> curr = intervals[0];
        int ans = intervals.size();
        for(int i=1; i<intervals.size(); i++) {
            if(curr[0] <= intervals[i][0] && curr[1] >= intervals[i][1]) {
                // it comes under
                ans -= 1;
            } else {
                curr = intervals[i];
            }
        }
        return ans;
    }
};