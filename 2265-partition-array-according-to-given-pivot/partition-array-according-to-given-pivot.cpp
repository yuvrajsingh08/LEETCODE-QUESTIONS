class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> eq;
        vector<int> great;
        for(auto &c: nums) {
            if(c < pivot) {
                less.push_back(c);
            } else if(c == pivot) {
                eq.push_back(c);
            } else {
                great.push_back(c);
            }
        }
        vector<int> ans;
        for(auto &c: less) {
            ans.push_back(c);
        }
        for(auto &c: eq) {
            ans.push_back(c);
        }
        for(auto &c: great) {
            ans.push_back(c);
        }

        return ans;
    }
};