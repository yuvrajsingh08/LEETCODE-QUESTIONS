class Solution {
public:
    int solve(vector<int> curr) {
        vector<int> a(11,0);
        for(auto c: curr) {
            a[c] = 1;
        }
        int ans = 2;
        for(int i=2; i<=5; i++) {
            if(a[i] == 1) {
                // means booked
                ans -= 1;
                break;
            }
        }
        for(int i=6; i<=9; i++) {
            if(a[i] == 1) {
                // means booked
                ans -= 1;
                break;
            }
        }
        if(ans == 0) {
            // check for 
            for(int i=4; i<=7; i++) {
                if(a[i] == 1) {
                    // means booked
                    return 0;
                }
            }
            ans = 1;
        }
        return ans;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(auto c: reservedSeats) {
            mp[c[0]].push_back(c[1]);
        }
        int ans = 0;
        for(auto row: mp) {
            // int curr = row.first;
            vector<int> curr = row.second;
            ans += solve(curr);
        }
        int x = mp.size();
        ans += (n-x)*2;
        return ans;
    }
};