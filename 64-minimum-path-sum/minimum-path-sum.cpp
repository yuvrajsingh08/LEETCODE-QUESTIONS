class Solution {
public:
    int solveUsingRecursion(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp) {
        if(i>=grid.size() || j>=grid[0].size()) return 10000000;
        if(i == grid.size()-1 && j == grid[0].size()-1 ) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        long long down = grid[i][j]+ solveUsingRecursion(grid,i,j+1,dp);
        long long up = grid[i][j]+ solveUsingRecursion(grid,i+1,j,dp);
        // cout<<i<<" "<<j<<" "<<" up "<<up<<" down "<<down<<" "<<endl;
        return dp[i][j] = min(up,down);
    }
    int solveUsingTab(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,10000000));
        dp[grid.size()-1][grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1];
        int m = grid.size();
        int n = grid[0].size();
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i == m-1 && j == n-1) continue;
                long long down = grid[i][j]+ dp[i][j+1];
                long long up = grid[i][j]+ dp[i+1][j];
                dp[i][j] = min(up,down);
            }
        }
        return dp[0][0];
    }
    int solveUsingTabSO(vector<vector<int>>& grid) {
        vector<int> next(grid[0].size()+1,10000000);
        // next[grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1]; why not working as n-1 & m-1 also in lloop
        int m = grid.size();
        int n = grid[0].size();
        for(int i=m-1; i>=0; i--) {
            vector<int> curr(grid[0].size()+1,10000000);
            for(int j=n-1; j>=0; j--) {
                 if (i == m - 1 && j == n - 1) {
                curr[j] = grid[i][j];
                continue;
            }
                long long down = grid[i][j]+ curr[j+1];
                long long up = grid[i][j]+ next[j];
                curr[j] = min(up,down);
            }
            next = curr;
        }
        return next[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        // vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return solveUsingTabSO(grid);
        // return solveUsingRecursion(grid, 0,0,dp);
    }
};