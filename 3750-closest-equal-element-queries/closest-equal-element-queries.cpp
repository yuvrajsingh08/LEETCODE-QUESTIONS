class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int> > mp;
        unordered_map<int,int> indexing;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
            indexing[i] = mp[nums[i]].size()-1;
        }
        int n =  nums.size();
        vector<int> ans;
        for(auto q: queries) {
            int ind = q;
            // check wethere it is present or not
            if(!mp.count(nums[ind])) {
                ans.push_back(-1);
                continue;
            }
            vector<int>& a = mp[nums[ind]];
            if(a.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            // int s = 0;
            // int e = a.size() - 1;
            // int curr = -1;
            // while(s <= e) {
            //     int m = (s+e)/2;
            //     if(a[m] == ind) {
            //         curr = m;
            //         break;
            //     } else if (a[m] > ind) {
            //         e = m-1;
            //     } else {
            //         s = m+1;
            //     }
            // }
            int curr = indexing[ind];
            int temp = n;
            int x = a.size();
            temp = min(temp,min(abs(a[(curr+1)%x] - a[curr]), n - abs(a[(curr+1)%x] - a[curr])));
            temp = min(temp,min(abs(a[curr] - a[(curr-1+x)%x]), n - abs(a[curr] - a[(curr-1+x)%x])));
            ans.push_back(temp);
        }
        return ans;
    }
};