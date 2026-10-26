class Solution {
public:
    int solveUsingBFS(vector<vector<int>>& grid, vector<vector<int>> &vis, int indX, int indY, int rem) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        queue<pair<int,int>> q;
        q.push({indX, indY});
        vis[indX][indY] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto [tempX,tempY] = q.front(); q.pop();
            sum += grid[tempX][tempY]%rem;
            for (int k = 0; k < 4; k++) {
                int newX = tempX + dx[k];
                int newY = tempY + dy[k];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != 0 && vis[newX][newY] == 0) {
                    // cout<<newX<<" | "<<newY<<endl;
                    q.push({newX, newY});
                    vis[newX][newY] = 1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == 0 && grid[i][j] != 0) {
                    if(solveUsingBFS(grid,vis, i, j, k)%k == 0) ans++;
                }
            }
        }
        return ans;
    }
};