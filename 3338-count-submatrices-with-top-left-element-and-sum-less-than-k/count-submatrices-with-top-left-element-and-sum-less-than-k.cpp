class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref = grid;

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                pref[i][j] += pref[i-1][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                pref[i][j] += pref[i][j-1];
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // cout<<pref[i][j]<<" ";
                if(pref[i][j] <= k) cnt++;
            } cout<<endl;
        }
        return cnt;
    }
};