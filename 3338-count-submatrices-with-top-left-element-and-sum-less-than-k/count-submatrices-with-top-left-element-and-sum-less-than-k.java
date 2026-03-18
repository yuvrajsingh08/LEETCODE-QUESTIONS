class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] pref = grid;

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
                if(pref[i][j] <= k) cnt++;
            } 
        }
        return cnt;
    }
}