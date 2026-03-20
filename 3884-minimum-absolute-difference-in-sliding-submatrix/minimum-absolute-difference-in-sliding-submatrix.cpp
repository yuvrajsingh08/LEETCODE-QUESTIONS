class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int x = n - k + 1;
        int y = m - k + 1;

        vector<vector<int>> ans(x, vector<int>(y));

        for(int i=0; i < x; i++) {
            for(int j=0; j<y; j++) {
                // now you got the subarray
                vector<int> temp;
                for(int a = i; a < i+k; a++) {
                    for(int b = j; b < j+k; b++) {
                        temp.push_back(grid[a][b]);
                        // cout<<grid[a][b]<<" ";
                    }
                    // cout<<endl;
                }

                sort(temp.begin(), temp.end());
                if(temp.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int curr = INT_MAX;
                    for(int ind = 1; ind < temp.size(); ind ++) {
                        if(temp[ind] == temp[ind-1]) continue;
                        curr = min(curr, temp[ind] - temp[ind-1]);
                    }
                    if(curr == INT_MAX) curr = 0;
                    ans[i][j] = curr;
                }
                //  cout<<ans[i][j]<<endl;
            
            }
            // cout<<" ---- "<<endl;  
        }
        return ans;
    }
};