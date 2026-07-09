class Solution {
public:
    unordered_map<int,int> parent;
    int doMapping(int n, vector<int>& nums, int maxDiff, int curr) {
        if(curr == n-1 || nums[curr+1] - nums[curr] > maxDiff){
            parent[curr] = curr;
            if(curr != n-1) {
                doMapping(n,nums,maxDiff,curr+1);
            }
            return curr; 
        } 
        return parent[curr] = doMapping(n,nums,maxDiff, curr+1);
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        doMapping(n,nums,maxDiff,0);
        vector<bool> ans;
        for(auto c: queries) {
            int u = c[0];
            int v = c[1];
            ans.push_back(parent[u] == parent[v]);
        }
        return ans;
    }
};