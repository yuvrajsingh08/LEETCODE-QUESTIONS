class Solution {
public:
    int solveUsingRec(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n) {
        if(i>=m || j>=n || i<0 || j<0 || obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1)  return 1;
               
        int ans = 0;
        ans += (solveUsingRec(obstacleGrid,i+1,j,m,n)+solveUsingRec(obstacleGrid,i,j+1,m,n));
        return ans;
    }
    int solveUsingMem(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>&dp) {
        if(i>=m || j>=n || i<0 || j<0 || obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1)  return 1;

        if(dp[i][j] != -1) return dp[i][j];      
        int ans = 0;
        ans += (solveUsingMem(obstacleGrid,i+1,j,m,n,dp)+solveUsingMem(obstacleGrid,i,j+1,m,n,dp));
        return dp[i][j]=ans;
    }

    int solveUsingTab(vector<vector<int>>& obstacleGrid,int m,int n) {
         vector<vector<int>>dp (m+2,vector<int>(n+2,0));
         dp[m-1][n-1] = 1;
         for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i == m-1 && j == n-1) continue;
                if(obstacleGrid[i][j]) continue;
                int ans = 0;
                ans += (dp[i+1][j]+dp[i][j+1]);
                dp[i][j] = ans;
            }
         }
         return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // return solveUsingRec(obstacleGrid,0,0,m,n);

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveUsingMem(obstacleGrid,0,0,m,n,dp);
        return solveUsingTab(obstacleGrid,m,n);
    }
};